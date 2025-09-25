# IKsPin::KsMediaSamplesCompleted

## Description

The **KsMediaSamplesCompleted** method informs a pin that a stream segment completed.

## Parameters

### `StreamSegment` [in]

Pointer to a [KSSTREAM_SEGMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/ns-ksproxy-_ksstream_segment) structure that contains header information for a completed stream segment.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

Input pins do nothing with the supplied header information and just return NOERROR. Output pins remove the head of the input and output (I/O) queue and add the next in the list to the I/O slots.

When a client calls the [IKsInterfaceHandler::KsCompleteIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksinterfacehandler-kscompleteio) method of an interface handler to complete an I/O operation, **KsCompleteIo** calls **KsMediaSamplesCompleted** for pins.

## See also

[IKsInterfaceHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-iksinterfacehandler)

[IKsInterfaceHandler::KsCompleteIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksinterfacehandler-kscompleteio)

[KSSTREAM_SEGMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/ns-ksproxy-_ksstream_segment)