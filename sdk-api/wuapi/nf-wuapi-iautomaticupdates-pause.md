# IAutomaticUpdates::Pause

## Description

[**IAutomaticUpdates::Pause** is no longer supported. Starting with
Windows 10 calls to **Pause** always return
**S_OK**, but do nothing.]

Pauses automatic updates.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | This method cannot be called from a remote computer. |
| **WU_E_INVALID_OPERATION** | The computer could not access the update site. |
| **WU_E_AU_NOSERVICE** | Automatic Updates is not enabled. |
| **WU_E_AU_PAUSED** | Automatic Updates is paused. |
| **WU_E_LEGACYSERVER** | You cannot search for updates if the following conditions are true:<br><br>* The [ServerSelection](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesearcher-get_serverselection) property of the [IUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesearcher) interface is set to [ssManagedServer](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/wuapicommon/ne-wuapicommon-serverselection.md) or [ssDefault](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/wuapicommon/ne-wuapicommon-serverselection.md).<br>* The managed server on a computer is a Microsoft Software Update Services (SUS) 1.0 server. |

## Remarks

This method requires administrator permissions.

Automatic Updates can be paused for only eight hours. This limit varies in different binary versions.
Callers should call the [Resume](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdates-resume) method after
calling **Pause** as soon as they no longer need to
pause automatic updating.

This method returns **WU_E_INVALID_OPERATION** if the object that is implementing the
interface is locked down.

This method returns **WU_E_AU_NOSERVICE** if Automatic Updates is disabled,
initializing, uninitializing, or not configured.

## See also

[IAutomaticUpdates](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iautomaticupdates)

[IAutomaticUpdates.Resume](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdates-resume)