# MI_Context_WriteMessage function

## Description

Sends an operational message to the client.

## Parameters

### `context` [in]

Request context.

### `channel`

The channel to which to write. The client can select from one these channels:

#### MI_WRITEMESSAGE_CHANNEL_WARNING (0)

Channel used to broadcast warning messages.

#### MI_WRITEMESSAGE_CHANNEL_VERBOSE (1)

Channel used to broadcast verbose informational messages.

#### MI_WRITEMESSAGE_CHANNEL_DEBUG (2)

Channel used to broadcast debugging information.

### `message`

A null-terminated string that represents the message to be sent to the client. The message should be localized if it is a warning or verbose.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

A provider calls this function when an operational message needs to be sent to the client about something. An example of an operational message would be notifying the client as to which files have been deleted in a long running delete process so that the client can update the UI. Care should be taken not to overuse this function as it can slow down the progress of the provider. A client can optionally register to receive these messages via an asynchronous callback. If a client does not register for these messages, the server will ignore the message.

## See also

[MI_Context](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_context)