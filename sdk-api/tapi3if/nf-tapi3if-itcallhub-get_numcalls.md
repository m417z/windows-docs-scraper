# ITCallHub::get_NumCalls

## Description

The
**get_NumCalls** method gets the number of calls currently in the CallHub.

## Parameters

### `plCalls` [out]

Total number of calls in the CallHub.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *plCalls* parameter is not a valid pointer. |

## See also

[CallHub Object](https://learn.microsoft.com/windows/desktop/Tapi/callhub-object)

[ITCallHub](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallhub)