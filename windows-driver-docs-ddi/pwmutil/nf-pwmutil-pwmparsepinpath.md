# PwmParsePinPath function

## Description

Parses a pin path under the Pulse Width Modulation (PWM) controller namespace to validate its format and extract the pin number.

## Parameters

### `PinPath` [in]

A pointer to pin path as a Unicode character string.

### `PinNumber` [out, optional]

A pointer to variable that receives a pin number.

## Return value

**PwmParsePinPath** returns the following values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | Extracted pin path successfully from supplied pin path. |
| **STATUS_INVALID_PARAMETER** | The specified pin path pointer is invalid or its Unicode string is invalid. |
| **STATUS_NO_SUCH_FILE** | The specified pin path does not constitute a valid pin path. |

## Remarks

The pin path must be a Unicode character string that ends in the pin number as follows: *...\<PinNumber>*.