# IPersistSerializedPropStorage::GetPropertyStorage

## Description

Gets the serialized property storage data from the property store instance.

## Parameters

### `ppsps` [out]

Type: **SERIALIZEDPROPSTORAGE****

When this method returns, contains the address of a pointer to the serialized property storage data.

### `pcb` [out]

Type: **DWORD***

When this method returns, contains the count of bytes contained in the serialized property storage data pointed to by *ppsps*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **SERIALIZEDPROPSTORAGE** type is defined in Propsys.h as an incomplete type. It should be treated as an array of **BYTE** values; the format of the returned data is not specified. The contents of the **SERIALIZEDPROPSTORAGE** structure are suitable for persisting to disk or other storage and can be used to initialize another property store through [IPersistSerializedPropStorage::SetPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipersistserializedpropstorage-setpropertystorage).

**Note** It is the responsibility of the application that calls **IPersistSerializedPropStorage::GetPropertyStorage** to later call [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to release the memory referred to by *ppsps* when it is no longer needed.