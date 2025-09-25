# IWriteEngine2EventArgs::get_LastWrittenLba

## Description

Retrieves the address of the sector most recently written to the device.

## Parameters

### `value` [out]

Logical block address of the sector most recently written to the device.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IWriteEngine2EventArgs](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iwriteengine2eventargs)

[IWriteEngine2EventArgs::get_LastReadLba](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2eventargs-get_lastreadlba)

[IWriteEngine2EventArgs::get_StartLba](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2eventargs-get_startlba)