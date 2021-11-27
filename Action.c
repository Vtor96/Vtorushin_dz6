Action()
{
	max = 0;
	maxInd = 0;
	
	for(i = 0; i < 3; i++)
	{
	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={Login}", ENDITEM,
		"Name=password", "Value={Password}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=0", ENDITEM,
		"Name=login.y", "Value=0", ENDITEM,
		LAST);
		
	web_reg_find("Text=First class",
	    "SaveCount=First_Count",
		LAST);
		
	web_url("Itinerary Button",
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
		
		/*Correlation comment - Do not change!  Original value='132687.192061563zicfAQHpttVzzzzHtAQfApfitzf' Name ='userSession' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value",
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);

	web_url("webtours", 
		"URL=http://localhost:1080/webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
		
		first = atoi(lr_eval_string("{First_Count}"));
		
		if(first > max)
		{
			max = first;
			maxInd = i + 1;
		}
		
	}
	
	if(maxInd == 0)
	{
		maxInd = 1;
	}
	
	for(i = 0; i < maxInd; i++)
	{
		lr_save_string(lr_eval_string("{Login}"), "Log");
		lr_save_string(lr_eval_string("{Password}"), "Pas");
		
	}
	
	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={Log}", ENDITEM,
		"Name=password", "Value={Pas}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=63", ENDITEM,
		"Name=login.y", "Value=7", ENDITEM,
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=FlightID", 
        "LB/IC=name=\"flightID\" value=\"",
        "RB/IC=\"  />",
        "Notfound=warning",
    	"Ordinal=all",
    	LAST);
	
	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	
	web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name={DeleateRandom}", "Value=on", ENDITEM, 
		"Name=flightID", "Value={FlightID_1}", ENDITEM, 
		"Name=flightID", "Value={FlightID_2}", ENDITEM,
		"Name=flightID", "Value={FlightID_3}", ENDITEM, 
		"Name=flightID", "Value={FlightID_4}", ENDITEM, 
		"Name=flightID", "Value={FlightID_5}", ENDITEM, 
		"Name=flightID", "Value={FlightID_6}", ENDITEM, 
		"Name=flightID", "Value={FlightID_7}", ENDITEM, 
		"Name=flightID", "Value={FlightID_8}", ENDITEM, 
		"Name=flightID", "Value={FlightID_9}", ENDITEM, 		
		"Name=flightID", "Value={FlightID_10}", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM,
		"Name=.cgifields", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=5", ENDITEM, 
		"Name=.cgifields", "Value=6", ENDITEM, 
		"Name=.cgifields", "Value=7", ENDITEM, 
		"Name=.cgifields", "Value=8", ENDITEM, 
		"Name=.cgifields", "Value=9", ENDITEM, 
		"Name=.cgifields", "Value=10", ENDITEM, 		
		"Name=removeFlights.x", "Value=72", ENDITEM, 
		"Name=removeFlights.y", "Value=6", ENDITEM, 
		LAST);
	
	return 0;
}
