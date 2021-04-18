class edn_fortification_dialogMenu
{
	idd = -1;
	movingenable = false;

	class controls
	{
		class RscText000 : RscText
		{
			text = "Fortification menu";
			x = 0.25;
			y = 0.14;
			h = 0.1;
			w = 0.5;
			colorBackground[] = {1,0.5,0,1};
			SizeEx = "2 * 0.024";
			style = ST_CENTER;
		};
		class GUIBack000 : IGUIBack
		{    
			x = 0.25; 
			y = 0.25;
			h = 0.5;
			w = 0.5;
			colorBackground[] = {0,0,0,0.75};
		};
		class RscButton000 : RscButton
		{
			text = "construction menu";
			x = 0.27; 
			y = 0.29;
			h = 0.10;
			w = 0.21;
			style = ST_CENTER;
			action = "closeDialog 0; [player] call edn_fnc_openconstructionmenu;";
		};
		class RscButton001 : RscButton
		{
			idc = 1500;
			text = "build from chest";
			x = 0.52; 
			y = 0.29;
			h = 0.10;
			w = 0.21;
			style = ST_CENTER;
			action = "closeDialog 0; [cursorTarget] call edn_fnc_openconstructionmenu";
		};
		class RscButton002 : RscButton
		{
			idc = 1501;
			text = "move object";
			x = 0.27; 
			y = 0.45;
			h = 0.10;
			w = 0.21;
			style = ST_CENTER;
			action = "[cursorTarget] call edn_fnc_moveObject; closeDialog 0;";
		};
		class RscButton003 : RscButton
		{
			idc = 1502;
			text = "remove object";
			x = 0.52; 
			y = 0.45;
			h = 0.10;
			w = 0.21;
			style = ST_CENTER;
			action = "[cursorTarget] call edn_fnc_removeObject; closeDialog 0;";
		};
		class RscButton004 : RscButton
		{
			idc = 1503;
			text = "align to ground";
			x = 0.27; 
			y = 0.61;
			h = 0.10;
			w = 0.21;
			style = ST_CENTER;
			action = "[] call edn_fnc_alignObject; closeDialog 0;";
		};
		class RscButton005 : RscButton
		{
			text = "cancel";
			x = 0.52; 
			y = 0.61;
			h = 0.10;
			w = 0.21;
			style = ST_CENTER;
			action = "closeDialog 0;";
		};
	};
};

class edn_fortification_dialogConstructionMenu
{
	idd = -1;
	movingenable = false;
	enableSimulation = 1;
	
	onLoad = "uiNamespace setVariable ['edn_fortification_display',_this select 0];";
	
	class Objects
	{
		class Object
		{
			idc = 1503; 
			type = 82;
			model = "A3\Structures_F\Mil\BagFence\BagFence_Long_F.p3d";
			scale = 1;
			
			direction[] = {0, 0, 1};
			up[] = {0, 1, 1};
 
			x = 0.5;
			y = 0.5;
			z = 4.5;
 
			xBack = 0.825;
			yBack = 0.5;
			zBack = 1.2;
 
			inBack = 0;
			enableZoom = 1;
			zoomDuration = 0.001;
		};
	};
	class controls
	{
		class GUIBack001 : IGUIBack
		{    
			x = safeZoneX + 0.01 * 3 / 4; 
			y = safeZoneY + 0.12;
			h = safeZoneH - 0.13;
			w = 0.75 * 3 / 4;
			colorBackground[] = {0,0,0,0.7};
		};
		
		class RscText000 : RscText
		{
			text = "Construction menu";
			x = safeZoneX + 0.01 * 3 / 4; 
			y = safeZoneY + 0.01;
			h = 0.1;
			w = 0.75 * 3 / 4;
			colorBackground[] = {1,0.5,0,1};
			SizeEx = "2 * 0.024";
			style = ST_CENTER;
		};
		
		class RscButton000 : RscButton
		{
			text = "cancel";
			x = safeZoneX + 0.035 * 3 / 4; 
			y = safeZoneY + safeZoneH - 0.12;
			h = 0.075;
			w = 0.3 * 3 / 4;
			style = ST_CENTER;
			action = "closeDialog 0";
		};
		class RscButton001 : RscButton
		{
			text = "build";
			x = safeZoneX + 0.425 * 3 / 4; 
			y = safeZoneY + safeZoneH - 0.12;
			h = 0.075;
			w = 0.3 * 3 / 4;
			style = ST_CENTER;
			action = "[] call edn_fnc_buildObject; closeDialog 0;";
		};
		
		class RscText002 : RscText
		{
			text = "Categorie:";
			x = safeZoneX + 0.02 * 3 / 4; 
			y = safeZoneY + 0.15;
			h = 0.04;
			w = 0.13 * 3 / 4;
			colorBackground[] = {0,0,0,0};
			colorText[] = {1,1,1,1};
			style = ST_LEFT;
		};
		
		class RscCombo000 : RscCombo
		{
			idc = 1500;
			x = safeZoneX + 0.15 * 3 / 4; 
			y = safeZoneY + 0.15;
			h = 0.04;
			w = 0.56 * 3 / 4;
			colorBackground[] = {0.1,0.1,0.1,1};
			
			onLBSelChanged = "[_this select 1,'Categorie'] call edn_fnc_updateConstructionMenu;";
		};
		class RscListBox000 : RscListBox
		{
			idc = 1501;
			x = safeZoneX + 0.04 * 3 / 4; 
			y = safeZoneY + 0.22;
			h = safeZoneH - 0.40;
			w = 0.68 * 3 / 4;
			colorBackground[] = {0,0,0,1};
			
			onLBSelChanged = "[_this select 1,'Classname'] call edn_fnc_updateConstructionMenu;";
			onLBDblClick = "[] call edn_fnc_buildObject; closeDialog 0;";
		};
		
		class GUIBack000 : RscListBox
		{    
			x = safeZoneX + 0.76 * 3 / 4; 
			y = safeZoneY;
			h = safeZoneH;
			w = safeZoneW - 0.76 * 3 / 4;
			colorBackground[] = {0,0,0,0};
		};
	};
	class controlsBackground
	{
		class GUIBack000 : IGUIBack
		{    
			x = safeZoneX; 
			y = safeZoneY;
			h = safeZoneH;
			w = safeZoneW;
			colorBackground[] = {0.5,0.5,0.5,1};
		};
	};
};

class jjx_menu
{
	idd = 999;
	movingenable = false;

	class controls 
	{
		class GUIBack220: IGUIBack
		{
			idc = 2200;
			x = 0.386534 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.226932 * safezoneW;
			h = 0.176 * safezoneH;
		};
		class txtName: RscText
		{
			idc = 1000;
			text = "BEAR Menu";
			x = 0.386534 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.216617 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class btnClose: RscButton
		{
			onMouseButtonClick = "closeDialog 0;";
			idc = 1600;
			text = "X";
			x = 0.603151 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.0103151 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = "Close the menu.";
		};
		class btnBackpack: RscButton
		{
			onMouseButtonClick = "if (isObjectHidden unitBackpack player) then {[unitBackpack player, false] remoteExec ['hideObjectGlobal', 2];} else {[unitBackpack player, true] remoteExec ['hideObjectGlobal', 2];};";
			idc = 1601;
			text = "Toggle backpack";
			x = 0.396849 * safezoneW + safezoneX;
			y = 0.456 * safezoneH + safezoneY;
			w = 0.0618905 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Toggle the visability of you backpack.";
		};
		class btnGrass: RscButton
		{
			onMouseButtonClick = "_this call jjx_fnc_grass;";
			idc = 1602;
			text = "Toggle Grass";
			x = 0.469055 * safezoneW + safezoneX;
			y = 0.456 * safezoneH + safezoneY;
			w = 0.0618905 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Toggle the visability of grass.";
		};
		class btnVisability: RscButton
		{
			onMouseButtonClick = "closeDialog 0;_this call CHVD_fnc_openDialog;";
			idc = 1603;
			text = "Change view";
			x = 0.54126 * safezoneW + safezoneX;
			y = 0.456 * safezoneH + safezoneY;
			w = 0.0618905 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Change your view distance.";
		};
		class btnAdmin: RscButton
		{
			onMouseButtonClick = "_this call jjx_fnc_openAdmin;";
			idc = 1604;
			text = "Admin";
			x = 0.54126 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.0618905 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Options for admins";
		};
		class btnSycn: RscButton
		{
			idc = 1605;
			text = "Sync";
			onMouseButtonClick = "player setUnitLoadout (getUnitLoadout player);";
			x = 0.396849 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.0618905 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Is someone says you have no clothes when you do, click me.";
		};
		class btnZeus: RscButton
		{
			idc = 1606;
			text = "Zeus";
			onMouseButtonClick = "_this call jjx_fnc_openZeus;";
			x = 0.469055 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.0618905 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Options for zeus";
		};
	};
};

class jjx_timerMenu
{
	idd = 998;
	movingenable = false;

