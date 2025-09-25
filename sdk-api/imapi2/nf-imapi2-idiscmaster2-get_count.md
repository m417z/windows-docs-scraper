# IDiscMaster2::get_Count

## Description

Retrieves the number of the CD and DVD disc devices installed on the computer.

## Parameters

### `value` [out]

Number of CD and DVD disc devices installed on the computer.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |
| **E_FAIL** | Unspecified failure.<br><br>Value: 0x80004005 |

## See also

[IDiscMaster2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscmaster2)

[IDiscMaster2::get_Item](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscmaster2-get_item)

[IDiscMaster::__NewEnum](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscmaster2-get__newenum)