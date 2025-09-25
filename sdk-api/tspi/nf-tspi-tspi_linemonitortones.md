# TSPI_lineMonitorTones function

## Description

The
**TSPI_lineMonitorTones** function enables and disables the detection of inband tones on the call. Each time a specified tone is detected, a message is sent to the client application through TAPI.

## Parameters

### `hdCall`

The handle to the call for which tone detection is to be done. The call state of *hdCall* can be any state except *idle*.

### `dwToneListID`

The unique identifier for this tone list. Several tone lists can be outstanding at one time. The service provider must replace any old list having the same *dwToneListID* with the new tone list. If *lpToneList* is **NULL**, the tone list with *dwToneListID* is simply dropped. In any case, other tone lists with different *dwToneListID*s are kept unchanged.

### `lpToneList`

A list of tones to be monitored, of type
[LINEMONITORTONE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemonitortone). Each tone in this list has an application-defined tag field that is used to identify individual tones in the list for the purpose of reporting a tone detection. Tone monitoring in progress is canceled or changed by calling this operation with either **NULL** for *lpToneList* or with another tone list. The service provider must copy the tone list into its own memory for later reference, rather than simply retaining the pointer into application memory.

### `dwNumEntries`

The number of entries in *lpToneList*. The *dwNumEntries* parameter is ignored if *lpToneList* is **NULL**. TAPI does not validate this parameter when this function is called.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONFAILED, LINEERR_INVALTONE, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM, LINEERR_INVALPOINTER.

## Remarks

This function returns zero (success) when tone monitoring is correctly initiated, not when tone monitoring is terminated. As with media monitoring, tone monitoring remains in effect for a given tone list until that tone list is explicitly disabled by calling
**TSPI_lineMonitorTones** with the same *dwToneListID* and another tone list (or a **NULL** tone list), or until the call transitions to *idle*.

Although this function can be invoked in any call state except *idle*, tones can typically only be detected while the call is in the *connected* state. Tone detection usually requires computational resources. Depending on the service provider and other activities that compete for such resources, the number of tones that can be detected can vary over time. Also, an equivalent amount of resources can be consumed for monitoring a single triple frequency tone versus three single frequency tones. If resources are overcommitted, the service provider returns LINEERR_RESOURCEUNAVAIL.

The service provider monitors for all tones in all tone lists concurrently. When a tone is detected, each matching tone from each tone list is reported separately using a
[LINE_MONITORTONE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725234(v=vs.85)) message. Each tone report includes both the tone list identifier and the application-specific tag. Some service providers may not be able to discriminate very close tones, so that multiple matches may be reported even for tones whose descriptions are not strictly identical.

**Note** **TSPI_lineMonitorTones** is also used to detect silence. Silence is specified as a tone with all zero frequencies.

The corresponding function at the TAPI level does not include a *dwToneListID* parameter. The inclusion of this parameter at the TSPI interface allows TAPI to forward the union of all tone monitoring lists from all applications to the service provider, while still retaining the ability to filter and forward the tone detection events according to application. This gives service-provider designers the maximum flexibility to determine the degree to which they can discriminate very close tones, because TAPI makes no assumptions about what tone descriptions are considered identical.

## See also

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[LINEMONITORTONE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemonitortone)

[LINE_MONITORTONE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725234(v=vs.85))

[TSPI_lineGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetdevcaps)

[TSPI_lineSetMediaControl](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetmediacontrol)