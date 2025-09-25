# IPropertyDescriptionAliasInfo::GetSortByAlias

## Description

Gets the address of a pointer to the [IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription) interface containing the primary sort column.

## Parameters

### `riid` [in]

Type: **REFIID**

A reference to the identifier of the requested [IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription) interface.

### `ppv` [out]

Type: **void****

When this method returns successfully, contains the address of a pointer to the [IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription) interface for the calling object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IPropertyDescriptionAliasInfo](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescriptionaliasinfo)

[IPropertyDescriptionAliasInfo::GetAdditionalSortByAliases](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertydescriptionaliasinfo-getadditionalsortbyaliases)