
let ctx=document.getElementById('chart').getContext('2d');
let chart=new Chart(ctx,{
type:'line',
data:{
labels:[],
datasets:[{label:'Gas Level',data:[]}]
}
});

setInterval(function(){
fetch('/data')
.then(res=>res.json())
.then(data=>{

document.getElementById("gas").innerHTML=data.gas;

chart.data.labels.push("");
chart.data.datasets[0].data.push(data.gas);

if(chart.data.labels.length>20){
chart.data.labels.shift();
chart.data.datasets[0].data.shift();
}

chart.update();
});
},1000);
