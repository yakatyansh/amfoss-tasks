import requests
import argparse
import json

parser=argparse.ArgumentParser(description="API for pictures from the rovers")
parser.add_argument("api_key",default='Ne5QVsmj5rabNTPZwE6d7MUhE1m9lWG4l0zm07Ci', type=str, help="Your API key")
parser.add_argument("earth_date",default="2015-06-03", type=str, help="Date in YYYY-MM-DD")
parser.add_argument("rover_id",default= 5, type=int, help="1: Curiosity 2: Opportunity 3: Spirit")
args = parser.parse_args()

earth_date = args.earth_date
api_key = args.api_key
rover_id = args.rover_id
rover_name = ""

if rover_id == 5:
    rover_name = "curiosity"
elif rover_id == 6:
    rover_name = "opportunity"
elif rover_id == 7:
   rover_name = "spirit"    
else:
    print("invalid id !!")

#ap=Ne5QVsmj5rabNTPZwE6d7MUhE1m9lWG4l0zm07Ci
api_url='https://api.nasa.gov/mars-photos/api/v1/rovers/{}/photos?earth_date={}&api_key={}'.format(rover_name,earth_date,api_key)
print(api_url)
request = requests.get(api_url)
parsed_requests = json.loads(request.text)

images_saved=0
if 'error' in parsed_requests:
    print(parsed_requests['error'])
else:
    for photo in parsed_requests['photos']:
        if rover_id == photo['rover']['id']:
            save_flag = True
            print("Saving Image")
            photo_url = photo['img_src']
            photo_request = requests.get(photo_url)
            photo_path = open(f"new_{images_saved+1}.png", "wb")
            photo_path.write(photo_request.content)
            photo_path.close()            
            images_saved += 1

if not images_saved:
    print("image not found")

    