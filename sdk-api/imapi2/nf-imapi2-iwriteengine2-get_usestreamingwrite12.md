# IWriteEngine2::get_UseStreamingWrite12

## Description

Retrieves a value that indicates if the write operations use the WRITE12 or WRITE10 command.

## Parameters

### `value` [out]

If VARIANT_TRUE, the write operations use the WRITE12 command with the streaming bit set to one. Otherwise, if VARIANT_FALSE, the write operations use the WRITE10 command.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IWriteEngine2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iwriteengine2)

[IWriteEngine2::WriteSection](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-writesection)

[IWriteEngine2::put_UseStreamingWrite12](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-put_usestreamingwrite12)