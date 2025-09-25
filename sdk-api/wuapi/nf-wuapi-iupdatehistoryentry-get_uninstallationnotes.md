# IUpdateHistoryEntry::get_UninstallationNotes

## Description

Gets the uninstallation notes of an update.

This property is read-only.

## Parameters

## Remarks

The information that this property returns is for the default user interface (UI) language of the user. However, note the following:

* If the default UI language of the user is unavailable, Windows Update Agent (WUA) uses the default UI language of the computer.
* If the default language of the computer is unavailable, WUA uses the language that the provider of the update recommends.

## See also

[IUpdateHistoryEntry](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatehistoryentry)

[IUpdateHistoryEntry.ClientApplicationID](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatehistoryentry-get_clientapplicationid)