# _UNIT_ISOCH_PARAMS structure

## Description

The UNIT_ISOCH_PARAMS structure is used to get or set the parameters that the IEC-61883 protocol driver uses when capturing or transmitting isochronous packets.

## Members

### `RX_NumPackets`

The number of isochronous packets per descriptor to be received.

### `RX_NumDescriptors`

The number of descriptors used for receiving isochronous data.

### `TX_NumPackets`

The number of isochronous packets per descriptor to be transmitted.

### `TX_NumDescriptors`

The number of descriptors used for transmitting isochronous data.

## Remarks

The UNIT_ISOCH_PARAMS structure can be used with Av61883_SetUnitInfo to set the number of isochronous packets and descriptors used while transmitting or receiving data. Before setting isochronous parameters, a driver should send an [Av61883_GetUnitInfo](https://learn.microsoft.com/previous-versions/ff536983(v=vs.85)) request to retrieve the current isochronous parameters and then make any necessary modifications with **Av61883_SetUnitInfo**.

## See also

[Av61883_GetUnitInfo](https://learn.microsoft.com/previous-versions/ff536983(v=vs.85))

[AV_61883_REQUEST structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)