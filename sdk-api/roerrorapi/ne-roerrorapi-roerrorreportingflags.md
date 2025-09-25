# RoErrorReportingFlags

## Description

Specifies the behavior of the [RoOriginateError](https://learn.microsoft.com/windows/win32/api/roerrorapi/nf-roerrorapi-rooriginateerror) and [RoTransformError](https://learn.microsoft.com/windows/win32/api/roerrorapi/nf-roerrorapi-rotransformerror) functions.

## Constants

### `None`

Error functions raise structured exceptions.

### `SuppressExceptions`

Error functions do not raise structured exceptions, even when a debugger is present.
Override the behavior of this flag by setting the *ForceExceptions* flag.

### `ForceExceptions`

Error functions raise structured exceptions, even if no debugger is present.
This flag supercedes the *SuppressExceptions* flag.
If this flag is set, structured exceptions are raised even if the *SuppressExceptions* flag is set.

### `UseSetErrorInfo`

Error functions report error strings through a COM object that is attached to the COM channel through the **SetErrorInfo** infrastructure.
This flag requires that the calling thread be initialized into COM.

### `SuppressSetErrorInfo`

Error functions do not report error strings through a COM object that is attached to the COM channel through the **SetErrorInfo** infrastructure.

## Remarks

## See also

[RoGetErrorReportingFlags](https://learn.microsoft.com/windows/win32/api/roerrorapi/nf-roerrorapi-rogeterrorreportingflags)

[RoSetErrorReportingFlags](https://learn.microsoft.com/windows/win32/api/roerrorapi/nf-roerrorapi-roseterrorreportingflags)

[RoOriginateError](https://learn.microsoft.com/windows/win32/api/roerrorapi/nf-roerrorapi-rooriginateerror)

[RoTransformError](https://learn.microsoft.com/windows/win32/api/roerrorapi/nf-roerrorapi-rotransformerror)