	class controls 
	{
		class GUIBack220: IGUIBack
		{
			idc = 2200;
			x = 0.386534 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.226932 * safezoneW;
			h = 0.176 * safezoneH;
		};
		class txtName: RscText
		{
			idc = 1000;
			text = "JJ's Timer Menu";
			x = 0.386534 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.216617 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class btnClose: RscButton
		{
			onMouseButtonClick = "closeDialog 0;";
			idc = 1600;
			text = "X";
			x = 0.603151 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.0103151 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = "Close the menu.";
		};
		class edtInput: RscEdit
		{
			idc = 1400;
			text = "3";
			x = 0.396849 * safezoneW + safezoneX;
			y = 0.456 * safezoneH + safezoneY;
			w = 0.0618905 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Input the number of minutes for the safezone to last.";
		};
		class btnTimer: RscButton
		{
			text = "Set Safe Timer";
			onMouseButtonClick = "[parseNumber ctrlText 1400] remoteExec ['jjx_fnc_setTimer', 2];_this spawn {hintsilent format ['Timer set to %1 minutes', parseNumber ctrlText 1400];uiSleep 3; hintsilent '';};";
			x = 0.396849 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.0618905 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Set the number of minutes input above.";
		};
		class btnEnableSafe: RscButton
		{
			onMouseButtonClick = "[true] remoteExec ['jjx_fnc_safety', 0, true];_this spawn {hintsilent 'Silently enabled safestart';uiSleep 3; hintsilent '';};";
			text = "Enable Safety";
			x = 0.54126 * safezoneW + safezoneX;
			y = 0.456 * safezoneH + safezoneY;
			w = 0.0618905 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "(SILENT) Enable safemode without a countdown.";
		};
		class btnDisableSafe: RscButton
		{
			onMouseButtonClick = "missionNamespace setVariable ['f_var_mission_timer', -1, true];[false] remoteExec ['jjx_fnc_safety', 0, true];_this spawn {hintsilent 'Silently disabled safestart';uiSleep 3; hintsilent '';};";
			text = "Disable safety";
			x = 0.54126 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.0618905 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "(SILENT) Disable safemode and stop countdown.";
		};
		class btnStart: RscButton
		{
			text = "Start the timer";
			onMouseButtonClick = "'f\safeStart\f_safeStart.sqf' remoteExec ['execVM', 0];_this spawn {hintsilent 'Safestart timer has started';uiSleep 3; hintsilent '';};";
			x = 0.469055 * safezoneW + safezoneX;
			y = 0.456 * safezoneH + safezoneY;
			w = 0.0618905 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Make sure you set the timer first (Left)";
		};
		class btnEnd: RscButton
		{
			text = "End the timer";
			onMouseButtonClick = "missionNamespace setVariable ['f_var_mission_timer', -1, true];[['SafeStartMissionStarting',['Safe Start ended by admin!']],'bis_fnc_showNotification',true] call BIS_fnc_MP;[false] remoteExec ['jjx_fnc_safety', 0, true];";
			x = 0.469055 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.0618905 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "End Safe Start and notify players.";
		};
	};
};

class jjx_adminMenu
{
	idd = 998;
	movingenable = false;

