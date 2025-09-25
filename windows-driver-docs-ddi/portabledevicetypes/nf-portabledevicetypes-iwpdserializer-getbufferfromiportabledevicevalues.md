# IWpdSerializer::GetBufferFromIPortableDeviceValues

## Description

Serializes a submitted **IPortableDeviceValues** interface to an allocated byte array. The byte array returned is allocated for the caller and should be freed by the caller using **CoTaskMemFree**.

## Parameters

### `pSource` [in]

Pointer to an [IPortableDeviceValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues) interface to serialize.

### `ppBuffer` [out]

Pointer to a **BYTE*** that contains the serialized data. Windows Portable Devices allocates this memory; the caller must free it by calling **CoTaskMemFree**.

### `pdwBufferSize` [out]

Pointer to a **DWORD** that specifies the size of allocated buffer, in bytes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A required pointer argument was **NULL**. |
| **E_OUTOFMEMORY** | There was not enough memory available to create the buffer. |

## Remarks

None.

## See also

[IWpdSerializer Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iwpdserializer)