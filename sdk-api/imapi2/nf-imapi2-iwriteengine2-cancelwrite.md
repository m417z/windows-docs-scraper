# IWriteEngine2::CancelWrite

## Description

Cancels a write operation that is in progress.

## Return value

The following values are returned on success, but other success codes may be returned as a result of implementation: The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_IMAPI_WRITE_NOT_IN_PROGRESS** | The 'write' operation initiated by the last call to [IWriteEngine2::WriteSection](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-writesection) has not yet begun, and cannot be canceled. It is recommended to call [IWriteEngine2::CancelWrite](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-cancelwrite) until a different success code is returned.<br><br>Value: 0x00AA0302L |

The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_FAIL** | Unspecified failure.<br><br>Value: 0x80004005 |

## Remarks

To cancel the write operation, you must call this method from the [DWriteEngine2Events::Update](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-dwriteengine2events-update) event handler that you implemented.

## See also

[DWriteEngine2Events](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-dwriteengine2events)

[IWriteEngine2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iwriteengine2)

[IWriteEngine2::WriteSection](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-writesection)

[IWriteEngine2::get_WriteInProgress](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-get_writeinprogress)