# StorPortGetSystemPortNumber function

## Description

The **StorPortGetSystemPortNumber** routine retrieves the system assigned port number for a storage adapter.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `Address` [in, out]

A pointer to a storage address structure formatted as [STOR_ADDR_BTL8](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-_stor_addr_btl8). On return, the **Port** member of this structure will contain the port value assigned to the adapter.

## Return value

**StorPortGetSystemPortNumber** returns one of the following status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_INVALID_DEVICE_STATE** | A port number value is not yet assigned to the storage adapter. |
| **STOR_STATUS_SUCCESS** | Indicates that port number of the storage adapter was returned successfully. |
| **STOR_STATUS_INVALID_PARAMETER** | The *HwDeviceExtension* was **NULL**.<br><br>-or-<br><br>The **Type** member of *Address* is not **STOR_ADDRESS_TYPE_BTL8**. |

## Remarks

The address structure pointed to by *Address* is allocated and formatted as [STOR_ADDR_BTL8](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-_stor_addr_btl8). The **Type** member of *Address* must be set to **STOR_ADDRESS_TYPE_BTL8** and the **Length** member *Address* must be greater than or equal to **STOR_ADDR_BTL8_ADDRESS_LENGTH**.

## See also

[STOR_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-_stor_address)

[STOR_ADDR_BTL8](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-_stor_addr_btl8)