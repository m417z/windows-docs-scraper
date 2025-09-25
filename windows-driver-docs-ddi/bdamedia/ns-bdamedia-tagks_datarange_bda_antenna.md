# tagKS_DATARANGE_BDA_ANTENNA structure

## Description

The KS_DATARANGE_BDA_ANTENNA structure describes a range of data formats for a BDA antenna stream.

## Members

### `DataRange`

KSDATARANGE structure that describes a range of data formats with the **MajorFormat** member specified as STATIC_KSDATAFORMAT_TYPE_BDA_ANTENNA.

## Remarks

A data range describes a range of data formats.

Pins of filters specify the data ranges they support to enable stream connections to pins of other filters that also support those data ranges.

## See also

[BDA Stream Format GUIDs](https://learn.microsoft.com/windows-hardware/drivers/stream/bda-stream-format-guids)

[KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85))

[KSPIN_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kspin_descriptor)