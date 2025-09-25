# ITLegacyCallMediaControl2::GatherDigits

## Description

The
**GatherDigits** method initiates the gathering of digits on the specified call. The application specifies the maximum number of digits to collect.

## Parameters

### `DigitMode` [in]

The digit mode(s) to monitor. This parameter specifies one or more of the
[LINEDIGITMODE](https://learn.microsoft.com/windows/desktop/Tapi/linedigitmode--constants) constants.

### `lNumDigits` [in]

The number of digits to collect.

If this parameter is zero, the method cancels any digit-gathering in progress, without starting a new digit-gathering attempt. For more information, see the following Remarks section.

### `pTerminationDigits` [in]

Pointer to a **BSTR** representation of the termination digits. If one of the termination digits in the string is detected, that digit is appended to the buffer, digit collection is terminated, and the **TE_GATHERDIGITS** event is sent to the application.

### `lFirstDigitTimeout` [in]

The length of time, in milliseconds, during which the first digit is expected. If the first digit is not received in this timeframe, digit collection is aborted and a **TE_GATHERDIGITS** event is sent to the application. The buffer contains only the **NULL** character, indicating that no digits were received and that the first-digit-timeout terminated digit-gathering. The minimum and maximum timeouts you can specify are found in the AC_GATHERDIGITSMINTIMEOUT and AC_GATHERDIGITSMAXTIMEOUT capabilities.

### `lInterDigitTimeout` [in]

The maximum time, in milliseconds, between consecutive digits. If the next digit is not received in this timeframe, digit collection is aborted and a **TE_GATHERDIGITS** event is sent to the application. The buffer contains only the digits collected up to this point followed by a **NULL** character, indicating that an interdigit-timeout terminated the digit-gathering. The minimum and maximum timeouts that can be specified are found in the AC_GATHERDIGITSMINTIMEOUT and AC_GATHERDIGITSMAXTIMEOUT capabilities.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pTerminationDigits* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | There is not enough memory to allocate the gather digits buffer. |
| **TAPI_E_INVALCALLSTATE** | The call must be in the *connected* state. |

## Remarks

The
**GatherDigits** method translates to a call to the TAPI 2.*x*
[lineGatherDigits](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegatherdigits) function.

Only one
**GatherDigits** call can be outstanding on a call. If you call
**GatherDigits** again, before the **TE_GATHERDIGITS** event has occurred, the second call cancels the previous gathering of digits. Canceled digit-gathering attempts send a **TE_GATHERDIGITS** event with the digits collected so far.

## See also

[ITLegacyCallMediaControl2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacycallmediacontrol2)