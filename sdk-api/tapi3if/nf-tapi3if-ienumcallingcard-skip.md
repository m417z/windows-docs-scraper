# IEnumCallingCard::Skip

## Description

The
**Skip** method skips over the next specified number of elements in the enumeration sequence. This method is hidden from Visual Basic and scripting languages.

## Parameters

### `celt` [in]

Number of elements to skip.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Number of elements skipped was *celt*. |
| **S_FALSE** | Number of elements skipped was not *celt*. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[Terminal Object](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object)