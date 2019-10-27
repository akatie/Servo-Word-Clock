#ifndef HU_PAGE_SETTIME_HU_H
#define HU_PAGE_SETTIME_HU_H

const char PAGE_SetTime[] PROGMEM = R"=====(
<meta name="viewport" content="width=device-width, initial-scale=1" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<a href="/"  class="btn btn--s"><</a>&nbsp;&nbsp;<strong>Pontos id&#337; be&#225;ll&#237;t&#225;s</strong>
<hr>
<form action="" method="get">
<table border="0"  cellspacing="0" cellpadding="3" >
<tr><td align="right">&Oacute;ra:</td><td><input type="text" id="set_hour" name="set_hour" size="3" maxlength="2" value=""></td></tr>
<tr><td align="right">Perc:</td><td><input type="text" id="set_minute" name="set_minute" size="3" maxlength="2" value=""></td></tr>
<tr><td align="right">M&aacute;sodperc:</td><td><input type="text" id="set_second" name="set_second" size="3" maxlength="2" value=""></td></tr>
<tr><td colspan="2" align="center"><input type="submit" style="width:150px" class="btn btn--m btn--blue" value="Ment&eacute;s"></td></tr>
</table>
</form>
<script>

window.onload = function ()
{
  load("style.css","css", function() 
  {
    load("microajax.js","js", function() 
    {
        setValues("/admin/timevalues");
    });
  });
}
function load(e,t,n){if("js"==t){var a=document.createElement("script");a.src=e,a.type="text/javascript",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}else if("css"==t){var a=document.createElement("link");a.href=e,a.rel="stylesheet",a.type="text/css",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}}



</script>
)=====";

void send_Time_Set_html()
{
  if (server.args() > 0 )  // Save Settings
  {
    for ( uint8_t i = 0; i < server.args(); i++ ) {
      if (server.argName(i) == "set_hour") DateTime.hour = server.arg(i).toInt();
      if (server.argName(i) == "set_minute") DateTime.minute = server.arg(i).toInt();
      if (server.argName(i) == "set_second") DateTime.second = server.arg(i).toInt();
    }
    manual_time_set = true;
    UnixTimestamp = (DateTime.hour*3600 + DateTime.minute*60 + DateTime.second - config.timeZone*360);
    ISRsecondTick();
  }
  server.send_P ( 200, "text/html", PAGE_SetTime );
  Serial.println(__FUNCTION__);

}

void send_Time_Set_values_html()
{

  String values ="";
  values += "set_hour|" + (String) DateTime.hour + "|input\n";
  values += "set_minute|" +  (String) DateTime.minute + "|input\n";
  values += "set_second|" +  (String) DateTime.second + "|input\n";
  server.send ( 200, "text/plain", values);
  Serial.println(__FUNCTION__);
  AdminTimeOutCounter=0;
}

#endif /* HU_PAGE_SETTIME_HU_H */