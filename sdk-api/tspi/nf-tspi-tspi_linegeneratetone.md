# TSPI_lineGenerateTone function

## Description

The
**TSPI_lineGenerateTone** function generates the specified tone inband over the specified call. Invoking this function with a zero for *dwToneMode* aborts any tone generation currently in progress on the specified call. Invoking
**TSPI_lineGenerateTone** or
[TSPI_lineGenerateDigits](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegeneratedigits) while tone generation is in progress aborts the current tone generation or digit generation in progress and initiates the generation of the newly specified tone or digits.

## Parameters

### `hdCall`

The service provider's handle to the call on which tone generation is to be performed. The call state of *hdCall* can be any state except *idle*.

### `dwEndToEndID`

A unique, uninterpreted identifier of the request for its entire lifetime, that is, until the matching
[LINE_GENERATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725230(v=vs.85)) message is sent. The service provider includes this identifier as one of the parameters in the message.

### `dwToneMode`

Defines the tone to be generated. Tones can be either standard or custom. A custom tone is composed of a set of arbitrary frequencies. A small number of standard tones are predefined. The duration of the tone is specified by **dwDuration** for both standard and custom tones. If *dwToneMode* is set to zero, any digit or tone generation in progress is canceled. This parameter uses one and only one of the
[LINETONEMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linetonemode--constants).

### `dwDuration`

The duration in milliseconds during which the tone is sustained. A value of 0 for *dwDuration* uses a default duration for the specified tone. Default values are:

CUSTOM: infinite

RINGBACK: infinite

BUSY: infinite

BEEP: infinite

BILLING: fixed (single cycle)

This parameter is not validated by TAPI when this function is called.

### `dwNumTones`

The number of entries in the *lpTones* array. This parameter is ignored if *dwToneMode* is not equal to LINETONEMODE_CUSTOM.

### `lpTones`

A pointer to a
[LINEGENERATETONE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linegeneratetone) array that specifies the tone's components. This parameter is ignored for noncustom tones. If *lpTones* is a multifrequency tone, the various tones are played simultaneously.

## Return value

Returns zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_NOMEM, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALTONEMODE, LINEERR_OPERATIONFAILED, LINEERR_INVALTONE, LINEERR_RESOURCEUNAVAIL, LINEERR_RESOURCEUNAVAIL.

## Remarks

**TSPI_lineGenerateTone** returns zero (success) when the tone generation is successfully initiated; not when the generation of the tone is finished. The function allows the inband generation of several predefined tones, such as ringback, busy tones, and beep. It also allows for the fabrication of custom tones by specifying their component frequencies, cadence and volume, if this is supported by the service provider. Because these tones are generated as inband tones, the call would typically have to be in the *connected* state for tone generation to be effective. When tone generation is complete, or when tone generation is canceled, a
[LINE_GENERATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725230(v=vs.85)) message is sent to TAPI.

**Note** Only one inband generation request (tone generation or digit generation) is allowed to be in progress per call. This implies that if tone generation is currently in progress on a call, invoking either
[TSPI_lineGenerateDigits](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegeneratedigits) or
**TSPI_lineGenerateTone** cancels the tone generation. The service provider must terminate any tone generation in progress when a subsequent
[TSPI_lineGenerateDigits](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegeneratedigits) or
**TSPI_lineGenerateTone** function is invoked.

The corresponding function at the TAPI level does not include the formal parameter *dwEndToEndID*. At that level, there is no end-to-end marking. TAPI uses end-to-end marking at the TSPI level to distinguish one
**TSPI_lineGenerateTone** request from another.

## See also

[LINEGENERATETONE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linegeneratetone)

[LINETONEMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linetonemode--constants)

[LINE_GENERATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725230(v=vs.85))

[TSPI_lineGenerateDigits](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegeneratedigits)