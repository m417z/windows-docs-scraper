# IUpdateHistoryEntry2::get_Categories

## Description

Gets a collection of the update categories to which an update belongs.

This property is read-only.

## Parameters

## Remarks

The [IUpdateHistoryEntry2](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatehistoryentry2) interface may require you to update Windows Update Agent (WUA). For more information, see [Updating Windows Update Agent](https://learn.microsoft.com/windows/desktop/Wua_Sdk/updating-the-windows-update-agent).

The information that this property returns is for the default user interface (UI) language of the user. If the default UI language of the user is unavailable, WUA uses the default UI language of the computer. If the default language of the computer is unavailable, WUA uses the language that the provider of the update recommends.

Because there is a [Categories](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdate-get_categories) property of the [IUpdate](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate) interface and a **Categories** property of the [IUpdateHistoryEntry2](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatehistoryentry2) interface, the information that is used by the localized properties of the [ICategory](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-icategory) interface depends on the WUA object that owns the **ICategory** interface. If the **ICategory** interface is returned from the **Categories** property of **IUpdate**, it follows the localization rules of **IUpdate**. If the **ICategory** interface is returned from the **Categories** property of **IUpdateHistoryEntry2**, it follows the localization rules of **IUpdateHistoryEntry2**.

## See also

[IUpdateHistoryEntry2](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatehistoryentry2)