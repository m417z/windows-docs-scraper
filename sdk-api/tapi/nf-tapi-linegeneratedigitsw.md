# lineGenerateDigitsW function

## Description

The
**lineGenerateDigits** function initiates the generation of the specified digits on the specified call as inband tones using the specified signaling mode. Calling this function with a **NULL** value for *lpszDigits* aborts any digit generation currently in progress. Invoking
**lineGenerateDigits** or
[lineGenerateTone](https://learn.microsoft.com/windows/win32/api/tapi/nf-tapi-linegeneratetone) while digit generation is in progress aborts the current digit generation or tone generation and initiates the generation of the most recently specified digits or tone.

## Parameters

### `hCall`

Handle to the call. The application must be an owner of the call. Call state of *hCall* can be any state. TAPI does not impose any callstate requirements, however some Tapi Service Providers may require that the hCall be in the LINECALLSTATE_CONNECTED state.

### `dwDigitMode`

Format to be used for signaling these digits. Be aware that *dwDigitMode* can only have a single flag set. This parameter uses one of the
[LINEDIGITMODE_ Constants](https://learn.microsoft.com/windows/win32/Tapi/linedigitmode--constants).

### `lpszDigits`

Pointer to a **null**-terminated character buffer that contains the digits to be generated. Valid characters are those specified for the
[LINEDIGITMODE_ Constants](https://learn.microsoft.com/windows/win32/Tapi/linedigitmode--constants) provided in *dwDigitModes*.

In addition, the comma (,) is also a valid character. A comma injects an extra delay between the signaling of the previous and next digits it separates. The duration of this pause is configuration defined, and the line device capabilities indicate this duration. Multiple commas can be used to inject longer pauses. Invalid digits are ignored during the generation, rather than being reported as errors.

The exclamation (!) is a valid character. This character causes a "hookflash" operation, as described for [dialable addresses](https://learn.microsoft.com/windows/win32/tapi/address-ovr).

### `dwDuration`

Both the duration in milliseconds of DTMF digits and pulse and DTMF inter-digit spacing. A value of 0 uses a default value. The *dwDuration* parameter must be within the range specified by **MinDialParams** and **MaxDialParams** in
[LINEDEVCAPS](https://learn.microsoft.com/windows/win32/api/tapi/ns-tapi-linedevcaps). If out of range, the actual value is set to the nearest value in the range.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INVALCALLHANDLE, LINEERR_NOTOWNER, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALDIGITMODE, LINEERR_OPERATIONFAILED, LINEERR_INVALPOINTER, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM, LINEERR_UNINITIALIZED.

## Remarks

The
**lineGenerateDigits** function is considered to have completed successfully when the digit generation has been successfully initiated, not when all digits have been generated. In contrast to
[lineDial](https://learn.microsoft.com/windows/win32/api/tapi/nf-tapi-linedial), which dials digits in a network-dependent fashion,
**lineGenerateDigits** guarantees to produce the digits as inband tones over the voice channel using DTMF or hookswitch dial pulses when using pulse. The
**lineGenerateDigits** function is generally not suitable for making calls or dialing. It is intended for end-to-end signaling over an established call.

After all digits in *lpszDigits* have been generated, or after digit generation has been aborted or canceled, a
[LINE_GENERATE](https://learn.microsoft.com/windows/win32/Tapi/line-generate) message is sent to the application.

Only one inband generation request (tone generation or digit generation) is allowed to be in progress per call across all applications that are owners of the call. Digit generation on a call is canceled by initiating either another digit generation request or a tone generation request. To cancel the current digit generation, the application can invoke
**lineGenerateDigits** and specify **NULL** for the *lpszDigits* parameter.

Depending on the service provider and hardware, the application can monitor the digits it generates itself. If that is not desired, the application can disable digit monitoring while generating digits.

> [!NOTE]
> The tapi.h header defines lineGenerateDigits as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[LINEDEVCAPS](https://learn.microsoft.com/windows/win32/api/tapi/ns-tapi-linedevcaps)

[LINE_GENERATE](https://learn.microsoft.com/windows/win32/Tapi/line-generate)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/win32/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/win32/Tapi/tapi-2-2-reference)

[lineDial](https://learn.microsoft.com/windows/win32/api/tapi/nf-tapi-linedial)

[lineGenerateTone](https://learn.microsoft.com/windows/win32/api/tapi/nf-tapi-linegeneratetone)