# IWriteEngine2::put_UseStreamingWrite12

## Description

Sets a value that indicates if the write operations use the WRITE12 or WRITE10 command.

## Parameters

### `value` [in]

Set to VARIANT_TRUE to use the WRITE12 command with the streaming bit set to one when writing to disc. Otherwise, set VARIANT_FALSE to use the WRITE10 command. The default is VARIANT_FALSE.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | Setting this property to VARIANT_TRUE is currently not supported.<br><br>Value: 0x80004001 |
| **E_FAIL** | Unspecified failure.<br><br>Value: 0x80004005 |

## See also

[IWriteEngine2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iwriteengine2)

[IWriteEngine2::WriteSection](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-writesection)

[IWriteEngine2::get_UseStreamingWrite12](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-get_usestreamingwrite12)