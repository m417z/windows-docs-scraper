# ITCallHub::Clear

## Description

The
**Clear** method attempts to remove all calls and participants from CallHub. The application may not have the privileges required to disconnect every call.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[CallHub Object](https://learn.microsoft.com/windows/desktop/Tapi/callhub-object)

[ITCallHub](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallhub)