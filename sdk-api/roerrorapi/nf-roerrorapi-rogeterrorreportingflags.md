# RoGetErrorReportingFlags function

## Description

Gets the current reporting behavior of Windows Runtime error functions.

## Parameters

### `pflags` [out]

Type: **UINT32***

A pointer to the bitmask of [RO_ERROR_REPORTING_FLAGS](https://learn.microsoft.com/windows/desktop/api/roerrorapi/ne-roerrorapi-roerrorreportingflags) values that represents the current error-reporting behavior.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The error-reporting behavior was retrieved successfully. |
| **E_POINTER** | *pflags* is **NULL**. |

## Remarks

Set the reporting behavior of Windows Runtime error functions by calling the [RoSetErrorReportingFlags](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-roseterrorreportingflags) function.

## See also

[RO_ERROR_REPORTING_FLAGS](https://learn.microsoft.com/windows/desktop/api/roerrorapi/ne-roerrorapi-roerrorreportingflags)

[RoOriginateError](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rooriginateerror)

[RoSetErrorReportingFlags](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-roseterrorreportingflags)

[RoTransformError](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rotransformerror)