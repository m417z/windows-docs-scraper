# IKsInterfaceHandler::KsCompleteIo

## Description

The **KsCompleteIo** method cleans up extended headers and releases media samples after input and output (I/O) complete.

## Parameters

### `StreamSegment` [in, out]

Pointer to a [KSSTREAM_SEGMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/ns-ksproxy-_ksstream_segment) structure that contains header information for a stream segment to complete.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

The **KsCompleteIo** method discards allocated memory, updates media samples, and decrements the count of wait items for the proxy.

The **KsCompleteIo** method must determine the type of I/O operation that the [IKsInterfaceHandler::KsProcessMediaSamples](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksinterfacehandler-ksprocessmediasamples) method completed from the **IoOperation** member of the KSSTREAM_SEGMENT structure. If the I/O operation was reading data from a stream (**KsIoOperation_Read** of the KSIOOPERATION enumerated type), **KsCompleteIo** performs the following actions to deliver the sample from an output pin to the connected input pin:

* Reflects the stream header information in the **IMediaSample** interface.
* Calls the [IKsPin::KsDeliver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-ikspin-ksdeliver) method of the output pin to deliver the sample. **KsDeliver** releases the sample so that when queuing buffers to the device, the sample can be retrieved if it is the last sample. The input pin then completes the I/O and it is safe to release the sample.

For more information about **IMediaSample**, see the Microsoft Windows SDK documentation.

## See also

[IKsInterfaceHandler::KsProcessMediaSamples](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksinterfacehandler-ksprocessmediasamples)

[IKsPin::KsDeliver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-ikspin-ksdeliver)

[KSSTREAM_SEGMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/ns-ksproxy-_ksstream_segment)