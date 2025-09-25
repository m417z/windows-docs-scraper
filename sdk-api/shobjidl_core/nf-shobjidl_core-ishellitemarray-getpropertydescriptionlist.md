# IShellItemArray::GetPropertyDescriptionList

## Description

Gets a property description list for the items in the shell item array.

## Parameters

### `keyType` [in]

Type: **REFPROPERTYKEY**

A reference to the [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure specifying which property list to retrieve.

### `riid` [in]

Type: **REFIID**

The IID of the object type to retrieve.

### `ppv` [out]

Type: **void****

When this method returns, contains the interface requested in riid. This will typically be [IPropertyDescriptionList](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescriptionlist).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function is used to determine a list of properties that are applicable to a set of shell items. The type of list is specified by a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure. Supported list types include but are not limited to:

* PKEY_PropList_PreviewDetails
* PKEY_PropList_PreviewTitle
* PKEY_PropList_FullDetails
* PKEY_PropList_TileInfo
* PKEY_PropList_ExtendedTileInfo
* PKEY_PropList_InfoTip
* PKEY_PropList_QuickTip
* PKEY_PropList_FileOperationPrompt
* PKEY_PropList_ConflictPrompt
* PKEY_PropList_SetDefaultsFor
* PKEY_PropList_NonPersonal
* PKEY_NewMenuPreferredTypes
* PKEY_NewMenuAllowedTypes

If the shell item array contains more than one item, then this method will obtain an intersection of the properties that would be returned for each item individually.

## See also

[IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray)

[Property Lists](https://learn.microsoft.com/windows/desktop/properties/building-property-handlers-property-lists)