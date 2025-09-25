# IPortableDeviceResources::GetStream

## Description

The **GetStream** method gets an **IStream** interface with which to read or write the content data in an object on a device. The retrieved interface enables you to read from or write to the object data.

## Parameters

### `pszObjectID` [in]

Pointer to a null-terminated string that contains the object ID of the object.

### `Key` [in]

A **REFPROPERTYKEY** that specifies which resource to read. You can retrieve the keys of all the object's resources by calling [GetSupportedResources](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledeviceresources-getsupportedresources).

### `dwMode` [in]

One of the following access modes:

* STGM_READ (Read-only access.)
* STGM_WRITE (Write-only access.)
* STGM_READWRITE (Read/write access.)

### `pdwOptimalBufferSize` [in, out]

An optional pointer to a **DWORD** that specifies an estimate of the best buffer size to use when reading or writing data by using *ppStream*. A driver is required to support this value.

### `ppStream` [out]

Pointer to an **IStream** interface pointer. This interface is used to read and write data to the object. The caller must release this interface when it is done with it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | At least one of the required pointer arguments was **NULL**. |

## Remarks

The retrieved stream cannot read the contents of a folder recursively. To copy all the resources in an object, specify **WPD_RESOURCE_DEFAULT** for *Key*.

If the object does not support resources, this method will return an error, and *ppStream* will be **NULL**.

Applications should use the buffer size returned by *pdwOptimalBufferSize* when allocating the buffer for read or write operations.

## See also

[IPortableDeviceResources Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceresources)