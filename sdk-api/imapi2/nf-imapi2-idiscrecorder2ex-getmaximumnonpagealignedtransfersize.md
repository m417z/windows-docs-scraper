# IDiscRecorder2Ex::GetMaximumNonPageAlignedTransferSize

## Description

Retrieves the maximum non-page-aligned transfer size for the device.

## Parameters

### `value` [out]

Maximum size, in bytes, of a non-page-aligned buffer.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_FAIL** | Unspecified failure.<br><br>Value: 0x80004005 |

## Remarks

This is the maximum buffer size that a device can accept for a single command. Buffers of this size provide the maximum exchange of data. The buffer does not need to begin on a physical memory page boundary.

## See also

[IDiscRecorder2Ex](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscrecorder2ex)

[IDiscRecorder2Ex::GetMaximumPageAlignedTransferSize](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2ex-getmaximumpagealignedtransfersize)