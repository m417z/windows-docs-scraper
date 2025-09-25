# lineSetMediaControl function

## Description

The
**lineSetMediaControl** function enables and disables control actions on the media stream associated with the specified line, address, or call. Media control actions can be triggered by the detection of specified digits, media types, custom tones, and call states.

## Parameters

### `hLine`

Handle to an open line device.

### `dwAddressID`

Address identifier on the given open line device. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `hCall`

Handle to a call. The application must be an owner of the call. The call state of *hCall* can be any state.

### `dwSelect`

Whether the media control requested is associated with a single call, is the default for all calls on an address, or is the default for all calls on a line. This parameter one and only one of the
[LINECALLSELECT_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallselect--constants).

### `lpDigitList`

Pointer to the array that contains the digits that are to trigger media control actions, of type
[LINEMEDIACONTROLDIGIT](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemediacontroldigit). Each time a digit in the digit list is detected, the specified media control action is carried out on the call's media stream.

Valid digits for pulse mode are '0' through '9'. Valid digits for DTMF mode are '0' through '9', 'A', 'B', 'C', 'D', '*', '#'.

### `dwDigitNumEntries`

Number of entries in the *lpDigitList*.

### `lpMediaList`

Pointer to an array with entries of type
[LINEMEDIACONTROLMEDIA](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemediacontrolmedia). The array has *dwMediaNumEntries* entries. Each entry contains a media type to be monitored, media-type specific information (such as duration), and a media control field. If a media type in the list is detected, the corresponding media control action is performed on the call's media stream.

### `dwMediaNumEntries`

Number of entries in *lpMediaList*.

### `lpToneList`

Pointer to an array with entries of type
[LINEMEDIACONTROLTONE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemediacontroltone). The array has *dwToneNumEntries* entries. Each entry contains a description of a tone to be monitored, duration of the tone, and a media-control field. If a tone in the list is detected, the corresponding media control action is performed on the call's media stream.

### `dwToneNumEntries`

Number of entries in *lpToneList*.

### `lpCallStateList`

Pointer to an array with entries of type
[LINEMEDIACONTROLCALLSTATE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemediacontrolcallstate). The array has *dwCallStateNumEntries* entries. Each entry contains a call state and a media control action. Whenever the given call transitions into one of the call states in the list, the corresponding media control action is invoked.

### `dwCallStateNumEntries`

Number of entries in *lpCallStateList*.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INVALADDRESSID, LINEERR_NOMEM, LINEERR_INVALCALLHANDLE, LINEERR_NOTOWNER, LINEERR_INVALCALLSELECT, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLSTATELIST, LINEERR_OPERATIONFAILED, LINEERR_INVALDIGITLIST, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALLINEHANDLE, LINEERR_UNINITIALIZED, LINEERR_INVALMEDIALIST, LINEERR_INVALPOINTER, LINEERR_INVALTONELIST.

## Remarks

The
**lineSetMediaControl** function is considered successful if media control has been correctly initiated, not when any media control has taken effect. Media control in progress is changed or is canceled by calling this function again with either different parameters or **NULL**s. If one or more of the parameters *lpDigitList*, *lpMediaList*, *lpToneList*, and *lpCallStateList* are **NULL**, then the corresponding digit, media type, tone, or call state-triggered media control is disabled. To modify just a portion of the media control parameters while leaving the remaining settings in effect, the application should invoke
**lineSetMediaControl**, supplying the previous parameters for those portions that must remain in effect and new parameters for those parts that are to be modified.

If *hCall* is selected and the call terminates or the application deallocates its handle, media control on that call is canceled.

All applications that are owners of the call are in principle allowed to make media control requests on the call. Only a single media control request can be outstanding on a call across all applications that own the call. Each time
**lineSetMediaControl** is called, the new request overrides any media control then in effect on the call, whether set by the calling application or any other owning application.

Depending on the service provider and other activities that compete for such resources, the number of simultaneous detections that can be made can vary over time. If service provider resources are overcommitted, the LINEERR_RESOURCEUNAVAIL error is returned.

Whether or not media control is supported by the service provider is a device capability.

## See also

[LINEMEDIACONTROLCALLSTATE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemediacontrolcallstate)

[LINEMEDIACONTROLDIGIT](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemediacontroldigit)

[LINEMEDIACONTROLMEDIA](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemediacontrolmedia)

[LINEMEDIACONTROLTONE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemediacontroltone)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)