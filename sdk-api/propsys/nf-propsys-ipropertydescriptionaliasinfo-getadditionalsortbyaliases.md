# IPropertyDescriptionAliasInfo::GetAdditionalSortByAliases

## Description

Gets the address of a pointer to the [IPropertyDescriptionList](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescriptionlist) interface, which contains additional sort column values.

## Parameters

### `riid` [in]

Type: **REFIID**

A reference to the identifier of the requested [IPropertyDescriptionList](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescriptionlist) interface.

### `ppv` [out]

Type: **void****

When this method returns successfully, contains the address of a pointer to an [IPropertyDescriptionList](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescriptionlist) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The following is an example usage for this method. When sorting by System.Author: System.DateModified, System.DateCreated, and System.ItemNameDisplay may be used as secondary sort columns. This ensures a unique sort order (for System.Author) and is used to provide a more consistent user experience.

 Calling applications include any UI that wants the secondary sort columns for a given property.

## See also

[IPropertyDescriptionAliasInfo](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescriptionaliasinfo)

[IPropertyDescriptionAliasInfo::GetSortByAlias](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertydescriptionaliasinfo-getsortbyalias)