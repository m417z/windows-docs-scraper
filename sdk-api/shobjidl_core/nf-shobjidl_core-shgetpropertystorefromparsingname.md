# SHGetPropertyStoreFromParsingName function

## Description

Returns a property store for an item, given a path or parsing name.

## Parameters

### `pszPath` [in]

Type: **PCWSTR**

A pointer to a null-terminated Unicode string that specifies the item path.

### `pbc` [in, optional]

Type: **[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)***

A pointer to a [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) object, which provides access to a bind context. This value can be **NULL**.

### `flags` [in]

Type: **[GETPROPERTYSTOREFLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-getpropertystoreflags)**

One or more values from the [GETPROPERTYSTOREFLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-getpropertystoreflags) constants. This parameter can also be **NULL**.

### `riid` [in]

Type: **REFIID**

A reference to the desired interface ID.

### `ppv` [out]

Type: **void****

When this function returns, contains the interface pointer requested in *riid*. This is typically [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) or a related interface.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IShellItem2::GetPropertyStore](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem2-getpropertystore)