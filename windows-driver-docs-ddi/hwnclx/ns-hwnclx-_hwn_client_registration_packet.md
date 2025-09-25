# _HWN_CLIENT_REGISTRATION_PACKET structure

## Description

Hardware Notification client driver registration packet that is passed to the class
extension when a client driver is registered. Contains version information and
client driver callback functions.

## Members

### `Version`

Version of this structure.

### `Size`

Size of this structure.

### `DeviceContextSize`

Size of the driver-defined context structure.

### `Reserved`

Reserved.

### `ClientInitializeDevice`

A pointer to the client driver's implementation of the [HWN_CLIENT_INITIALIZE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hwnclx/nc-hwnclx-hwn_client_initialize_device) callback function.

### `ClientUnInitializeDevice`

A pointer to the client driver's implementation of the [HWN_CLIENT_UNINITIALIZE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hwnclx/nc-hwnclx-hwn_client_uninitialize_device) callback function.

### `ClientQueryDeviceInformation`

A pointer to the client driver's implementation of the [HWN_CLIENT_QUERY_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/hwnclx/nc-hwnclx-hwn_client_query_device_information) callback function.

### `ClientStartDevice`

A pointer to the client driver's implementation of the [HWN_CLIENT_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hwnclx/nc-hwnclx-hwn_client_start_device) callback function.

### `ClientStopDevice`

A pointer to the client driver's implementation of the [HWN_CLIENT_STOP_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hwnclx/nc-hwnclx-hwn_client_stop_device) callback function.

### `ClientSetHwNState`

A pointer to the client driver's implementation of the [HWN_CLIENT_SET_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hwnclx/nc-hwnclx-hwn_client_set_state) callback function.

### `ClientGetHwNState`

A pointer to the client driver's implementation of the [HWN_CLIENT_GET_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hwnclx/nc-hwnclx-hwn_client_get_state) callback function.

## Syntax

```cpp
typedef struct _HWN_CLIENT_REGISTRATION_PACKET {
  USHORT                                Version;
  USHORT                                Size;
  ULONG                                 DeviceContextSize;
  ULONG                                 Reserved;
  PHWN_CLIENT_INITIALIZE_DEVICE         ClientInitializeDevice;
  PHWN_CLIENT_UNINITIALIZE_DEVICE       ClientUnInitializeDevice;
  PHWN_CLIENT_QUERY_DEVICE_INFORMATION  ClientQueryDeviceInformation;
  PHWN_CLIENT_START_DEVICE              ClientStartDevice;
  PHWN_CLIENT_STOP_DEVICE               ClientStopDevice;
  PHWN_CLIENT_SET_STATE                 ClientSetHwNState;
  PHWN_CLIENT_GET_STATE                 ClientGetHwNState;
} HWN_CLIENT_REGISTRATION_PACKET, HWN_CLIENT_REGISTRATION_PACKET;
```

## See also

[Hardware notifications support](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/hardware-notifications-support)

[Hardware notifications reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/_gpio)