function click_1(){
    localStorage.setItem("Hey this is Yash");
}

function click_2(){
    const date = new Date();
    var hr = date.getHours();
    var min = date.getMinutes();
    var sec = date.getSeconds();
    var time = "Time : " +hr + " : " + min + " : " + sec;
  
    alert(time);      
}

function click_3(){
    var colour_list= ["#011f4b","#03396c","#005b96","#6497b1","#b3cde0"];
    var choice = colour_list[Math.floor(Math.random()*colour_list.length)];
    document.body.style.background = choice;
    //console.log(choice);
}

function click_6(){
    for (var j=1;j<=150;j++){
        console.log("I did it !!")
    }
}