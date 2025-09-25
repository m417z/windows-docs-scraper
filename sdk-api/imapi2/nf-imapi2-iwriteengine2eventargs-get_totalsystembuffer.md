# IWriteEngine2EventArgs::get_TotalSystemBuffer

## Description

Retrieves the size of the internal data buffer that is used for writing to disc.

## Parameters

### `value` [out]

Size, in bytes, of the internal data buffer that is used for writing to disc.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IWriteEngine2EventArgs](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iwriteengine2eventargs)

[IWriteEngine2EventArgs::get_FreeSystemBuffer](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2eventargs-get_freesystembuffer)

[IWriteEngine2EventArgs::get_UsedSystemBuffer](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2eventargs-get_usedsystembuffer)