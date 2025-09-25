# IDiscRecorder2Ex::GetMaximumPageAlignedTransferSize

## Description

Retrieves the maximum page-aligned transfer size for the device.

## Parameters

### `value` [out]

Maximum size, in bytes, of a page-aligned buffer.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_FAIL** | Unspecified failure.<br><br>Value: 0x80004005 |

## Remarks

Maximum page-aligned buffer size that a device can accept for a single command. The buffer for this transfer size must begin on a physical memory page boundary.

## See also

[IDiscRecorder2Ex](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscrecorder2ex)

[IDiscRecorder2Ex::GetMaximumNonPageAlignedTransferSize](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2ex-getmaximumnonpagealignedtransfersize)