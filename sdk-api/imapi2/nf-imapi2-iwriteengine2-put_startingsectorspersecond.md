# IWriteEngine2::put_StartingSectorsPerSecond

## Description

Sets the estimated number of sectors per second that the recording device can write to the media at the start of the writing process.

## Parameters

### `value` [in]

Approximate number of sectors per second that the recording device can write to the media at the start of the writing process. The default is -1 for maximum speed.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_FAIL** | Unspecified failure.<br><br>Value: 0x80004005 |
| **E_INVALIDARG** | One or more arguments are not valid.<br><br>Value: 0x80070057 |

## Remarks

This is used to optimize sleep time in the write engine.

## See also

[IWriteEngine2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iwriteengine2)

[IWriteEngine2::get_BytesPerSector](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-get_bytespersector)

[IWriteEngine2::get_EndingSectorsPerSecond](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-get_endingsectorspersecond)

[IWriteEngine2::get_StartingSectorsPerSecond](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-get_startingsectorspersecond)

[IWriteEngine2::put_BytesPerSector](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-put_bytespersector)

[IWriteEngine2::put_EndingSectorsPerSecond](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-put_endingsectorspersecond)