# IProgressItems::get_Count

## Description

Retrieves the number of progress items in the collection.

## Parameters

### `Count` [out]

Number of progress items in the collection.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IProgressItems](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-iprogressitems)