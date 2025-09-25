# ITBasicCallControl::Disconnect

## Description

The
**Disconnect** method disconnects the call. The
[call state](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_state) will transition to CS_DISCONNECTED after the method completes successfully.

## Parameters

### `code` [in]

[DISCONNECT_CODE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-disconnect_code) indicating reason for call disconnection.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **S_FALSE** | The call state is CS_IDLE or a valid handle for the call could not be obtained by the TAPI 3 DLL. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## See also

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[DISCONNECT_CODE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-disconnect_code)

[Drop overview](https://learn.microsoft.com/windows/desktop/Tapi/drop-ovr)

[ITBasicCallControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasiccallcontrol)

[Terminate a Session Overview](https://learn.microsoft.com/windows/desktop/Tapi/terminate-a-session-ovr)

[lineDrop](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedrop)