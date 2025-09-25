# IWpdSerializer::WriteIPortableDeviceValuesToBuffer

## Description

Serializes an **IPortableDeviceValues** interface to a caller-allocated byte array.

## Parameters

### `dwOutputBufferLength` [in]

**DWORD** that specifies the size of *pBuffer*, in bytes.

### `pResults` [in]

Pointer to an [IPortableDeviceValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues) interface to serialize.

### `pBuffer` [out]

Pointer to a caller-allocated buffer. To learn the size of the required buffer, call **GetSerializedSize**.

### `pdwBytesWritten` [out]

Pointer to a **DWORD** that indicates the number of bytes that were actually written to the caller-allocated buffer.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A required pointer argument was **NULL**. |
| **E_OUTOFMEMORY** | The caller-provided buffer was not big enough. |

## Remarks

This method copies an **IPortableDeviceValues** interface into an existing buffer. If you want to allocate a new buffer, use [GetBufferFromIPortableDeviceValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nf-portabledevicetypes-iwpdserializer-getbufferfromiportabledevicevalues).

## See also

[IWpdSerializer Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iwpdserializer)