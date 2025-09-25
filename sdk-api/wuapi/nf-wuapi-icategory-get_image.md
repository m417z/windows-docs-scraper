# ICategory::get_Image

## Description

Gets an interface that contains information about the image that is associated with the category.

This property is read-only.

## Parameters

## Remarks

A [Categories](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdate-get_categories) property exists for the [IUpdate](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate) interface. And, a [Categories](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatehistoryentry2-get_categories) property exists for the [IUpdateHistoryEntry2](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatehistoryentry2) interface. Therefore, the information that is used by the localized properties of the [ICategory](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-icategory) interface depends on the Windows Update Agent (WUA) object that owns the **ICategory** interface.

 If the [ICategory](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-icategory) interface is returned from the [Categories](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdate-get_categories) property of [IUpdate](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate), the **ICategory** interface follows the localization rules of the **IUpdate** interface. In this case, if the [IUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesearcher) interface is created by using the [IUpdateSession::CreateUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesession-createupdatesearcher) method, the information that this property returns is for the language that is specified by the [UserLocale](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesession2-get_userlocale) property of the [IUpdateSession2](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesession2) interface of the session that is used to create **IUpdateSearcher**.

If a language preference is not specified by the [UserLocale](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesession2-get_userlocale) property of the [IUpdateSession2](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesession2) interface, or if the [IUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesearcher) interface is not created by using the [IUpdateSession::CreateUpdateSearcher](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatesession-createupdatesearcher) method, the information that this property returns is for the default user interface (UI) language of the user. If the default UI language of the user is unavailable, WUA uses the default UI language of the computer. If the default language of the computer is unavailable, WUA uses the language that the provider of the update recommends.

If the [ICategory](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-icategory) interface is returned from the [Categories](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatehistoryentry2-get_categories) property of the [IUpdateHistoryEntry2](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatehistoryentry2) interface, the **ICategory** interface follows the localization rules of the **IUpdateHistoryEntry2** interface. The information that this property returns is for the default UI language of the user. If the default UI language of the user is unavailable, WUA uses the default UI language of the computer. If the default language of the computer is unavailable, WUA uses the language that the provider of the update recommends.

## See also

[ICategory](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-icategory)

[IImageInformation](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iimageinformation)