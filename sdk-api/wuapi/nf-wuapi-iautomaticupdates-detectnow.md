# IAutomaticUpdates::DetectNow

## Description

Begins the Automatic Updates detection task if Automatic Updates is enabled. If any updates are detected, the installation behavior is determined by the [NotificationLevel](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings-get_notificationlevel) property of the [IAutomaticUpdatesSettings](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iautomaticupdatessettings) interface.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **WU_E_AU_NOSERVICE** | Automatic Updates is not enabled. |
| **WU_E_AU_PAUSED** | Automatic Updates is paused. |
| **WU_E_LEGACYSERVER** | You cannot search for updates if the following conditions are true:<br><br>* The [ServerSelection](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesearcher-get_serverselection) property of the [IUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesearcher) interface is set to [ssManagedServer](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/wuapicommon/ne-wuapicommon-serverselection.md) or [ssDefault](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/wuapicommon/ne-wuapicommon-serverselection.md).<br>* The managed server on a computer is a Microsoft Software Update Services (SUS) version 1.0 server. |

## Remarks

This method returns **WU_E_AU_NOSERVICE** if Automatic Updates is disabled, initializing, uninitializing, or not configured.

## See also

[IAutomaticUpdates](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iautomaticupdates)