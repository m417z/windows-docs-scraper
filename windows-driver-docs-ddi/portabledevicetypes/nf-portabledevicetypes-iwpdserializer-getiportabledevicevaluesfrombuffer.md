# IWpdSerializer::GetIPortableDeviceValuesFromBuffer

## Description

Deserializes a byte array to an **IPortableDeviceValues** interface.

## Parameters

### `pBuffer` [in]

Pointer to the buffer to deserialize.

### `dwInputBufferLength` [in]

**DWORD** that specifies the size of the buffer, in bytes.

### `ppParams` [out]

Address of a variable that receives a pointer to an [IPortableDeviceValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues) interface created from the buffer. The application is responsible for calling **Release** on the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A required pointer argument was **NULL**. |
| **E_UNEXPECTED** | An unspecified conversion error occurred. |

## Remarks

None.

## See also

[IWpdSerializer Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iwpdserializer)