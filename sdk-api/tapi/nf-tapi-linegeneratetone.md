# lineGenerateTone function

## Description

The
**lineGenerateTone** function generates the specified inband tone over the specified call. Invoking this function with a zero for *dwToneMode* aborts the tone generation currently in progress on the specified call. Invoking
**lineGenerateTone** or
[lineGenerateDigits](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegeneratedigits) while tone generation is in progress aborts the current tone generation or digit generation and initiates the generation of the newly specified tone or digits.

## Parameters

### `hCall`

Handle to the call on which a tone is to be generated. The application must be an owner of the call. The call state of *hCall* can be any state.

### `dwToneMode`

Defines the tone to be generated. Tones can be either standard or custom. A custom tone is composed of a set of arbitrary frequencies. A small number of standard tones are predefined. The duration of the tone is specified with *dwDuration* for both standard and custom tones. The *dwToneMode* parameter can only have one bit set. If no bits are set (the value 0 is passed), tone generation is canceled. This parameter uses one of the
[LINETONEMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linetonemode--constants).

### `dwDuration`

Duration in milliseconds during which the tone should be sustained. A value of 0 for *dwDuration* uses a default duration for the specified tone. Default values are:

CUSTOM: The tone is sustained until it is shut off, usually by user interaction or an equipment time-out.

RINGBACK: The tone is sustained until it is shut off, usually by user interaction or an equipment time-out.

BUSY: The tone is sustained until it is shut off, usually by user interaction or an equipment time-out.

BEEP: The tone is sustained until it is shut off, usually by user interaction or an equipment time-out.

BILLING: Fixed (single cycle).

### `dwNumTones`

Number of entries in the *lpTones* array. This parameter is ignored if *dwToneMode* is not equal to CUSTOM.

### `lpTones`

Pointer to a
[LINEGENERATETONE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linegeneratetone) array that specifies the tone's components. This parameter is ignored for standard
[LINETONEMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linetonemode--constants) tones such as LINETONEMODE_BUSY. If *lpTones* is a multifrequency tone, the various tones are played simultaneously.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INVALCALLHANDLE, LINEERR_NOTOWNER, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALPOINTER, LINEERR_OPERATIONFAILED, LINEERR_INVALTONEMODE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALTONE, LINEERR_UNINITIALIZED, LINEERR_NOMEM.

## Remarks

The
**lineGenerateTone** function is considered to have completed successfully when the tone generation has been successfully initiated, not when the generation of the tone is finished. The function allows the inband generation of several predefined tones, such as ringback, busy tones, and beep. It also allows for the fabrication of custom tones by specifying their component frequencies, cadence, and volume. Because these tones are generated as inband tones, the call would typically have to be in the *connected* state for tone generation to be effective. When the generation of the tone is complete, or when tone generation is canceled, a LINE_GENERATE message is sent to the application.

Only one inband generation request (tone generation or digit generation) is allowed to be in progress per call across all applications that are owners of the call. This implies that if tone generation is currently in progress on a call, invoking
[lineGenerateDigits](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegeneratedigits) cancels the tone generation.

If the LINEERR_INVALPOINTER error value is returned, the specified *lpTones* parameter is invalid or the value specified by the *dwNumTones* parameter is too large.

## See also

[LINEGENERATETONE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linegeneratetone)

[LINE_GENERATE](https://learn.microsoft.com/windows/desktop/Tapi/line-generate)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineGenerateDigits](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegeneratedigits)