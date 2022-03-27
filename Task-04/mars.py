import requests,argparse,json

prsr=argparse.ArgumentParser(description="API for pictures from the rovers")
prsr.add_argument("api_key",default='Ne5QVsmj5rabNTPZwE6d7MUhE1m9lWG4l0zm07Ci', type=str, help="Your API key")
prsr.add_argument("rover_id",default= 5, type=int, help="1: Curiosity 2: Opportunity 3: Spirit")
prsr.add_argument("earth_date",default="2015-06-03", type=str, help="Date in YYYY-MM-DD")
args = prsr.parse_args()

e_date = args.earth_date
api_key = args.api_key
rov_id = args.rover_id
rov_name = ""

if rov_id == 5:
    rov_name = "curiosity"
elif rov_id == 6:
    rov_name = "opportunity"
elif rov_id == 7:
   rov_name = "spirit"    
else:
    print("invalid ID !!")

#ap=Ne5QVsmj5rabNTPZwE6d7MUhE1m9lWG4l0zm07Ci
api_url='https://api.nasa.gov/mars-photos/api/v1/rovers/{}/photos?earth_date={}&api_key={}'.format(rov_name,e_date,api_key)
print(api_url)
request = requests.get(api_url)
parsed_requests = json.loads(request.text)

img_saved=0
if 'error' in parsed_requests:
    print(parsed_requests['error'])
else:
    for photo in parsed_requests['photos']:
        if rov_id == photo['rover']['id']:
            save_flag = True
            print("Saving Image")
            photo_url = photo['img_src']
            photo_request = requests.get(photo_url)
            photo_path = open("downloaded_file_{}.png".format(img_saved+1), "wb")
            photo_path.write(photo_request.content)
            photo_path.close()            
            img_saved += 1

if not img_saved:
    print("image not found")