# IWriteEngine2::get_EndingSectorsPerSecond

## Description

Retrieves the estimated number of sectors per second that the recording device can write to the media at the end of the writing process.

## Parameters

### `value` [out]

Approximate number of sectors per second that the recording device can write to the media at the end of the writing process.

A value of -1 indicates maximum speed.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IWriteEngine2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iwriteengine2)

[IWriteEngine2::get_BytesPerSector](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-get_bytespersector)

[IWriteEngine2::get_StartingSectorsPerSecond](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-get_startingsectorspersecond)

[IWriteEngine2::put_BytesPerSector](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-put_bytespersector)

[IWriteEngine2::put_EndingSectorsPerSecond](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-put_endingsectorspersecond)

[IWriteEngine2::put_StartingSectorsPerSecond](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-put_startingsectorspersecond)