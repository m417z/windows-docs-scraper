# RoSetErrorReportingFlags function

## Description

Sets the reporting behavior of Windows Runtime error functions.

## Parameters

### `flags` [in]

Type: **UINT32**

A bitmask of [RO_ERROR_REPORTING_FLAGS](https://learn.microsoft.com/windows/desktop/api/roerrorapi/ne-roerrorapi-roerrorreportingflags) values.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The error-reporting behavior was set successfully. |
| **E_INVALIDARG** | *flags* has invalid or undefined bits set. |

## Remarks

Get the current reporting behavior of Windows Runtime error functions by calling the [RoGetErrorReportingFlags](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rogeterrorreportingflags) function.

## See also

[RO_ERROR_REPORTING_FLAGS](https://learn.microsoft.com/windows/desktop/api/roerrorapi/ne-roerrorapi-roerrorreportingflags)

[RoGetErrorReportingFlags](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rogeterrorreportingflags)

[RoOriginateError](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rooriginateerror)

[RoSetErrorReportingFlags](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-roseterrorreportingflags)

[RoTransformError](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rotransformerror)