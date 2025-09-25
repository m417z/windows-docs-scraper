# IWriteEngine2::get_WriteInProgress

## Description

Retrieves a value that indicates whether the recorder is currently writing data to the disc.

## Parameters

### `value` [out]

If VARIANT_TRUE, the recorder is currently writing data to the disc. Otherwise, if VARIANT_FALSE, the recorder is not currently writing to disc.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IWriteEngine2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iwriteengine2)

[IWriteEngine2::CancelWrite](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-cancelwrite)

[IWriteEngine2::WriteSection](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-writesection)