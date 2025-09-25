# PSGetItemPropertyHandlerWithCreateObject function

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

### `punkCreateObject` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

Pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of a class factory object that supports [ICreateObject](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-icreateobject).

### `riid` [in]

Type: **REFIID**

A reference to the IID of the interface to retrieve through *ppv*.

### `ppv` [out]

Type: **void****

When this function returns successfully, contains the interface pointer requested in *riid*. This is typically [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) or [IPropertyStoreCapabilities](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystorecapabilities).

## Return value

Type: **PSSTDAPI**

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

This function is supported in Windows XP as part of the Microsoft Windows Desktop Search (WDS) redistributable which includes [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) and supporting interfaces. For applications supported only on Windows Vista or later, we recommend that you use [IShellItem2::GetPropertyStoreWithCreateObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem2-getpropertystorewithcreateobject) instead of [PSGetItemPropertyHandlerWithCreateObject](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetitempropertyhandlerwithcreateobject) because **IShellItem2::GetPropertyStoreWithCreateObject** provides a richer set of properties in the property store that is returned.

This function is approximately equivalent to passing the GPS_HANDLERPROPERTIESONLY flag to [IShellItem2::GetPropertyStoreWithCreateObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem2-getpropertystorewithcreateobject).

The *punkCreateObject* parameter enables the creation of a property store in a different context than that of the caller. For instance, the [ICreateObject](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-icreateobject) implementation can cause the property store to be created in another process. This parameter is used only for property handlers that support it and that are registered under `HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\PropertySystem\PropertyHandlers`.

You must initialize Component Object Model (COM) with [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) or [OleInitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize) before you call [PSGetItemPropertyHandlerWithCreateObject](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetitempropertyhandlerwithcreateobject). COM must remain initialized for the lifetime of this object.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PSGetItemPropertyHandlerWithCreateObject](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetitempropertyhandlerwithcreateobject) to obtain a property handler for an item.

```cpp
// IShellItem *psi;
// ICreateObject *pco;
// Assume variables pco and psi are valid and initialized.
IPropertyStore *pStore;

HRESULT hr = PSGetItemPropertyHandlerWithCreateObject(psi, FALSE, pco, IID_PPV_ARGS(&pStore));

if (SUCCEEDED(hr))
{
    // pStore is now valid and contains properties exposed through the
    // property handler for the item.

    pStore->Release();
}
```

## See also

[IShellItem2::GetPropertyStoreWithCreateObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem2-getpropertystorewithcreateobject)

[Initializing Property Handlers](https://learn.microsoft.com/windows/desktop/properties/building-property-handlers-property-handlers)