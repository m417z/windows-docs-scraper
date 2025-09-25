# PHONECALLBACK callback function

## Description

The
**phoneCallback** function is a placeholder for the application-supplied function name.

## Parameters

### `hDevice`

Handle to a phone device associated with the callback.

### `dwMessage`

### `dwInstance`

### `dwParam1`

Parameter for the message.

### `dwParam2`

Parameter for the message.

### `dwParam3`

Parameter for the message.

#### - dwCallbackInstance

Callback instance data passed back to the application in the callback. This **DWORD** is not interpreted by TAPI.

#### - dwMsg

Line or call device message.

## Remarks

For more information about the parameters passed to this callback function, see
[TAPI Messages](https://learn.microsoft.com/windows/desktop/Tapi/tapi-messages).

All callbacks occur in the application's context. The callback function must reside in a dynamic-link library (DLL) or application module and be exported in the module-definition file.