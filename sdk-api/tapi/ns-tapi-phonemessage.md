# PHONEMESSAGE structure

## Description

The
**PHONEMESSAGE** structure contains the next message queued for delivery to the application. The
[phoneGetMessage](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetmessage) function returns this structure.

## Members

### `hDevice`

Handle to a phone device.

### `dwMessageID`

Phone message.

### `dwCallbackInstance`

Instance data passed back to the application, which was specified by the application in
[phoneInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneinitializeexa). This value is not interpreted by TAPI.

### `dwParam1`

Parameter for the message.

### `dwParam2`

Parameter for the message.

### `dwParam3`

Parameter for the message.

## Remarks

For information about parameter values passed in this structure, see
[Phone Device Messages](https://learn.microsoft.com/windows/desktop/Tapi/phone-device-messages).

## See also

[phoneGetMessage](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetmessage)

[phoneInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneinitializeexa)