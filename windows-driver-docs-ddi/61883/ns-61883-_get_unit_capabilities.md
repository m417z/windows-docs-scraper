# _GET_UNIT_CAPABILITIES structure

## Description

The GET_UNIT_CAPABILITIES structure is used in conjunction with the [Av61883_GetUnitInfo](https://learn.microsoft.com/previous-versions/ff536983(v=vs.85)) request to retrieve unit information about a device's capabilities.

## Members

### `NumOutputPlugs`

The number of output plugs supported by the device.

### `NumInputPlugs`

The number of input plugs supported by the device.

### `MaxDataRate`

The maximum data rate of the device. Can be one of the following:

CMP_SPEED_S100

CMP_SPEED_S200

CMP_SPEED_S400

### `CTSFlags`

A bitmask that identifies the command and transaction sets supported by the device. For example, if **CTSFlags** is 0001, the device supports Audio Video Control (AV/C). If **CTSFlags** is 4000, the device supports a vendor-unique CTS. Most devices that support multiple command and transaction sets report each CTS value in a separate Configuration ROM unit directory entry, so typically only one bit is set at a time.

### `HardwareFlags`

If the AV_HOST_DMA_DOUBLE_BUFFERING_ENABLED flag is set, and the request level is SET_UNIT_INFO_ISOCH_PARAMS, then a size limit is imposed on members **RX_NumPackets** and **TX_NumPackets** of the [UNIT_ISOCH_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_unit_isoch_params) structure. These members, when multiplied by the packet size, must be less than or equal to 64 KB. For example, **Rx_NumPackets * PacketSize** must be less than or equal to 64 KB.

## See also

[Av61883_GetUnitInfo](https://learn.microsoft.com/previous-versions/ff536983(v=vs.85))