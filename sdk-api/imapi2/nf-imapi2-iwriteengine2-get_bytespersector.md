# IWriteEngine2::get_BytesPerSector

## Description

Retrieves the number of bytes to use for each sector during writing. The returned value indicates what the value previously set with [IWriteEngine2::put_BytesPerSector](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-put_bytespersector), and does not return a current bytes per sector value for media.

## Parameters

### `value` [out]

Number of bytes to use for each sector during writing.

**Note** If [IWriteEngine2::put_BytesPerSector](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-put_bytespersector) has not been called, this parameter will indicate a value of '-1'.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IWriteEngine2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iwriteengine2)

[IWriteEngine2::get_EndingSectorsPerSecond](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-get_endingsectorspersecond)

[IWriteEngine2::get_StartingSectorsPerSecond](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-get_startingsectorspersecond)

[IWriteEngine2::put_BytesPerSector](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-put_bytespersector)

[IWriteEngine2::put_EndingSectorsPerSecond](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-put_endingsectorspersecond)

[IWriteEngine2::put_StartingSectorsPerSecond](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-put_startingsectorspersecond)