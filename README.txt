						Alay Vora – akv140030
					Read me file for the web proxy server program.

	Web Proxy Server Side of code running on net01.utdallas.edu

	Needs to pass one arguments
	1)Port Number at which proxy server will listen to the clientXX (XX-01, 02…)

	Compile -:     gcc –o server –server.c -lpthread

	Sample Output:-

	./server 2001

	Connection accepted

	Received message from the server

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>

<meta http-equiv="Content-Language" content="en-us">

<meta name="GENERATOR" content="Microsoft FrontPage 6.0">

<meta name="ProgId" content="FrontPage.Editor.Document">

<meta http-equiv="Content-Type"
content="text/html; charset=windows-1252">
<title>Kamil Sarac</title>
<style>
<!--
li.MsoNormal
{mso-style-parent:"";
margin-bottom:.0001pt;
font-size:12.0pt;
font-family:"Times New Roman";
margin-left:0in; margin-right:0in; margin-top:0in}
td{ font-family: sans-serif; font-size: 10pt; color: #000000;}
.pagecontent {padding:10px; background:#fff}
.style10 {font-size: 30px}
.style3 {font-size: 16}
.style4 {
font-size: 14px;
font-weight: bold;
}
-->
</style>
</head>
<body>
......................................

	Connection closed with webserver

-----------------------------------------------------------------------------/* For another client*/--------------------------------------------------------------------------------------

	Received message from the server

<!doctype html><html itemscope="" itemtype="http://schema.org/WebPage" lang="en"><head><meta content="Search the world's information, including webpages, images, videos and more. Google has many special features to help you find exactly what you're looking for." name="description"><meta content="noodp" name="robots"><meta content="/images/google_favicon_128.png" itemprop="image"><meta content="origin" id="mref" name="referrer"><title>Google</title> <script>(function(){window.google={kEI:'DNExVI6MFpaqyASbgoKICw',kEXPI:'4897,17259,3300102,3300134,3300137,3300161,3310366,3310648,3310754,3312195,3700340,3700343,3700348,4000116,4007661,4008142,4009033,4010858,4010899,4011679,4012373,4014431,4016824,4017981,4019702,4019841,4020148,4020240,4020250,4020347,4020379,4020381,4020383,4020385,4020500,4020560,4020663,4020726,4020822,4020872,4020879,4020892,4020921,4020948,4021015,4021071,4021092,4021125,4021341,4021498,4021537,4021634,4021660,4021796,4021890,4021909,4022087,4022140,4022195,4022268,4022271,4022327,4022468,4022565,4022727,4022729,4022881,4022882,4022996,7000511,8300007,8300030,8300072,8300087,8300091,8500272,8500325,8500393,8500556,8500572,8500585,8500593,8500615,10100012,10200083,10200297,10200347,10200581,10200585,10200602,10200631,10200671,10200685,10200698,10200699,10200702,10200706,10200708,10200710,10200712,10200724,10200726',authuser:0,j:{en:1,bv:21,pm:'p',u:'c9c918f0',qbp:0},kSID:'DNExVI6MFpaqyASbgoKICw'};google.kHL='en';})();(function(){google.lc=[];google.li=0;google.getEI=function(a){for(var b;a&&(!a.getAttribute||!(b=a.getAttribute("eid")));)a=a.parentNode;return b||google.kEI};google.https=function(){return"https:"==window.location.protocol};google.ml=function(){};google.time=function(){return(new Date).getTime()};google.log=function(a,b,d,h,k){var c=new Image,f=google.lc,e=google.li,g="",l=google.ls||"";c.onerror=c.onload=c.onabort=function(){delete f[e]};f[e]=c;d||-1!=b.search("&ei=")||(g="&ei="+google.getEI(h));a=d||"/"+(k||"gen_204")+"?atyp=i&ct="+a+"&cad="+b+g+l+"&zx="+google.time();/^http:/i.test(a)&&google.https()?(google.ml(Error("a"),!1,{src:a,glmm:1}),delete f[e]):(c.src=a,google.li=e+1)};google.y={};google.x=function(a,b){google.y[a.id]=[a,b];return!1};google.load=function(a,b,d){google.x({id:a+m++},function(){google.load(a,b,d)})};var m=0;})();google.kCSI={};
…………………………

	Connection closed with webserver





----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Client1 Side of code running on net02.utdallas.edu

	Client needs to pass two arguments
	1) Ip address of the host on which the server is running.
	2) Port Number at which server is listening.


	Compile -:     gcc –o client –client.c -lpthread

	Sample Output:-

	./client 10.176.67.64 2001

	Connection Established

	Please enter the URL: PortNo: FileName: www.utdallas.edu:80:/~ksarac/

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>

