# IKsPin::KsDeliver

## Description

The **KsDeliver** method delivers a media sample from an output pin to an input pin, continues an I/O operation by retrieving the next buffer from an allocator, and submits the buffer to the associated device.

## Parameters

### `Sample` [in]

Pointer to the **IMediaSample** interface for the associated media sample.

### `Flags` [in]

Specifies a bitmask enumerating information about the stream header of the media sample. A bitwise OR combination of the following flags is possible:

KSSTREAM_HEADER_OPTIONSF_SPLICEPOINT

KSSTREAM_HEADER_OPTIONSF_PREROLL

KSSTREAM_HEADER_OPTIONSF_DATADISCONTINUITY

KSSTREAM_HEADER_OPTIONSF_TYPECHANGED

KSSTREAM_HEADER_OPTIONSF_TIMEVALID

KSSTREAM_HEADER_OPTIONSF_TIMEDISCONTINUITY

KSSTREAM_HEADER_OPTIONSF_FLUSHONPAUSE

KSSTREAM_HEADER_OPTIONSF_DURATIONVALID

KSSTREAM_HEADER_OPTIONSF_ENDOFSTREAM

KSSTREAM_HEADER_OPTIONSF_LOOPEDDATA

These flags are defined in the **OptionsFlags** member of the [KSSTREAM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksstream_header) structure description.

The pin connection checks for the end-of-stream flag (KSSTREAM_HEADER_OPTIONSF_ENDOFSTREAM) to determine if it must deliver an end-of-stream event after the sample completes.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

An interface handler ([IKsInterfaceHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-iksinterfacehandler)) calls **KsDeliver** on the output pin of a filter to deliver a media sample to the input pin of another filter. These input and output pins are connected.

For an input pin, **KsDeliver** is an invalid entry point and returns EFAIL.

For more information about **IMediaSample**, see the Microsoft Windows SDK documentation.

## See also

[IKsInterfaceHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nn-ksproxy-iksinterfacehandler)

[IKsInterfaceHandler::KsCompleteIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksinterfacehandler-kscompleteio)