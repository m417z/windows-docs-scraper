# IDiscRecorder2::get_ActiveDiscRecorder

## Description

Retrieves the unique identifier used to initialize the disc device.

## Parameters

### `value` [out]

Unique identifier for the device. This is the identifier you specified when calling [IDiscRecorder2::InitializeDiscRecorder](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2-initializediscrecorder).

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_FAIL** | Unspecified failure.<br><br>Value: 0x80004005 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |
| **E_INVALIDARG** | One or more arguments are not valid.<br><br>Value: 0x80070057 |

## See also

[IDiscRecorder2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscrecorder2)