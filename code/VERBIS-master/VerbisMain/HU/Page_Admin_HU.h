#ifndef HU_PAGE_ADMIN_HU_H
#define HU_PAGE_ADMIN_HU_H

//
//  HTML PAGE
//

const char PAGE_AdminMainPage[] PROGMEM = R"=====(
<meta name="viewport" content="width=device-width, initial-scale=1" />
<strong>VERBIS Sz��ra Adminisztr�ci�</strong>
<hr>
<a href="config.html" style="width:250px" class="btn btn--m btn--blue" >H�l�zat konfigur�ci�</a><br>
<a href="info.html"   style="width:250px"  class="btn btn--m btn--blue" >H�l�zati Inform�ci�k</a><br>
<a href="ntp.html"   style="width:250px"  class="btn btn--m btn--blue" >Id� server be�ll�t�sok</a><br>
<a href="time.html"   style="width:250px"  class="btn btn--m btn--blue" >Pontos Id� Be�ll�t�s</a><br>
<a href="color.html"   style="width:250px"  class="btn btn--m btn--blue" >Szinbe�ll�t�s</a><br>

<script>
window.onload = function ()
{
	load("style.css","css", function() 
	{
		load("microajax.js","js", function() 
		{
				// Do something after load...
		});
	});
}
function load(e,t,n){if("js"==t){var a=document.createElement("script");a.src=e,a.type="text/javascript",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}else if("css"==t){var a=document.createElement("link");a.href=e,a.rel="stylesheet",a.type="text/css",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}}

</script>

)=====";

#endif /* HU_PAGE_ADMIN_HU_H */
