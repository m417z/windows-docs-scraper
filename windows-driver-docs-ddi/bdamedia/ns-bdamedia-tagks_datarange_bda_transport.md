# tagKS_DATARANGE_BDA_TRANSPORT structure

## Description

The KS_DATARANGE_BDA_TRANSPORT structure describes a range of data formats for a BDA transport stream.

## Members

### `DataRange`

KSDATARANGE structure that describes a range of data formats.

### `BdaTransportInfo`

BDA_TRANSPORT_INFO structure that describes formatting for a BDA transport stream connection.

## Remarks

A BDA_TRANSPORT_INFO structure in conjunction with a KSDATARANGE structure makes up a KS_DATARANGE_BDA_TRANSPORT data range. A data range describes a range of data formats.

Pins of filters specify the data ranges they support to enable stream connections to pins of other filters that also support those data ranges.

## See also

[BDA Stream Format GUIDs](https://learn.microsoft.com/windows-hardware/drivers/stream/bda-stream-format-guids)

[BDA_TRANSPORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdamedia/ns-bdamedia-tagbda_transport_info)

[KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85))

[KSPIN_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kspin_descriptor)