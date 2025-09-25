# _SCSI_PNP_REQUEST_BLOCK structure (srb.h)

## Description

The**SCSI_PNP_REQUEST_BLOCK** structure is a special version of a [SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block) that is used for plug and play (PNP) requests.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `Length`

The size, in bytes, of the **SCSI_PNP_REQUEST_BLOCK** structure.

### `Function`

The operation to perform. For the **SCSI_PNP_REQUEST_BLOCK** structure, this member is always set to SRB_FUNCTION_PNP.

### `SrbStatus`

The status of the completed request. The miniport driver should set this value before notifying the Storport driver that the request has completed. A miniport driver notifies the Storport driver that the request has completed by calling the [StorPortNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportnotification) routine with a notification type of **RequestComplete**. For a list of possible status values, see [SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block).

### `PnPSubFunction`

This member is not currently used. Miniport drivers ignore this member.

### `PathId`

The SCSI port or bus identifier for the request. This value is zero based.

### `TargetId`

The target controller or device identifier on the bus.

### `Lun`

The logical unit number (LUN) of the device.

### `PnPAction`

The plug and play action to perform. This member can have one of the following values:

| Value | Meaning |
| --- | --- |
| **StorStartDevice**<br><br>0x00 | Start the device. |
| **StorRemoveDevice**<br><br>0x02 | Remove the device. |
| **StorStopDevice**<br><br>0x04 | Stop the device. |
| **StorQueryCapabilities**<br><br>0x09 | Query the capabilities of the device. |
| **StorQueryResourceRequirements**<br><br>0x0B | Query the resource requirements for the device. |
| **StorFilterResourceRequirements**<br><br>0x0D | Filter the resource requirements for the device. |
| **StorSupriseRemoval**<br><br>0x17 | Surprise Removal of the device. This value was added in Windows 7. |

### `SrbFlags`

Miniport driver should ignore this member.

### `DataTransferLength`

Miniport driver should ignore this member.

### `TimeOutValue`

The interval, in seconds, that the request can execute before the Storport driver determines that the request has timed out.

### `DataBuffer`

Miniport driver should ignore this member.

### `SenseInfoBuffer`

Miniport driver should ignore this member.

### `NextSrb`

Miniport driver should ignore this member.

### `OriginalRequest`

Miniport driver should ignore this member.

### `SrbExtension`

A pointer to the SRB extension. A miniport driver must not use this member if it set **SrbExtensionSize** to zero in the [HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_initialization_data) structure. The Storport driver does not initialize the memory that this member points to. The HBA can directly access the data that the miniport driver writes into the SRB extension. A miniport driver can obtain the physical address of the SRB extension by calling the [StorPortGetPhysicalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetphysicaladdress) routine.

### `SrbPnPFlags`

The PNP flags. Currently, the only flag allowed is SRB_PNP_FLAGS_ADAPTER_REQUEST, which indicates that the PNP request is for the adapter, and not for one of the devices on the adapter. If this flag is set, the miniport driver should ignore the values in the **PathId**, **TargetId**, and **Lun**.

### `Reserved`

Reserved for system use.

### `Reserved4`

Reserved for system use.

## Remarks

The Storport driver sends **SCSI_PNP_REQUEST_BLOCK** requests to a miniport driver to notify the miniport driver of Windows plug and play events that affect storage devices that are connected to the adapter.

The Storport driver calls [HwStorBuildIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_buildio) to pass SRBs to the miniport driver. **HwStorBuildIo** checks the **Function** member of the SRB to determine the type of the SRB. If the **Function** member is set to SRB_FUNCTION_PNP, the SRB is a structure of type **SCSI_PNP_REQUEST_BLOCK**.

## See also

[HwStorBuildIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_buildio)

[SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block)

[StorPortNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportnotification)