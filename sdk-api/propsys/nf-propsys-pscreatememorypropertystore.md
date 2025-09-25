# PSCreateMemoryPropertyStore function

## Description

Creates an in-memory property store.

## Parameters

### `riid` [in]

Type: **REFIID**

Reference to the requested interface ID.

### `ppv` [out]

Type: **void****

When this function returns, contains a pointer to the desired interface, typically [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) or [IPersistSerializedPropStorage](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipersistserializedpropstorage).

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function creates an in-memory property store object that implements [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore), [INamedPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-inamedpropertystore), [IPropertyStoreCache](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystorecache), [IPersistStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststream), [IPropertyBag](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ipropertybag), and [IPersistSerializedPropStorage](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipersistserializedpropstorage).

This is the same object identified by `InMemoryPropertyStore` (`CLSID_InMemoryPropertyStore`) and `InMemoryPropertyStoreMarshalByValue` (`CLSID_InMemoryPropertyStoreMarshalByValue`), constructed with CoCreateInstance.

`InMemoryPropertyStoreMarshalByValue` can be used in designs that pass objects
between processes to make them more efficient. It implements [marshal by value](https://devblogs.microsoft.com/oldnewthing/20220617-41/?p=106760), creating a copy of the object in the
unmarshal context and avoids inter-process communication that can be expensive.

The memory property store has no presistent representation so calls to [IPropertyStore::Commit](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystore-commit) are a no-op.

The memory property store is thread safe and agile.

#### Examples

The following example demonstrates how to use `InMemoryPropertyStore`.

```cpp
auto memPropStore = wil::CoCreateInstance<InMemoryPropertyStore, IPropertyStore>();
auto value = PROPVARIANT{};
value.vt = VT_LPWSTR;
value.pwszVal = L"Title";
THROW_IF_FAILED(memPropStore->SetValue(PKEY_Title, value));
```

## See also

[PSCreateMultiplexPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pscreatemultiplexpropertystore)