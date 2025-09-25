# _SET_CMP_ADDRESS_TYPE structure

## Description

The SET_CMP_ADDRESS_TYPE structure is used in conjunction with the Av61883_SetUnitInfo request to set the parameters that the IEC-61883 protocol driver should use when capturing and transmitting isochronous packets.

## Members

### `Type`

Indicates what kind of address range plugs can be accessed in. Possible values are:

#### CMP_ADDRESS_TYPE_GLOBAL

This requests the default behavior. All plugs created on the local system are within a global address range, accessible by any node on the 1394 bus.

#### CMP_ADDRESS_TYPE_EXCLUSIVE

This flag must be set before any plugs are created or removed within the driver. When this flag is set, all plugs created within the driver are in an exclusive address range, only accessible to the device for which the driver is loaded.

## See also

[AV_61883_REQUEST structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)