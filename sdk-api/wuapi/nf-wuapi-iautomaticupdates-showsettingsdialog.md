# IAutomaticUpdates::ShowSettingsDialog

## Description

[**IAutomaticUpdates::ShowSettingsDialog** is no longer supported. Starting with
Windows 10 calls to **ShowSettingsDialog** always return
**S_OK**, but do nothing.]

Displays a dialog box that contains settings for Automatic Updates.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | This method cannot be called from a remote computer. |
| **WU_E_AU_NOSERVICE** | Automatic Updates is not enabled. |
| **WU_E_AU_PAUSED** | Automatic Updates is paused. |
| **WU_E_LEGACYSERVER** | You cannot search for updates if the following conditions are true:<br><br>* The [ServerSelection](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesearcher-get_serverselection) property of the [IUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesearcher) interface is set to [ssManagedServer](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/wuapicommon/ne-wuapicommon-serverselection.md) or [ssDefault](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/wuapicommon/ne-wuapicommon-serverselection.md).<br>* The managed server on a computer is a Microsoft Software Update Services (SUS) 1.0 server. |

## Remarks

A call to **ShowSettingsDialog** fails if the calling user is not logged on or does not have a desktop.
A caller can also programmatically modify Automatic Updates settings by using the [Settings](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdates-get_settings) property.

The settings in the dialog box are read-only if the caller has insufficient security permissions or if the settings are enforced by a domain administrator who is using Group Policy settings.

 This method returns **WU_E_AU_NOSERVICE** if Automatic Updates is disabled, initializing, uninitializing, or not configured.

## See also

[IAutomaticUpdates](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iautomaticupdates)

[IAutomaticUpdates.Settings](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdates-get_settings)