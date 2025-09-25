# IUpdate::get_ReleaseNotes

## Description

Gets the localized release notes for the update.

This property is read-only.

## Parameters

## Remarks

If the [IUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesearcher) interface is created by using the [IUpdateSession::CreateUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesession-createupdatesearcher) method, the information that this property returns is for the language that is specified by the [UserLocale](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesession2-get_userlocale) property. This is the **UserLocale** property of the [IUpdateSession2](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesession2) interface of the session that is used to create **IUpdateSearcher**.

If a language preference is not specified by the [UserLocale](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesession2-get_userlocale) property of [IUpdateSession2](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesession2), or if the [IUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesearcher) interface is not created by using [IUpdateSession::CreateUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesession-createupdatesearcher), the information that is returned by this property is for the default user interface (UI) language of the user. If the default UI language of the user is unavailable, Windows Update Agent (WUA) uses the default UI language of the computer. If the default language of the computer is unavailable, WUA uses the language that the provider of the update recommends.

## See also

[IUpdate](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate)