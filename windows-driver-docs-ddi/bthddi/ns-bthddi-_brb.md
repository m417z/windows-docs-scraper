# _BRB structure

## Description

Profile drivers use Bluetooth request blocks (BRBs), to send requests to the Bluetooth driver stack.
The BRB structure defines the format for all supported commands that can be sent to a Bluetooth
device.

## Members

### `BrbHeader`

Describes basic information about the request being sent to the Bluetooth device. For more
information, see
[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header).

### `BrbGetDeviceInterfaceString`

Defines the format for a command to get the interface string of the current Bluetooth device
object. For more information about getting the device interface string, see
[_BRB_GET_DEVICE_INTERFACE_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_get_device_interface_string).

### `BrbL2caRegisterServer`

Defines the format for a command to register a L2CAP server. For more information about
registering a L2CAP server, see
[_BRB_L2CA_REGISTER_SERVER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_register_server).

### `BrbL2caUnregisterServer`

Defines the format for a command to unregister a previously registered L2CAP server. For more
information about unregistering a L2CAP server, see
[_BRB_L2CA_UNREGISTER_SERVER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_unregister_server).

### `BrbL2caOpenChannel`

Defines the format of the L2CAP open channel and the L2CAP open channel response commands sent to
the Bluetooth device. For more information about opening a L2CAP channel, see
[_BRB_L2CA_OPEN_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_open_channel).

### `BrbL2caCloseChannel`

Defines the format of a L2CAP close channel command sent to the Bluetooth device. For more
information about closing a L2CAP channel, see
[_BRB_L2CA_CLOSE_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_close_channel).

### `BrbL2caPing`

Defines the format of a command that sends a L2CAP_EchoReq message to and receives a
L2CAP_EchoRsp message from a remote Bluetooth device over a L2CAP connection. For more information
about pinging a L2CAP connection, see
[_BRB_L2CA_PING](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_ping).

### `BrbL2caAclTransfer`

Defines the format of a command that performs read and write operations over a L2CAP connection
to a Bluetooth device. For more information about ACL transfers, see
[_BRB_L2CA_ACL_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_acl_transfer).

### `BrbGetLocalBdAddress`

Defines the format of a command that returns the address of the local Bluetooth radio. For more
information about getting the local Bluetooth device address, see
[_BRB_GET_LOCAL_BD_ADDR](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_get_local_bd_addr).

### `BrbPsm`

Defines the format for the commands that register and unregister a Protocol/Service Multiplexer
(PSM) that L2CAP Bluetooth devices connect to. For more information about PSMs, see
[_BRB_PSM](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_psm).

### `BrbL2caUpdateChannel`

Defines the format of a command that updates the settings of a L2CAP channel to a Bluetooth
device. For more information about updating a L2CAP channel, see
[_BRB_L2CA_UPDATE_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_update_channel).

### `BrbScoRegisterServer`

Defines the format for a command to register a SCO server. For more information about registering
a SCO server, see
[_BRB_SCO_REGISTER_SERVER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_register_server).

### `BrbScoUnregisterServer`

Defines the format for a command to unregister a previously registered SCO server. For more
information about unregistering a SCO server, see
[_BRB_SCO_UNREGISTER_SERVER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_unregister_server).

### `BrbScoOpenChannel`

Defines the format of SCO open channel and the SCO open channel response commands sent to the
Bluetooth device. For more information about opening a SCO channel, see
[_BRB_SCO_OPEN_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_open_channel).

### `BrbScoCloseChannel`

Defines the format of a SCO close channel command sent to the Bluetooth device. For more
information about closing a SCO channel, see
[_BRB_SCO_CLOSE_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_close_channel).

### `BrbScoFlushChannel`

Defines the format of a SCO flush channel command. For more information about flushing a SCO
channel, see
[_BRB_SCO_FLUSH_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_flush_channel).

### `BrbScoTransfer`

Defines the format of a command that reads isochronous data from or writes data to a SCO channel
from a Bluetooth device. For more information, see
[_BRB_SCO_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_transfer).

### `BrbScoGetChannelInfo`

Defines the format of a command that reads the settings of a SCO channel to a Bluetooth device.
For more information about SCO transfers, see
[_BRB_SCO_GET_CHANNEL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_get_channel_info).

### `BrbScoGetSystemInfo`

Defines the format of a command that reads the SCO settings of the local system. For more
information about getting local SCO settings, see
[_BRB_SCO_GET_SYSTEM_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_get_system_info).

### `BrbAclGetMode`

Defines the format of a command to get the current ACL mode. For more information about getting
the current ACL mode, see
[_BRB_ACL_GET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_acl_get_mode).

### `BrbAclEnterActiveMode`

Defines the format of a command to enter active ACL mode. For more information about entering
active ACL mode, see
[_BRB_ACL_ENTER_ACTIVE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_acl_enter_active_mode).

### `BrbL2caOpenEnhancedChannel`

Defines the format of the enhanced L2CAP open channel and the enhanced L2CAP open channel response commands sent to
the Bluetooth device. For more information about opening an enhanced L2CAP channel, see
[_BRB_L2CA_OPEN_ENHANCED_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_open_enhanced_channel). This member is present in Windows 8 and later versions of Windows.

## See also

[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header)

[_BRB_ACL_ENTER_ACTIVE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_acl_enter_active_mode)

[_BRB_ACL_GET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_acl_get_mode)

[_BRB_GET_DEVICE_INTERFACE_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_get_device_interface_string)

[_BRB_GET_LOCAL_BD_ADDR](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_get_local_bd_addr)

[_BRB_L2CA_ACL_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_acl_transfer)

[_BRB_L2CA_CLOSE_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_close_channel)

[_BRB_L2CA_OPEN_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_open_channel)

[_BRB_L2CA_PING](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_ping)

[_BRB_L2CA_REGISTER_SERVER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_register_server)

[_BRB_L2CA_UNREGISTER_SERVER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_unregister_server)

[_BRB_L2CA_UPDATE_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_update_channel)

[_BRB_PSM](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_psm)

[_BRB_SCO_CLOSE_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_close_channel)

[_BRB_SCO_FLUSH_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_flush_channel)

[_BRB_SCO_GET_CHANNEL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_get_channel_info)

[_BRB_SCO_GET_SYSTEM_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_get_system_info)

[_BRB_SCO_OPEN_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_open_channel)

[_BRB_SCO_REGISTER_SERVER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_register_server)

[_BRB_SCO_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_transfer)

[_BRB_SCO_UNREGISTER_SERVER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_unregister_server)