<meta http-equiv="Content-Language" content="en-us">

<meta name="GENERATOR" content="Microsoft FrontPage 6.0">

<meta name="ProgId" content="FrontPage.Editor.Document">

<meta http-equiv="Content-Type"
content="text/html; charset=windows-1252">
<title>Kamil Sarac</title>
<style>
<!--
li.MsoNormal
{mso-style-parent:"";
margin-bottom:.0001pt;
font-size:12.0pt;
font-family:"Times New Roman";
margin-left:0in; margin-right:0in; margin-top:0in}
td{ font-family: sans-serif; font-size: 10pt; color: #000000;}
.pagecontent {padding:10px; background:#fff}
.style10 {font-size: 30px}
.style3 {font-size: 16}
.style4 {
font-size: 14px;
font-weight: bold;
}
-->
</style>
</head>
<body>  ......................................

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Client2 Side of code running on net03.utdallas.edu

	Client needs to pass two arguments
	1) Ip address of the host on which the server is running.
	2) Port Number at which server is listening.

	Compile:-     gcc –o client –client.c –lpthread

	Sample Output:-

	./client 10.176.67.64 2001

	Connection Established

	Please enter the URL: PortNo: FileName: www.google.com:80: /?gws_rd=ssl

<!doctype html><html itemscope="" itemtype="http://schema.org/WebPage" lang="en"><head><meta content="Search the world's information, including webpages, images, videos and more. Google has many special features to help you find exactly what you're looking for." name="description"><meta content="noodp" name="robots"><meta content="/images/google_favicon_128.png" itemprop="image"><meta content="origin" id="mref" name="referrer"><title>Google</title> <script>(function(){window.google={kEI:'DNExVI6MFpaqyASbgoKICw',kEXPI:'4897,17259,3300102,3300134,3300137,3300161,3310366,3310648,3310754,3312195,3700340,3700343,3700348,4000116,4007661,4008142,4009033,4010858,4010899,4011679,4012373,4014431,4016824,4017981,4019702,4019841,4020148,4020240,4020250,4020347,4020379,4020381,4020383,4020385,4020500,4020560,4020663,4020726,4020822,4020872,4020879,4020892,4020921,4020948,4021015,4021071,4021092,4021125,4021341,4021498,4021537,4021634,4021660,4021796,4021890,4021909,4022087,4022140,4022195,4022268,4022271,4022327,4022468,4022565,4022727,4022729,4022881,4022882,4022996,7000511,8300007,8300030,8300072,8300087,8300091,8500272,8500325,8500393,8500556,8500572,8500585,8500593,8500615,10100012,10200083,10200297,10200347,10200581,10200585,10200602,10200631,10200671,10200685,10200698,10200699,10200702,10200706,10200708,10200710,10200712,10200724,10200726',authuser:0,j:{en:1,bv:21,pm:'p',u:'c9c918f0',qbp:0},kSID:'DNExVI6MFpaqyASbgoKICw'};google.kHL='en';})();(function(){google.lc=[];google.li=0;google.getEI=function(a){for(var b;a&&(!a.getAttribute||!(b=a.getAttribute("eid")));)a=a.parentNode;return b||google.kEI};google.https=function(){return"https:"==window.location.protocol};google.ml=function(){};google.time=function(){return(new Date).getTime()};google.log=function(a,b,d,h,k){var c=new Image,f=google.lc,e=google.li,g="",l=google.ls||"";c.onerror=c.onload=c.onabort=function(){delete f[e]};f[e]=c;d||-1!=b.search("&ei=")||(g="&ei="+google.getEI(h));a=d||"/"+(k||"gen_204")+"?atyp=i&ct="+a+"&cad="+b+g+l+"&zx="+google.time();/^http:/i.test(a)&&google.https()?(google.ml(Error("a"),!1,{src:a,glmm:1}),delete f[e]):(c.src=a,google.li=e+1)};google.y={};google.x=function(a,b){google.y[a.id]=[a,b];return!1};google.load=function(a,b,d){google.x({id:a+m++},function(){google.load(a,b,d)})};var m=0;})();google.kCSI={};
…………………………
