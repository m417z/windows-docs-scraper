# StreamClassCompleteRequestAndMarkQueueReady function

## Description

The **StreamClassCompleteRequestAndMarkQueueReady** routine completes a request, and signals the class driver that the minidriver is ready to receive a new request of the same type.

## Parameters

### `Srb` [in]

Pointer to the [HW_STREAM_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_request_block) that the minidriver has completed processing.

## Return value

None

## Remarks

This call is equivalent to calling **StreamClass***Xxx***Notification** twice, once to signal that the request is completed, and once to signal that the minidriver is ready for the next request of that type.

## See also

[HW_STREAM_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_request_block)

[StreamClassDeviceNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassdevicenotification)

[StreamClassStreamNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassstreamnotification)