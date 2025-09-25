# LINECALLBACK callback function

## Description

The
**lineCallback** function is a placeholder for the application-supplied function name.

## Parameters

### `hDevice`

Handle to either a line device or a call associated with the callback. The nature of this handle (line handle or call handle) can be determined by the context provided by *dwMsg*. Applications must use the **DWORD** type for this parameter because using the **HANDLE** type may generate an error.

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

For information about parameter values passed to this function, see
[Line Device Messages](https://learn.microsoft.com/windows/desktop/Tapi/line-device-messages).

All callbacks occur in the application's context. The callback function must reside in a DLL or application module.