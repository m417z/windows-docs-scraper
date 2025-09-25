# IWpdSerializer::GetSerializedSize

## Description

Calculates the buffer size that is required to hold a serialized **IPortableDeviceValues** interface.

## Parameters

### `pSource` [in]

Pointer to an [IPortableDeviceValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues) interface whose size you want to request.

### `pdwSize` [out]

Pointer to a **DWORD** that indicates the buffer size that is required to serialize *pSource*, in bytes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A required pointer argument was **NULL**. |
| **E_OUTOFMEMORY** | There was not enough available memory to create the buffer. |

## Remarks

None.

## See also

[IWpdSerializer Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iwpdserializer)