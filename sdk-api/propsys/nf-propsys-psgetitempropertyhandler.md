# PSGetItemPropertyHandler function

## Description

Retrieves a property handler for a Shell item.

## Parameters

### `punkItem` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of a Shell item that supports [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem).

**Windows XP:** Use [SHCreateShellItem](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shcreateshellitem) to create the Shell item.

**Windows Vista:** Use [SHCreateItemFromIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shcreateitemfromidlist), [SHCreateItemFromParsingName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shcreateitemfromparsingname), [SHCreateItemFromRelativeName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shcreateitemfromrelativename), [SHCreateItemInKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shcreateiteminknownfolder), or [SHCreateItemWithParent](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-shcreateitemwithparent) to create the Shell item.

### `fReadWrite` [in]

Type: **BOOL**

**TRUE** to retrieve a read/write property handler. **FALSE** to retrieve a read-only property handler.

### `riid` [in]

Type: **REFIID**

Reference to the IID of the interface the handler object should return. This should be [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) or an interface derived from **IPropertyStore**.

### `ppv` [out]

Type: **void****

When this function returns, contains the interface pointer requested in *riid*.

## Return value

Type: **PSSTDAPI**

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

This function is supported in Windows XP and Windows Vista. For applications supported only on Windows Vista or later, it is recommended that you use [IShellItem2::GetPropertyStore](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem2-getpropertystore) instead of [PSGetItemPropertyHandler](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetitempropertyhandler). That method provides a richer set of properties in the property store that is returned.

This function is approximately equivalent to passing the GPS_HANDLERPROPERTIESONLY flag to [IShellItem2::GetPropertyStore](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem2-getpropertystore).

You must initialize Component Object Model (COM) with [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) or [OleInitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize) before you call [PSGetItemPropertyHandler](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetitempropertyhandler). COM must remain initialized for the lifetime of this object.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PSGetItemPropertyHandler](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetitempropertyhandler) to obtain a property handler for an item.

```cpp
// IShellItem *psi;
// Assume variable psi is valid and initialized.
IPropertyStore *pStore;

HRESULT hr = PSGetItemPropertyHandler(psi, FALSE, IID_PPV_ARGS(&pStore));

if (SUCCEEDED(hr))
{
    // pStore is now valid and contains properties exposed through the
    // property handler for the item.

    pStore->Release();
}
```