# _BRB_HEADER structure

## Description

The BRB_HEADER structure contains header information about a Bluetooth request block (BRB), including
information about the BRB type that the Bluetooth driver stack uses to determine which kind of BRB type to
process.

## Members

### `ListEntry`

A LIST_ENTRY structure used by the current owner of the BRB to place the BRB in a queue.

### `Length`

The size, in bytes, of the BRB, including the BRB_HEADER structure. The
[BthAllocateBrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbth_allocate_brb),
[BthInitializeBrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbth_initialize_brb) and
[BthReuseBrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbth_reuse_brb) functions automatically set this
member.

### `Version`

For internal use only. Do not use.

### `Type`

The Bluetooth request block type. The
[BthAllocateBrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbth_allocate_brb),
[BthInitializeBrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbth_initialize_brb) and
[BthReuseBrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbth_reuse_brb) functions automatically set this
member.Possible values include:

* BRB_HCI_GET_LOCAL_BD_ADDR
* BRB_L2CA_REGISTER_SERVER
* BRB_L2CA_UNREGISTER_SERVER
* BRB_L2CA_OPEN_CHANNEL
* BRB_L2CA_OPEN_CHANNEL_RESPONSE
* BRB_L2CA_CLOSE_CHANNEL
* BRB_L2CA_ACL_TRANSFER
* BRB_L2CA_UPDATE_CHANNEL
* BRB_L2CA_PING
* BRB_REGISTER_PSM
* BRB_UNREGISTER_PSM
* BRB_SCO_REGISTER_SERVER
* BRB_SCO_UNREGISTER_SERVER
* BRB_SCO_OPEN_CHANNEL
* BRB_SCO_OPEN_CHANNEL_RESPONSE
* BRB_SCO_CLOSE_CHANNEL
* BRB_SCO_TRANSFER
* BRB_SCO_GET_CHANNEL_INFO
* BRB_SCO_GET_SYSTEM_INFO
* BRB_SCO_FLUSH_CHANNEL
* BRB_ACL_GET_MODE
* BRB_ACL_ENTER_ACTIVE_MODE
* BRB_GET_DEVICE_INTERFACE_STRING

### `BthportFlags`

For internal use only. Do not use.

### `Status`

The NTSTATUS code that is passed when the BRB call completes.

### `BtStatus`

The Bluetooth status code (BTSTATUS) that corresponds to the NTSTATUS code that is passed in the
**Status** member. Possible values include:

* BTH_ERROR_SUCCESS
* BTH_ERROR_ACL_CONNECTION_ALREADY_EXISTS
* BTH_ERROR_AUTHENTICATION_FAILURE
* BTH_ERROR_COMMAND_DISALLOWED
* BTH_ERROR_CONNECTION_TIMEOUT
* BTH_ERROR_ENCRYPTION_MODE_NOT_ACCEPTABLE
* BTH_ERROR_HARDWARE_FAILURE
* BTH_ERROR_HOST_REJECTED_LIMITED_RESOURCES
* BTH_ERROR_HOST_REJECTED_PERSONAL_DEVICE
* BTH_ERROR_HOST_REJECTED_SECURITY_REASONS
* BTH_ERROR_HOST_TIMEOUT
* BTH_ERROR_INSTANT_PASSED
* BTH_ERROR_INVALID_HCI_PARAMETER
* BTH_ERROR_INVALID_LMP_PARAMETERS
* BTH_ERROR_KEY_MISSING
* BTH_ERROR_LMP_PDU_NOT_ALLOWED
* BTH_ERROR_LMP_RESPONSE_TIMEOUT
* BTH_ERROR_LMP_TRANSACTION_COLLISION
* BTH_ERROR_LOCAL_HOST_TERMINATED_CONNECTION
* BTH_ERROR_MAX_NUMBER_OF_CONNECTIONS
* BTH_ERROR_MAX_NUMBER_OF_SCO_CONNECTIONS
* BTH_ERROR_MEMORY_FULL
* BTH_ERROR_NO_CONNECTION
* BTH_ERROR_PAGE_TIMEOUT
* BTH_ERROR_PAIRING_NOT_ALLOWED
* BTH_ERROR_PAIRING_WITH_UNIT_KEY_NOT_SUPPORTED
* BTH_ERROR_QOS_IS_NOT_SUPPORTED
* BTH_ERROR_REMOTE_LOW_RESOURCES
* BTH_ERROR_REMOTE_POWERING_OFF
* BTH_ERROR_REMOTE_USER_ENDED_CONNECTION
* BTH_ERROR_REPEATED_ATTEMPTS
* BTH_ERROR_ROLE_CHANGE_NOT_ALLOWED
* BTH_ERROR_SCO_AIRMODE_REJECTED
* BTH_ERROR_SCO_INTERVAL_REJECTED
* BTH_ERROR_SCO_OFFSET_REJECTED
* BTH_ERROR_UKNOWN_LMP_PDU
* BTH_ERROR_UNIT_KEY_NOT_USED
* BTH_ERROR_UNKNOWN_HCI_COMMAND
* BTH_ERROR_UNSPECIFIED_ERROR
* BTH_ERROR_UNSUPPORTED_FEATURE_OR_PARAMETER
* BTH_ERROR_UNSUPPORTED_LMP_PARM_VALUE
* BTH_ERROR_UNSUPPORTED_REMOTE_FEATURE

### `Context`

For internal use only. Do not use.

### `ClientContext`

The client context that is associated with the BRB call. The caller can use this member to store a
pointer or other information.

### `Reserved`

Reserved for future use. Do not use.

## Remarks

The BRB_HEADER structure contains common types of information about the specified BRB. The BRB_HEADER
structure is used by all BRB structures that are used as the input buffer for
[IOCTL_INTERNAL_BTH_SUBMIT_BRB](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_internal_bth_submit_brb) IOCTLs.

Profile drivers should not modify any of the members of the BRB_HEADER structure except
**ClientContext**.

## See also

[BthAllocateBrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbth_allocate_brb)

[BthInitializeBrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbth_initialize_brb)

[BthReuseBrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/nc-bthddi-pfnbth_reuse_brb)