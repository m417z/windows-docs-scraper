# IOCTL_BTHHFP_DEVICE_REQUEST_CONNECT IOCTL

## Description

The **IOCTL_BTHHFP_DEVICE_REQUEST_CONNECT**
IOCTL requests a Handsfree Profile (HFP) Service Level Connection to the Bluetooth device.

## Parameters

### Major code

### Input buffer

N/A

### Input buffer length

N/A

### Output buffer

N/A

### Output buffer length

N/A

### Input/output buffer

### Input/output buffer length

### Status block

N/A

## Remarks

This request initiates the procedure to create a Service Level Connection, and ends without waiting for the connection procedure to complete. Connection status can be determined using [IOCTL_BTHHFP_DEVICE_GET_CONNECTION_STATUS_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ni-bthhfpddi-ioctl_bthhfp_device_get_connection_status_update).

The audio driver sends this request from its handler for the [KSPROPERTY_ONESHOT_RECONNECT](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-oneshot-reconnect) KS property.

## See also

[Bluetooth HFP DDI IOCTLs](https://learn.microsoft.com/windows-hardware/drivers/audio/bluetooth-hfp-ddi-ioctls)

[IOCTL_BTHHFP_DEVICE_GET_CONNECTION_STATUS_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ni-bthhfpddi-ioctl_bthhfp_device_get_connection_status_update)

[KSPROPERTY_ONESHOT_RECONNECT](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-oneshot-reconnect)