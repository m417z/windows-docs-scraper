# TSPI_lineGenerateDigits function

## Description

The
**TSPI_lineGenerateDigits** function initiates the generation of the specified digits on the specified call as in-band tones using the specified signaling mode. Invoking this function while digit or tone generation is in progress aborts the current digit or tone generation. Passing a **NULL** value for *lpsDigits* generates no new digits.

**Note** Only one in-band generation request at a time (tone generation or digit generation) can be in progress per call.

## Parameters

### `hdCall`

The handle to the call on which digit generation is to be done.

### `dwEndToEndID`

This unique request identifier should be stored by the service provider and passed back as *dwParam2* to the
[LINEEVENT](https://learn.microsoft.com/windows/win32/api/tspi/nc-tspi-lineevent) procedure when the digit generation is completed.

### `dwDigitMode`

The format to be used for signaling these digits. This parameter uses one and only one of the
[LINEDIGITMODE_ constants](https://learn.microsoft.com/windows/win32/Tapi/linedigitmode--constants).

### `lpszDigits`

A pointer to a **null**-terminated Unicode character buffer that contains the digits to be generated. A comma injects an extra delay between the signaling of the previous and next digits it separates. The duration of this pause is configuration defined. The line's device capabilities indicate what this duration is. Multiple commas can be used to inject longer pauses. Invalid digits are ignored during the generation, rather than being reported as an error.

### `dwDuration`

Specifies both the duration in milliseconds of DTMF digits and pulse and DTMF inter-digit spacing. A value of 0 uses a default value. The *dwDuration* parameter must be within the range specified by **MinDialParams** to **MaxDialParams** in
[LINEDEVCAPS](https://learn.microsoft.com/windows/win32/api/tapi/ns-tapi-linedevcaps). If out of range, the actual value is set by the service provider to the nearest value in the range. This parameter is not validated by TAPI when this function is called.

## Return value

Returns zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_NOMEM, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALDIGITMODE, LINEERR_OPERATIONFAILED, LINEERR_RESOURCEUNAVAIL, LINEERR_RESOURCEUNAVAIL.

## Remarks

The call state of *hdCall* can be any state.

The
**TSPI_lineGenerateDigits** function is considered to have completed successfully when the digit generation is successfully initiated; not when all digits are generated.

After all digits in *lpsDigits* are generated, or after digit generation is aborted or canceled, a
[LINE_GENERATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725230(v=vs.85)) message is sent to TAPI.

**Note** Only one inband generation request (tone generation or digit generation) is allowed to be in progress per call. This implies that if digit generation is currently in progress on a call, invoking either
**TSPI_lineGenerateDigits** or
[TSPI_lineGenerateTone](https://learn.microsoft.com/windows/win32/api/tspi/nf-tspi-tspi_linegeneratetone) cancels the digit generation. The service provider must terminate any digit generation in progress when a subsequent
**TSPI_lineGenerateDigits** or
**TSPI_lineGenerateTone** is invoked. Invoking
**TSPI_lineGenerateDigits** with *lpszDigits* set to **NULL** cancels any current digit (or tone) generation.

The corresponding function at the TAPI level does not include the formal parameter *dwEndToEndID*. At that level, there is no end-to-end marking. TAPI uses end-to-end marking at the TSPI level to disambiguate one
**TSPI_lineGenerateDigits** request from another.

## See also

[LINEDEVCAPS](https://learn.microsoft.com/windows/win32/api/tapi/ns-tapi-linedevcaps)

[LINEDIGITMODE_ Constants](https://learn.microsoft.com/windows/win32/Tapi/linedigitmode--constants)

[LINEEVENT](https://learn.microsoft.com/windows/win32/api/tspi/nc-tspi-lineevent)

[LINE_GENERATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725230(v=vs.85))

[TSPI_lineGenerateTone](https://learn.microsoft.com/windows/win32/api/tspi/nf-tspi-tspi_linegeneratetone)