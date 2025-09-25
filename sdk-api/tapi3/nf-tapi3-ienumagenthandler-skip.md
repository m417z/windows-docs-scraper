# IEnumAgentHandler::Skip

## Description

The
**Skip** method skips over the next specified number of elements in the enumeration sequence.

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

[IEnumAgentHandler](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-ienumagenthandler)