# IWriteEngine2EventArgs::get_StartLba

## Description

Retrieves the starting logical block address (LBA) of the current write operation.

## Parameters

### `value` [out]

Starting logical block address of the write operation. Negative values for LBAs are supported.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## Remarks

This is the same value passed to the [IWriteEngine2::WriteSection](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-writesection) method.

## See also

[IWriteEngine2::WriteSection](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-writesection)

[IWriteEngine2EventArgs](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iwriteengine2eventargs)

[IWriteEngine2EventArgs::get_LastReadLba](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2eventargs-get_lastreadlba)

[IWriteEngine2EventArgs::get_LastWrittenLba](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2eventargs-get_lastwrittenlba)