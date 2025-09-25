# LINEMESSAGE structure

## Description

The
**LINEMESSAGE** structure contains parameter values specifying a change in status of the line the application currently has open. The
[lineGetMessage](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetmessage) function returns the
**LINEMESSAGE** structure.

## Members

### `hDevice`

Handle to either a line device or a call. The nature of this handle (line handle or call handle) can be determined by the context provided by *dwMessageID*.

### `dwMessageID`

Line or call device message.

### `dwCallbackInstance`

Instance data passed back to the application, which was specified by the application in the *dwCallBackInstance* parameter of
[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa). This **DWORD** is not interpreted by TAPI.

### `dwParam1`

Parameter for the message.

### `dwParam2`

Parameter for the message.

### `dwParam3`

Parameter for the message.

## Remarks

For information about parameter values passed in this structure, see
[Line Device Messages](https://learn.microsoft.com/windows/desktop/Tapi/line-device-messages).

## See also

[lineGetMessage](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetmessage)

[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa)