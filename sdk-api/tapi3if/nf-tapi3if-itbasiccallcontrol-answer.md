# ITBasicCallControl::Answer

## Description

The
**Answer** method answers an incoming call. This method can succeed only if the
[call state](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_state) is CS_OFFERING.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_UNEXPECTED** | Call state was not CS_OFFERING. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## See also

[Answer Overview](https://learn.microsoft.com/windows/desktop/Tapi/answer-ovr)

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[ITBasicCallControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasiccallcontrol)

[lineAnswer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineanswer)