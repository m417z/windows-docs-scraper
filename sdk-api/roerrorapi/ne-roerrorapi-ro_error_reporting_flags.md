# RO_ERROR_REPORTING_FLAGS enumeration

## Description

Specifies the behavior of the [RoOriginateError](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rooriginateerror) and [RoTransformError](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rotransformerror) functions.

## Constants

### `RO_ERROR_REPORTING_NONE:0x00000000`

Error functions raise structured exceptions when a debugger is attached.

### `RO_ERROR_REPORTING_SUPPRESSEXCEPTIONS:0x00000001`

Error functions do not raise structured exceptions, even when a debugger is present. Override the behavior of this flag by setting the **ForceExceptions** flag.

### `RO_ERROR_REPORTING_FORCEEXCEPTIONS:0x00000002`

Error functions raise structured exceptions, even if no debugger is present. This flag supercedes the **RO_ERROR_REPORTING_SUPPRESSEXCEPTIONS** flag. If this flag is set, structured exceptions are raised even if the **RO_ERROR_REPORTING_SUPPRESSEXCEPTIONS** flag is set.

### `RO_ERROR_REPORTING_USESETERRORINFO:0x00000004`

Error functions report error strings through a COM object that is attached to the COM channel through the [SetRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-setrestrictederrorinfo) infrastructure. For the **SetRestrictedErrorInfo** call to succeed, the thread must be initialized into COM.

### `RO_ERROR_REPORTING_SUPPRESSSETERRORINFO:0x00000008`

Error functions do not report error strings through a COM object that is attached to the COM channel through the [SetRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-setrestrictederrorinfo) infrastructure.

## Remarks

Use the **RO_ERROR_REPORTING_FLAGS** enumeration with the [RoSetErrorReportingFlags](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-roseterrorreportingflags) function to specify the behavior of the [RoOriginateError](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rooriginateerror), [RoOriginateErrorW](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rooriginateerrorw), [RoTransformError](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rotransformerror), and [RoTransformErrorW](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rotransformerrorw) functions.

## See also

[RoGetErrorReportingFlags](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rogeterrorreportingflags)

[RoOriginateError](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rooriginateerror)

[RoOriginateErrorW](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rooriginateerrorw)

[RoSetErrorReportingFlags](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-roseterrorreportingflags)

[RoTransformError](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rotransformerror)

[RoTransformErrorW](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rotransformerrorw)

[SetRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-setrestrictederrorinfo)