# IDiscRecorder2Ex::GetDeviceDescriptor

## Description

Retrieves the device descriptor for the device.

## Parameters

### `data` [out]

Data buffer that contains the descriptor of the storage device. For details of the contents of the data buffer, see the **STORAGE_DEVICE_DESCRIPTOR** structure in the DDK

When done, call the **CoTaskMemFree** function to free the memory.

### `byteSize` [out]

Size, in bytes, of the data buffer.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_FAIL** | Unspecified failure.<br><br>Value: 0x80004005 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |

## See also

[IDiscRecorder2Ex](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscrecorder2ex)