	class controls 
	{
		class GUIBack220: IGUIBack
		{
			idc = 2200;
			x = 0.386534 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.226932 * safezoneW;
			h = 0.176 * safezoneH;
		};
		class txtName: RscText
		{
			idc = 1000;
			text = "JJ's Admin Menu";
			x = 0.386534 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.216617 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class btnClose: RscButton
		{
			onMouseButtonClick = "closeDialog 0;";
			idc = 1600;
			text = "X";
			x = 0.603151 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.0103151 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = "Close the menu.";
		};
		class btnHealAll: RscButton
		{
			text = "Heal all";
			onMouseButtonClick = "[] remoteExec ['jjx_fnc_healAll', 0, true];_this spawn {hintsilent 'Healed all!';uiSleep 3; hintsilent '';};";
			x = 0.396849 * safezoneW + safezoneX;
			y = 0.456 * safezoneH + safezoneY;
			w = 0.0618905 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Ace heal all players.";
		};
		class btnNotification: RscButton
		{
			text = "Notification";
			onMouseButtonClick = "_this call jjx_fnc_openNotification;";
			x = 0.396849 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.0618905 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Open notification handler.";
		};
		class btnTimer: RscButton
		{
			text = "Timer";
			onMouseButtonClick = "_this call jjx_fnc_openTimer;"
			x = 0.469055 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.0618905 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Open timer menu.";
		};
	};
};

class jjx_zeusMenu
{
	idd = 998;
	movingenable = false;

	class controls 
	{
		class GUIBack220: IGUIBack
		{
			idc = 2200;
			x = 0.386534 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.226932 * safezoneW;
			h = 0.176 * safezoneH;
		};
		class txtName: RscText
		{
			idc = 1000;
			text = "Bear Zeus Menu";
			x = 0.386534 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.216617 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class btnClose: RscButton
		{
			onMouseButtonClick = "closeDialog 0;";
			idc = 1600;
			text = "X";
			x = 0.603151 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.0103151 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = "Close the menu.";
		};
		class btnHealAll: RscButton
		{
			text = "Heal all";
			onMouseButtonClick = "[] remoteExec ['jjx_fnc_healAll', 0, true];_this spawn {hintsilent 'Healed all!';uiSleep 3; hintsilent '';};";
			x = 0.396849 * safezoneW + safezoneX;
			y = 0.456 * safezoneH + safezoneY;
			w = 0.0618905 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Ace heal all players.";
		};
		class btnToggleFPS: RscButton
		{
			text = "Toggle FPS";
			onMouseButtonClick = "call jjx_fnc_toggleFPS;";
			x = 0.396849 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.0618905 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Toggle the FPS overlay";
		};
	};
};

class jjx_notificationMenu
{
	idd = 997;
	movingenable = false;

	class controls 
	{
		class GUIBack220: IGUIBack
		{
			idc = 2200;
			x = 0.386534 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.226932 * safezoneW;
			h = 0.176 * safezoneH;
		};
		class txtName: RscText
		{
			idc = 1000;
			text = "JJ's Notification Menu";
			x = 0.386534 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.216617 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class btnClose: RscButton
		{
			onMouseButtonClick = "closeDialog 0;";
			idc = 1600;
			text = "X";
			x = 0.603151 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.0103151 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = "Close the menu.";
		};
		class edtTitle: RscEdit
		{
			idc = 1401;
			x = 0.396849 * safezoneW + safezoneX;
			y = 0.456 * safezoneH + safezoneY;
			w = 0.206302 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Input the title for the notification.";
		};
		class edtDescription: RscEdit
		{
			idc = 1402;
			x = 0.396849 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.144411 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Input the description for the notification.";
		};
		class btnSend: RscButton
		{
			text = "Send";
			onMouseButtonClick = "['Custom',[format['%1',ctrlText 1401],format['%1',ctrlText 1402]]] remoteExec ['bis_fnc_showNotification', 0, true];";
			x = 0.551575 * safezoneW + safezoneX;
			y = 0.522 * safezoneH + safezoneY;
			w = 0.0515754 * safezoneW;
			h = 0.044 * safezoneH;
			tooltip = "Send the notification";
		};
	};
};