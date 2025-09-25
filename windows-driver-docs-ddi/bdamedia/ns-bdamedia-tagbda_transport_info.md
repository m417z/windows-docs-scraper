# tagBDA_TRANSPORT_INFO structure

## Description

The BDA_TRANSPORT_INFO structure describes formatting for a stream connection.

## Members

### `ulcbPhyiscalPacket`

Size, in bytes, of a physical packet (for example, the size of a satellite link payload).

### `ulcbPhyiscalFrame`

Size, in bytes, of each physical frame (0 indicates no hardware requirement).

### `ulcbPhyiscalFrameAlignment`

Capture buffer alignment in bytes (0 and 1 indicate no alignment requirements).

### `AvgTimePerFrame`

REFERENCE TIME value that indicates the video frame's average display time, in 100-nanosecond units.

## Remarks

A BDA_TRANSPORT_INFO structure in conjunction with a KSDATARANGE structure makes up a KS_DATARANGE_BDA_TRANSPORT data range. A data range describes a range of data formats.

Pins of filters specify the data ranges they support to enable stream connections to pins of other filters that also support those data ranges.

## See also

[KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85))

[KSPIN_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kspin_descriptor)

[KS_DATARANGE_BDA_TRANSPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdamedia/ns-bdamedia-tagks_datarange_bda_transport)