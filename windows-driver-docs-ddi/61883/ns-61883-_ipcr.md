# _IPCR structure

## Description

The IPCR structure contains initialization values for an input plug.

## Members

### `Reserved0`

Reserved.

### `Channel`

Indicates the channel number that the input plug shall use to transmit the isochronous data flow, for a suspended input plug. For an active input plug it indicates the actual channel number that the input plug uses to transmit the isochronous data flow. For an unconnected input plug it has no meaning.

### `Reserved1`

Reserved.

### `PPCCounter`

Indicates the number of point-to-point connections to the input plug.

### `BCCCounter`

Indicates, when one, that there is a broadcast-in connection to the input plug. When zero it indicates that there is no connection.

### `OnLine`

Indicates, when one, that the corresponding input plug is on-line. When zero it indicates that the input plug is off-line.

## See also

[AV_PCR](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_pcr)