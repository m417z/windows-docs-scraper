# CItemIDFactory::GetPropertyFromIDList(PCUIDLIST_RELATIVE,PCWSTR,VARIANT)

## Description

Gets a property from the [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) within the IDList as a variant, using the key.

## Parameters

### `pidl` [in]

A PIDL identifying the [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore).

### `pszName` [in]

The key for the selected property.

### `pvar`

When this method returns, contains a pointer to the property. If *rkey* is not found, *pvar* will be **VT_EMPTY**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is useful when using [IShellFolder2::GetDetailsEx](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder2-getdetailsex), as is returns a variant rather than a **PROPVARIANT**.

## See also

[CItemIDFactory](https://learn.microsoft.com/windows/desktop/api/shidfact/nl-shidfact-citemidfactory)

[GetPropertyFromIDList](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh289343(v=vs.85))

[IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore)

[IShellFolder2::GetDetailsEx](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder2-getdetailsex)