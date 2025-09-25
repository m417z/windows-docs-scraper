# TSPI_lineSetMediaControl function

## Description

The
**TSPI_lineSetMediaControl** function enables and disables control actions on the media stream associated with the specified line, address, or call. Media control actions can be triggered by the detection of specified digits, media types, custom tones, and call states. The new specified media controls replace all the ones that were in effect for this line, address, or call prior to this request.

## Parameters

### `hdLine`

The handle to a line.

### `dwAddressID`

An address on the given open line device. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades. TAPI does not validate this parameter when this function is called.

### `hdCall`

The handle to a call. The call state of *hdCall* can be any state.

### `dwSelect`

Specifies whether media control is requested is associated with a single call, is the default for all calls on an address, or is the default for all calls on a line. This parameter uses the following
[LINECALLSELECT_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallselect--constants).

### `lpDigitList`

A pointer to the array that contains the digits that are to trigger media control actions, of type
[LINEMEDIACONTROLDIGIT](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemediacontroldigit). Each time a digit listed in the digit list is detected, the specified media control action is carried out on the call's media stream.

Valid digits for pulse mode are '0' through '9'. Valid digits for DTMF mode are '0' through '9', 'A', 'B', 'C', 'D', '*', '#'.

### `dwDigitNumEntries`

The number of entries in the *lpDigitList*. TAPI does not validate this parameter when this function is called.

### `lpMediaList`

A pointer to an array with entries of type
[LINEMEDIACONTROLMEDIA](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemediacontrolmedia). The array has *dwMediaNumEntries* entries. Each entry contains a media type to be monitored, media-type specific information (such as duration), and a media control field. If a media type in the list is detected, the corresponding media control action is performed on the call's media stream.

### `dwMediaNumEntries`

The number of entries in *lpMediaList*. TAPI does not validate this parameter when this function is called.

### `lpToneList`

A pointer to an array with entries of type
[LINEMEDIACONTROLTONE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemediacontroltone). The array has *dwToneNumEntries* entries. Each entry contains a description of a tone to be monitored, duration of the tone, and a media control field. If a tone in the list is detected, the corresponding media control action is performed on the call's media stream.

### `dwToneNumEntries`

The number of entries in *lpToneList*. TAPI does not validate this parameter when this function is called.

### `lpCallStateList`

A pointer to an array with entries of type
[LINEMEDIACONTROLCALLSTATE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemediacontrolcallstate). The array has *dwCallStateNumEntries* entries. Each entry contains a call state and a media control action.

### `dwCallStateNumEntries`

The number of entries in *lpCallStateList*. TAPI does not validate this parameter when this function is called.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALADDRESSID, LINEERR_INVALPOINTER, LINEERR_INVALCALLHANDLE, LINEERR_INVALTONELIST, LINEERR_INVALCALLSELECT, LINEERR_NOMEM, LINEERR_INVALCALLSTATELIST, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALDIGITLIST, LINEERR_OPERATIONFAILED, LINEERR_INVALLINEHANDLE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALMEDIALIST.

## Remarks

This function returns zero (success) when media control is correctly initiated, not when any media control takes effect. Media control in progress is changed or is canceled when this function is called again with either different parameters or **NULL**s.

Only a single media control request can be outstanding on a call at one time. A request replaces any that may be outstanding.

Depending on the service provider and other activities that compete for such resources, the amount of simultaneous detections that can be made can vary over time. If service provider resources are overcommitted, it returns LINEERR_RESOURCEUNAVAIL.

Whether or not media control is supported by the service provider is a device capability indicated in
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps).

Each time
**TSPI_lineSetMediaControl** is called, the new request overrides any media control currently in effect. If one or more of the parameters *lpDigitList*, *lpMediaList*, *lpToneList*, and *lpCallStateList* are **NULL**, the corresponding digit, media type, tone, or call state-triggered media control is disabled. To modify just a portion of the media control parameters while leaving the remaining settings in effect, the application should invoke
**TSPI_lineSetMediaControl** supplying the previous parameters for those portions that must remain in effect, and new parameters for those parts that are to be modified.

## See also

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[LINEDIGITMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linedigitmode--constants)

[LINEMEDIACONTROLCALLSTATE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemediacontrolcallstate)

[LINEMEDIACONTROLDIGIT](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemediacontroldigit)

[LINEMEDIACONTROLMEDIA](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemediacontrolmedia)

[LINEMEDIACONTROLTONE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemediacontroltone)

[LINEMEDIAMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linemediamode--constants)

[TSPI_lineGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetdevcaps)