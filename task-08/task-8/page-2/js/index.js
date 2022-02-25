function button1(){
    var name=prompt("Enter something");
    localStorage.setItem("username1", name);
}

function show_now() { 
    var my_time = new Date();
    alert(my_time)
    }

function chBackcolor(color) {
        document.body.style.background = color;
    }

function refreshPage(){
        window.location.reload();
    }

function openWin() {
        window.open("https://shyamdevkrishnanj.github.io/");
      }

