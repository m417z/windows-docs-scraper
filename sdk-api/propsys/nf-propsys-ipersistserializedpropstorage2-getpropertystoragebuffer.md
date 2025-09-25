# IPersistSerializedPropStorage2::GetPropertyStorageBuffer

## Description

Gets the serialized property storage buffer from the property store instance.

## Parameters

### `psps` [out]

Type: **SERIALIZEDPROPSTORAGE***

When this method returns successfully, contains the contents of the property storage buffer.

### `cb` [in]

Type: **DWORD**

The initial size, in bytes, of the buffer pointed to by *psps*

### `pcbWritten` [out]

Type: **DWORD***

The count of bytes contained in the serialized property storage buffer pointed to by *psps*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This methods returns an error if *cb* is smaller than the total size of the serialized data.

The **SERIALIZEDPROPSTORAGE** type is defined in Propsys.h as an incomplete type. It should be treated as an array of **BYTE** values; the format of the returned data is not specified. The contents of the **SERIALIZEDPROPSTORAGE** structure are suitable for persisting to disk or other storage and can be used to initialize another property store through [IPersistSerializedPropStorage::SetPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipersistserializedpropstorage-setpropertystorage).