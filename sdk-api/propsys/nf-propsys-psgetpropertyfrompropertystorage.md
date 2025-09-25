# PSGetPropertyFromPropertyStorage function

## Description

Gets the value of a property as stored in serialized property storage.

## Parameters

### `psps` [in]

Type: **PCUSERIALIZEDPROPSTORAGE**

Pointer to an allocated buffer that contains the serialized properties. This buffer is obtained by a call to [IPersistSerializedPropStorage::GetPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipersistserializedpropstorage-getpropertystorage).

### `cb` [in]

Type: **DWORD**

The size, in bytes, of the **USERIALIZESPROPSTORAGE** buffer pointed to by *psps*.

### `rpkey` [in]

Type: **REFPROPERTYKEY**

Reference to the [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) that identifies the property for which to get the value.

### `ppropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)****

When this function returns, contains the requested value.

## Return value

Type: **PSSTDAPI**

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

This function is intended to be called if the calling application already has a serialized property storage and needs no more than a few properties from storage. If many properties need to be retrieved, performance can be enhanced by creating a memory property store through [PSCreateMemoryPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pscreatememorypropertystore), initializing the property store by calling [IPersistSerializedPropStorage::SetPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipersistserializedpropstorage-setpropertystorage), and by using [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) to retrieve the properties.

Note that [PSGetPropertyFromPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetpropertyfrompropertystorage) works only on serialized buffers created by the system implementation of [IPersistSerializedPropStorage](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipersistserializedpropstorage). You must first obtain a memory property store by calling [PSCreateMemoryPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pscreatememorypropertystore). That store can then create a serialized buffer using the **IPersistSerializedPropStorage** interface.

Although SERIALIZEDPROPSTORAGE is an opaque serialized data structure whose format may change in the future, earlier formats will be supported on subsequent versions of Windows. Because the format is opaque, applications should use supported property storage APIs to access and manipulate the serialized buffer (see [IPersistSerializedPropStorage](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipersistserializedpropstorage)).

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PSGetPropertyFromPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetpropertyfrompropertystorage) to read a value from serialized property storage.

```cpp
// SERIALIZEDPROPSTORAGE *pStorage;
// DWORD cbStorage;
// Assume the variables pStorage and cbStorage are initialized and valid.
PROPVARIANT propvar;

HRESULT hr = PSGetPropertyFromPropertyStorage(pStorage, cb, PKEY_Rating, &propvar);

if (SUCCEEDED(hr))
{
    // propvar is now valid.

    PropVariantClear(&propvar);
}
```

## See also

[PSGetNamedPropertyFromPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetnamedpropertyfrompropertystorage)