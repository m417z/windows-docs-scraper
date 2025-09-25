# _OPCR structure

## Description

The OPCR structure contains initialization values for an output plug.

## Members

### `Payload`

Specifies the connection speed.

### `OverheadID`

Specifies, for an unconnected output plug, the upper bounds for the bandwidth that the output plug needs for the transmission of an isochronous packet.

### `DataRate`

Indicates the bit rate that the output plug uses to transmit an isochronous packet.

### `Channel`

Indicates the channel number that the output plug shall use to transmit the isochronous data flow, for a suspended output plug. For an active output plug it indicates the actual channel number that the output plug uses to transmit the isochronous data flow. For an unconnected output plug it has no meaning.

### `Reserved`

Reserved.

### `PPCCounter`

Indicates the number of point-to-point connections to the output plug.

### `BCCCounter`

Indicates, when one, that there is a broadcast-out connection to the output plug. When zero it indicates that there is no connection.

### `OnLine`

Indicates, when one, that the corresponding output plug is on-line. When zero it indicates that the output plug is off-line.

## See also

[AV_PCR](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_pcr)