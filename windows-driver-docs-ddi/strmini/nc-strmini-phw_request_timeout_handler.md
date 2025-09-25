## Description

The stream class driver calls the minidriver's *StrMiniRequestTimeout* routine to signal to the minidriver that a request has timed out.

## Parameters

### `SRB` [in]

Pointer to the stream request that has timed out.

## Remarks

The minidriver specifies this routine in the **HwRequestTimeoutHandler** member of its [HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_initialization_data) structure. The minidriver passes this structure to the class driver when it registers itself by calling [StreamClassRegisterMinidriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassregisteradapter).

When the class driver first issues a request, it sets a time-out value (in seconds) with the **TimeoutCounter** member of the [HW_STREAM_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_request_block) pointed to by *SRB*. The class driver decrements the **TimeoutCounter** member of that structure once a second. A request times out when the class driver decrements **TimeoutCounter** to zero, at which time the class driver calls *StrMiniRequestTimeout* to handle any clean-up necessary to cease processing the request.

Minidrivers that rely on the class driver to handle synchronization should, once they have successfully handled the request time-out, signal to the class driver that they are ready for another request by using [StreamClassStreamNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassstreamnotification) or [StreamClassDeviceNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassdevicenotification) with the appropriate **ReadyForNext***Xxx***Request**.