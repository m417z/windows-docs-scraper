# DISCONNECT_CODE enumeration

## Description

The
**DISCONNECT_CODE** enum is used by the
[ITBasicCallControl::Disconnect](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-disconnect) method.

## Constants

### `DC_NORMAL:0`

The call is being disconnected as part of the normal cycle of the call.

### `DC_NOANSWER`

The call is being disconnected because it has not been answered. (For example, an application may set a certain amount of time for the user to answer the call. If the user does not answer, the application can call
[Disconnect](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-disconnect) with the NOANSWER code.)

### `DC_REJECTED`

The user rejected the offered call.

## See also

[ITBasicCallControl::Disconnect](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-disconnect)