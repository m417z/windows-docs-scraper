# IUpdate::get_Categories

## Description

Gets an interface that contains a collection of categories to which the update belongs.

This property is read-only.

## Parameters

## Remarks

If the [IUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesearcher) interface is created by using the [IUpdateSession::CreateUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesession-createupdatesearcher) method, the information that this property returns is for the language that is specified by the [UserLocale](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesession2-get_userlocale) property of the [IUpdateSession2](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesession2) interface of the session that was used to create **IUpdateSearcher**.

If a language preference is not specified by the [UserLocale](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesession2-get_userlocale) property of [IUpdateSession2](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesession2), or if the [IUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesearcher) interface is not created by using [IUpdateSession::CreateUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesession-createupdatesearcher), the information that this property returns is for the default user interface (UI) language of the user. If the default UI language of the user is unavailable, Windows Update Agent (WUA) uses the default UI language of the computer. If the default language of the computer is unavailable, WUA uses the language that the provider of the update recommends.

Because there is a **Categories** property of [IUpdate](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate) and a [Categories](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatehistoryentry2-get_categories) property of [IUpdateHistoryEntry2](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatehistoryentry2), the information that is used by the localized properties of the [ICategory](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-icategory) interface depend on the WUA object that owns the **ICategory** interface. If the **ICategory** interface is returned from the **Categories** property of **IUpdate**, it follows the localization rules of **IUpdate**. If the **ICategory** interface is returned from the **Categories** property of **IUpdateHistoryEntry2**, it follows the localization rules of **IUpdateHistoryEntry2**.

## See also

[IUpdate](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate)