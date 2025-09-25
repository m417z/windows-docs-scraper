# IWriteEngine2::put_BytesPerSector

## Description

Sets the number of bytes to use for each sector during writing.

## Parameters

### `value` [in]

Number of bytes to use for each sector during writing. The minimum size is 1 byte and the maximum is MAXLONG bytes. Typically, this value is 2,048 bytes for CD media, although any arbitrary size is supported (such as 2352 or 2448). This value is limited to the [IDiscRecorder2Ex::GetMaximumPageAlignedTransferSize](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2ex-getmaximumpagealignedtransfersize), which is typically 65,536 (64K) bytes.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_FAIL** | Unspecified failure.<br><br>Value: 0x80004005 |
| **E_INVALIDARG** | One or more arguments are not valid.<br><br>Value: 0x80070057 |

## Remarks

You must specify a logical block size.

## See also

[IWriteEngine2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iwriteengine2)

[IWriteEngine2::get_BytesPerSector](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-get_bytespersector)

[IWriteEngine2::get_EndingSectorsPerSecond](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-get_endingsectorspersecond)

[IWriteEngine2::get_StartingSectorsPerSecond](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-get_startingsectorspersecond)

[IWriteEngine2::put_EndingSectorsPerSecond](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-put_endingsectorspersecond)

[IWriteEngine2::put_StartingSectorsPerSecond](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-put_startingsectorspersecond)