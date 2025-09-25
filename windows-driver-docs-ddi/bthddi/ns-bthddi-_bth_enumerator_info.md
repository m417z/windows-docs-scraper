# _BTH_ENUMERATOR_INFO structure

## Description

The BTH_ENUMERATOR_INFO structure contains information about an underlying device and the service
that caused the Plug and Play (PnP) manager to load the profile driver.

## Members

### `EnumeratorType`

Reserved for use by the Bluetooth driver stack. Do not use.

### `Action`

Reserved for use by the Bluetooth driver stack. Do not use.

### `Port`

If the enumeration was caused by a connection request, this member contains the device's port
number. Otherwise, this value is undefined. For a L2CAP connection request, the port number also
identifies the Protocol/Service Multiplexer (PSM) that is being connected to. For an RFCOMM connection
request, this is an RFCOMM data link connection identifier (DLCI).

### `Flags`

A flag that indicates the direction of the request. Possible values include:

* BTH_ENUMERATORFL_INCOMING
* BTH_ENUMERATORFL_OUTGOING
* BTH_ENUMERATORFL_REENUM

### `Guid`

 The enumeration protocol or service class GUID. This value is usually obtained from the INF file
that loaded the profile driver.

### `InstanceId`

 The instance ID of the protocol or service if the BTH_ENUMERATORFL_INCOMING flag is set.

### `InstanceIdStr`

 The instance ID of the protocol or service if the BTH_ENUMERATORFL_OUTGOING flag is set.

### `Vid`

The vendor ID of the remote device, which is obtained from SDP.

### `Pid`

The product ID of the remote device, which is obtained from SDP.

### `Mfg`

The manufacturer ID of the remote device, which is obtained from SDP.

### `LocalMfg`

The local radio manufacturer obtained from the HCI.

### `VidType`

 The remote device vendor ID type, which is obtained from SDP.

### `ServiceName`

The service name that is used for local services.

### `SdpPriLangServiceName`

The identifier used for remote services.

### `DeviceString`

The device string for the remote device.

## Remarks

The
[IOCTL_INTERNAL_BTHENUM_GET_ENUMINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_internal_bthenum_get_enuminfo) call's output buffer contains the information about an
underlying device and the service that caused the Plug and Play (PnP) manager to load the profile
driver.

## See also

[ENUMERATOR_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_enumerator_action)

[ENUMERATOR_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_enumerator_type)

[IOCTL_INTERNAL_BTHENUM_GET_ENUMINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_internal_bthenum_get_enuminfo)