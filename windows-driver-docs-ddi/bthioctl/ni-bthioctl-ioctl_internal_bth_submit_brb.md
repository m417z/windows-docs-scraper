# IOCTL_INTERNAL_BTH_SUBMIT_BRB IOCTL

## Description

Profile drivers use **IOCTL_INTERNAL_BTH_SUBMIT_BRB** to submit a Bluetooth Request Block (BRB) to the
Bluetooth driver stack.

## Parameters

### Major code

[IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control)

### Input buffer

The
**Parameters.Others.Argument1** member points to the address an instance of the
structure that corresponds to the BRB that the profile driver intends to issue. The following list
describes the structures that correspond to specific BRBs.

| Bluetooth Request Block (BRB) | Corresponding structure |
| --- | --- |
| BRB_HCI_GET_LOCAL_BD_ADDR | [_BRB_GET_LOCAL_BD_ADDR](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_get_local_bd_addr) |
| BRB_L2CA_REGISTER_SERVER | [_BRB_L2CA_REGISTER_SERVER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_register_server) |
| BRB_L2CA_UNREGISTER_SERVER | [_BRB_L2CA_UNREGISTER_SERVER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_unregister_server) |
| BRB_L2CA_OPEN_CHANNEL | [_BRB_L2CA_OPEN_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_open_channel) |
| BRB_L2CA_OPEN_CHANNEL_RESPONSE | [_BRB_L2CA_OPEN_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_open_channel) |
| BRB_L2CA_CLOSE_CHANNEL | [_BRB_L2CA_CLOSE_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_close_channel) |
| BRB_L2CA_ACL_TRANSFER | [_BRB_L2CA_ACL_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_acl_transfer) |
| BRB_L2CA_UPDATE_CHANNEL | [_BRB_L2CA_UPDATE_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_update_channel) |
| BRB_L2CA_PING | [_BRB_L2CA_PING](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_ping) |
| BRB_REGISTER_PSM | [_BRB_PSM](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_psm) |
| BRB_UNREGISTER_PSM | [_BRB_PSM](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_psm) |
| BRB_SCO_REGISTER_SERVER | [_BRB_SCO_REGISTER_SERVER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_register_server) |
| BRB_SCO_UNREGISTER_SERVER | [_BRB_SCO_UNREGISTER_SERVER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_unregister_server) |
| BRB_SCO_OPEN_CHANNEL | [_BRB_SCO_OPEN_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_open_channel) |
| BRB_SCO_OPEN_CHANNEL_RESPONSE | [_BRB_SCO_OPEN_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_open_channel) |
| BRB_SCO_CLOSE_CHANNEL | [_BRB_SCO_CLOSE_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_close_channel) |
| BRB_SCO_TRANSFER | [_BRB_SCO_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_transfer) |
| BRB_SCO_GET_CHANNEL_INFO | [_BRB_SCO_GET_CHANNEL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_get_channel_info) |
| BRB_SCO_GET_SYSTEM_INFO | [_BRB_SCO_GET_SYSTEM_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_get_system_info) |
| BRB_SCO_FLUSH_CHANNEL | [_BRB_SCO_FLUSH_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_flush_channel) |
| BRB_ACL_GET_MODE | [_BRB_ACL_GET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_acl_get_mode) |
| BRB_ACL_ENTER_ACTIVE_MODE | [_BRB_ACL_ENTER_ACTIVE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_acl_enter_active_mode) |
| BRB_GET_DEVICE_INTERFACE_STRING | [_BRB_GET_DEVICE_INTERFACE_STRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_get_device_interface_string) |

### Input buffer length

The length of the structure.

### Output buffer

If the BRB returns output,
**Parameters->Others.Argument1** points to the same BRB that was passed as input. Output is
returned in the members of the associated BRB structure or in buffers that are specified in the BRB
structure.

### Output buffer length

The length of the structure

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the
**Information** member of the **STATUS_BLOCK** structure is set to the size, in bytes, of the Bluetooth
request block that was submitted. Otherwise, the
**Information** member is set to zero.

The
**Status** member is set to one of the values in the following table.

| Status value | Description |
| --- | --- |
| STATUS_SUCCESS | The IOCTL completed successfully. |
| STATUS_INVALID_DEVICE_REQUEST | The request sent to the remote device through the BRB structure was invalid. |
| STATUS_INVALID_PARAMETER | One or more of the input parameters was invalid. |
| STATUS_INVALID_BUFFER_SIZE or<br><br>STATUS_BUFFER_TOO_SMALL | The length of the supplied buffer was too small. |
| STATUS_NOT_IMPLEMENTED | The stack has not implemented the necessary module to process the BRB. |
| STATUS_NOT_SUPPORTED | The stack does not support this BRB. |
| STATUS_PENDING | The BRB is pending. |

## Remarks

Profile drivers use BRBs to handle most input, output, and connection tasks. A number of BRBs are
defined for these tasks, and each one uses a specific, corresponding structure. All BRBs share a common
header, which contains the type of the BRB. The Bluetooth driver stack uses the BRB header to correctly
interpret the remainder of the BRB. For more information about BRB headers, see the
[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header) structure.

For more information about how profile drivers use BRBs to communicate with the Bluetooth driver
stack, see
[Building and Sending a BRB](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)).

These BRBs must be called at IRQL <= PASSIVE_LEVEL.

## See also

[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header)

[BRB_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ne-bthddi-_brb_type)

[Building and Sending a BRB](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85))