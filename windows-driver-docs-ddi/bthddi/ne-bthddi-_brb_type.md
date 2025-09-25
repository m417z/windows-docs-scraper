# _BRB_TYPE enumeration

## Description

The **BRB_TYPE** enumeration type is used to determine the Bluetooth request block when a profile driver
[builds and sends](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a BRB.

## Constants

### `BRB_HCI_GET_LOCAL_BD_ADDR`

This value declares a
[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb) of type
**BRB_HCI_GET_LOCAL_BD_ADDR**.

### `BRB_L2CA_REGISTER_SERVER`

This value declares a
[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb) of type
**BRB_L2CA_REGISTER_SERVER**.

### `BRB_L2CA_UNREGISTER_SERVER`

This value declares a
[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb) of type
**BRB_L2CA_UNREGISTER_SERVER**.

### `BRB_L2CA_OPEN_CHANNEL`

This value declares a
[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb) of type
**BRB_L2CA_OPEN_CHANNEL**.

### `BRB_L2CA_OPEN_CHANNEL_RESPONSE`

This value declares a
[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb) of type
**BRB_L2CA_OPEN_CHANNEL_RESPONSE**.

### `BRB_L2CA_CLOSE_CHANNEL`

This value declares a
[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb) of type
**BRB_L2CA_CLOSE_CHANNEL**.

### `BRB_L2CA_ACL_TRANSFER`

This value declares a
[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb) of type
**BRB_L2CA_ACL_TRANSFER**.

### `BRB_L2CA_UPDATE_CHANNEL`

This value declares a
[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb) of type
**BRB_L2CA_UPDATE_CHANNEL**.

### `BRB_L2CA_PING`

This value declares a
[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb) of type
**BRB_L2CA_PING**.

### `BRB_L2CA_INFO_REQUEST`

For internal use only. Do not use.

### `BRB_REGISTER_PSM`

This value declares a
[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb) of type
**BRB_REGISTER_PSM**.

### `BRB_UNREGISTER_PSM`

This value declares a
[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb) of type
**BRB_UNREGISTER_PSM**.

### `BRB_SCO_REGISTER_SERVER`

This value declares a
[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb) of type
**BRB_SCO_REGISTER_SERVER**.

### `BRB_SCO_UNREGISTER_SERVER`

This value declares a
[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb) of type
**BRB_SCO_UNREGISTER_SERVER**.

### `BRB_SCO_OPEN_CHANNEL`

This value declares a
[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb) of type
**BRB_SCO_OPEN_CHANNEL**.

### `BRB_SCO_OPEN_CHANNEL_RESPONSE`

This value declares a
[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb) of type
**BRB_SCO_OPEN_CHANNEL_RESPONSE**.

### `BRB_SCO_CLOSE_CHANNEL`

This value declares a
[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb) of type
**BRB_SCO_CLOSE_CHANNEL**.

### `BRB_SCO_TRANSFER`

This value declares a
[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb) of type
**BRB_SCO_TRANSFER**.

### `BRB_SCO_GET_CHANNEL_INFO`

This value declares a
[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb) of type
**BRB_SCO_GET_CHANNEL_INFO**.

### `BRB_SCO_GET_SYSTEM_INFO`

This value declares a
[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb) of type
**BRB_SCO_GET_SYSTEM_INFO**.

### `BRB_SCO_FLUSH_CHANNEL`

This value declares a
[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb) of type
**BRB_SCO_FLUSH_CHANNEL**.

### `BRB_SCO_OPEN_UNMANAGED_CHANNEL`

This value declares a
[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb) of type
**BRB_SCO_OPEN_CHANNEL**.

### `BRB_SCO_OPEN_UNMANAGED_CHANNEL_RESPONSE`

This value declares a
[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb) of type
**BRB_SCO_OPEN_CHANNEL_RESPONSE**.

### `BRB_L2CA_OPEN_ENHANCED_CHANNEL`

This value declares a
[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb) of type
**BRB_L2CA_OPEN_CHANNEL**. This value is present in Windows 8 and later versions of Windows.

### `BRB_L2CA_OPEN_ENHANCED_CHANNEL_RESPONSE`

This value declares a
[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb) of type
**BRB_L2CA_OPEN_CHANNEL_RESPONSE**. This value is present in Windows 8 and later versions of Windows.

### `BRB_ACL_GET_MODE`

### `BRB_ACL_ENTER_ACTIVE_MODE`

This value declares a
[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb) of type
**BRB_ACL_ENTER_ACTIVE_MODE**.

### `BRB_STORED_LINK_KEY`

For internal use only. Do not use.

### `BRB_GET_DEVICE_INTERFACE_STRING`

This value declares a
[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb) of type
**BRB_GET_DEVICE_INTERFACE_STRING**.

## Remarks

The type of BRB is specified in the
**Type** member of the
[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header) structure. The
[BthAllocateBrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbth_allocate_brb) and
[BthInitializeBrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbth_initialize_brb) functions automatically
set the
**Type** member.

## See also

[BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb)

[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header)

[BthAllocateBrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbth_allocate_brb)

[BthInitializeBrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbth_initialize_brb)

[IOCTL_INTERNAL_BTH_SUBMIT_BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_internal_bth_submit_brb)