# _IRB_REQ_GET_MAX_SPEED_BETWEEN_DEVICES structure

## Description

This structure contains the fields necessary in order for the Bus driver to carry out a
**GetMaxSpeedBetweenDevices** request.

## Members

### `fulFlags`

Specifies the source device. Zero indicates the calling device. USE_LOCAL_NODE indicates the computer itself.

**Note** In Windows 7, the new 1394 bus driver returns only the speed between the local node and the device. The USE_LOCAL_NODE flag must be set in the **u.GetMaxSpeedBetweenDevices.fulFlags** parameter.

### `ulNumberOfDestinations`

Specifies the number of destination devices.

### `hDestinationDeviceObjects`

Points to an array of the device objects of the destination devices.

### `fulSpeed`

Specifies the maximum speed returned.