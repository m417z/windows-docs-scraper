# lineMonitorTones function

## Description

The
**lineMonitorTones** function enables and disables the detection of inband tones on the call. Each time a specified tone is detected, a message is sent to the application.

## Parameters

### `hCall`

Handle to the call on whose voice channel tones are to be monitored. The call state of *hCall* can be any state except *idle*.

### `lpToneList`

List of tones to be monitored. This parameter is of type
[LINEMONITORTONE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemonitortone). Each tone in this list has an application-defined tag field that is used to identify individual tones in the list to report a tone detection. Tone monitoring in progress is canceled or changed by calling this operation with either **NULL** for *lpToneList* or with another tone list.

### `dwNumEntries`

Number of entries in *lpToneList*. This parameter is ignored if *lpToneList* is **NULL**.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INVALCALLHANDLE, LINEERR_INVALCALLSTATE, LINEERR_INVALPOINTER, LINEERR_INVALTONE, LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL, LINEERR_RESOURCEUNAVAIL, LINEERR_UNINITIALIZED.

## Remarks

This function succeeds if tone monitoring has been correctly initiated, not when tone monitoring has terminated. Tone monitoring remains in effect until it is explicitly disabled by calling
**lineMonitorTones** with another tone list (or **NULL**), until the call transitions to *idle*, or when the application deallocates its call handle for the call.

Although this function can be invoked in any call state, tones can typically only be detected while the call is in the *connected* state. Tone detection typically requires computational resources. Depending on the service provider and other activities that compete for such resources, the number of tones that can be detected can vary over time. Also, an equivalent amount of resources can be consumed for monitoring a single triple frequency tone versus three single frequency tones. If resources are overcommitted, the LINEERR_RESOURCEUNAVAIL error is returned.

The
**lineMonitorTones** function is also used to detect silence. Silence is specified as a tone with a frequency of zero.

Monitoring of tones on a conference call applies only to the *hConfCall*, not to the individual participating calls

If the LINEERR_INVALPOINTER error value is returned, the specified *lpToneList* parameter is invalid or the value specified by the *dwNumEntries* parameter is too large.

## See also

[LINEMONITORTONE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemonitortone)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)