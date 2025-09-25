# _IDE_REQUEST_BLOCK structure

## Description

The IDE_REQUEST_BLOCK structure defines an IDE request block.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `Function`

Specifies the category that the request belongs to. The table below describes the classification of the I/O requests.

|  |  |  |
| --- | --- | --- |
| **Function** | **Sub-commands** | **Description** |
| IRB_FUNCTION_ATA_COMMAND | IRB_FUNCTION_ATA_IDENTIFY<br><br>IRB_FUNCTION_ATA_READ<br><br>IRB_FUNCTION_ATA_WRITE<br><br>IRB_FUNCTION_ATA_FLUSH<br><br>IRB_FUNCTION_ATA_SMART | Indicates that the IRB contains an IdeTaskFile that describes the ATA command. The sub-commands indicate finer grouping of request for faster lookup. |
| IRB_FUNCTION_ATAPI_COMMAND | IRB_FUNCTION_REQUEST_SENSE | Indicates that the IRB contains a CDB that describes the ATAPI command. |
| IRB_FUNCTION_MINIPORT_COMMAND | IRB_FUNCTION_ADAPTER_FLUSH<br><br>IRB_FUNCTION_SHUTDOWN<br><br>IRB_FUNCTION_POWER_CHANGE<br><br>IRB_FUNCTION_POWER_REBOOT<br><br>IRB_FUNCTION_LUN_RESET<br><br>IRB_FUNCTION_MINIPORT_IOCTL | Indicates that the IRB is for the miniport. It is the responsibility of the miniport to interpret the command appropriately. |

### `IrbStatus`

The miniport must set this member to indicates the status of the specified operation. The table below describes the various **IrbStatus** values and their meaning.

|  |  |
| --- | --- |
| **Value** | **Meaning** |
| IRB_STATUS_PENDING | Indicates that the request is in progress. The port driver initializes **IrbStatus** to this value. A miniport driver should never set the **IrbStatus** member to this value. |
| IRB_STATUS_SUCCESS | Indicates that the request was completed successfully. |
| IRB_STATUS_DATALENGTH_MISMATCH | Indicates that a data underrun or overrun error occurred. The miniport must update the DataTransferLength field in the IRB to indicate the actual amount of data that was transferred in the case of an underrun. |
| IRB_STATUS_DEVICE_ERROR | Indicates that the device returned an error. The miniport driver must update the *AtaStatus* and *AtaError* fields in the Irb to the contents of the device ATA status and error register at the completion of the command. |
| IRB_STATUS_INVALID_REQUEST | Indicates that the miniport does not support the given request. |
| IRB_STATUS_BUS_RESET | Indicates that a bus reset occurred while processing the given request. |
| IRB_STATUS_SELECTION_TIMEOUT | Indicates that the destination device could not be selected. |
| IRB_STATUS_BUSY | Indicates that the device is busy. The port driver retries any request completed with this status. A request completed with busy status is retried only once. It is the responsibility of the miniport driver to pause the request queue using **AtaPortDeviceBusy** if the device cannot handle request for a certain period of time. |
| IRB_STATUS_AUTOSENSE_VALID | IRB_STATUS_AUTOSENSE_VALID is a bitmask that indicates valid sense data in the *SenseInfoBuffer* member of the IRB. |
| IRB_STATUS_RETURN_TASKFILE_VALID | IRB_STATUS_RETURN_TASKFILE_VALID is a bitmask that indicates a valid return task file in the *SenseInfoBuffer* member of the IRB. |

### `AtaStatus`

Indicates the status returned by the device in its status register. The miniport driver should update this field when completing an IRB with *IRB_STATUS_DEVICE_ERROR*.

### `AtaError`

Indicates the error value returned by the device in its error register. The miniport driver should update this field when completing an IRB with *IRB_STATUS_DEVICE_ERROR*.

### `Channel`

Specifies the channel number.

### `TargetId`

Specifies the target ID of the device.

### `Lun`

Specifies the logical unit number of the device.

### `CdbLength`

Specifies the length in bytes of the buffer pointed to by **Cdb**.

### `SenseInfoBufferLength`

Specifies the length in bytes of the buffer pointed to by **SenseInfoBuffer**.

### `SenseInfoBufferType`

Specifies the type of data structure returned in **SenseInfoBuffer**. Because ATA commands don't have a need for the request sense command, ATA_PASS_THROUGH commands use **SenseInfoBuffer** to return task file information. For ATA_PASS_THROUGH commands, as identified in the **IrbFlags** member, the appropriate return **TaskFile** size should be reported as either SENSE_INFO_BUFFER_RETURN_TYPE_28BIT_TASKFILE or

SENSE_INFO_BUFFER_RETURN_TYPE_48BIT_TASKFILE.

### `QueueTag`

The queue tag for this IRB. The port driver sets this field to 0.

### `ReservedAsUlong`

Reserved for future use.

### `IrbFlags`

Qualifies the request with certain actions that need to be performed. The table below describes them in detail.

|  |  |
| --- | --- |
| **Flag** | **Description** |
| IRB_FLAGS_DRDY_REQUIRED | Indicates that the miniport driver must wait for the device to set the DRDY bit in the ATA status register before issuing this command. |
| IRB_FLAGS_USE_DMA | Indicates that the request has an associated scatter/gather list and the miniport driver could use DMA to transfer data for this request. |
| IRB_FLAGS_MAP_BUFFERS | Indicates that the **DataBuffer** field in the IRB is mapped. The miniport can safely access **DataBuffer** when this flag is set. The miniport driver must not access **DataBuffer** if the flag is not set. The miniport driver could request the port driver to map the data buffer by setting this flag in the IRB in its **IdeHwBuildIo** routine. |
| IRB_FLAGS_48BIT | Indicates that the ATA command in the IRB belongs to the 48 bit LBA feature set. The **Previous** field in the *_IDE_TASK_FILE* structure is valid when this flag is set. |
| IRB_FLAGS_PIO_MULTIPLE | Indicates that the ATA command is to be transferred using the ATA PIO Multiple method. |
| IRB_FLAGS_RETURN_RESULTS | Indicates that the ATA return task file is to be copied to **SenseInfoBuffer**. |
| IRB_FLAGS_DATA_IN | Indicates that the data is to be transferred from the device to the host system (a read operation). |
| IRB_FLAGS_DATA_OUT | Indicates that the data is to be transferred to the device from the host system ( a write operation). |
| IRB_FLAGS_DISCARDABLE | Indicates that the command shall be done in a best effort manner. (note: this is not currently employed by ATAport). |
| IRB_FLAGS_HIGH_PRIORITY | Indicates that this IRB is to be processed as soon as possible, before non-high-priority IRBs currently in the ATA miniport. |

### `TimeOutValue`

Indicates the time in seconds after which the request will time out.

### `DataTransferLength`

Contains the length in bytes of the data buffer that contains data to be transferred.

### `IrbExtension`

Pointer to the per-request extension allocated by the port driver.

### `DataBuffer`

Pointer to the buffer where the data resides.

### `SenseInfoBuffer`

Pointer to the buffer which holds the sense data.

### `NextIrb`

Pointer to the next IRB to be processed. The port driver sets this to **NULL**. The miniport driver can use this field to link IRBs together.

### `Reserved`

Reserved for future use.

### `IdeTaskFile`

Contains a structure of type [IDE_TASK_FILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_task_file) that holds the IDE task file for the indicated controller. This member is defined whenever the result of a bitwise AND between the **Function** member and IRB_FUNCTION_ATA_COMMAND is nonzero.

### `Cdb`

Contains a command descriptor block (CDB). This member is defined whenever the result of a bitwise AND between the **Function** member and IRB_FUNCTION_ATAPI_COMMAND is nonzero.

### `PowerChange`

Indicates an enumeration value of type [POWER_CHANGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_power_info) that defines a power state transition. This member is defined whenever **Function** is equal to IRB_FUNCTION_POWER_CHANGE.

### `AsUChar`

Provides a means of accessing members **IdeTaskFile**, **PowerChange**, and **Cdb** as unsigned character data.

## Remarks

The IDE_REQUEST_BLOCK structure provides a functionality similar to the [SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block) but with characteristics more suitable for managing devices on an IDE bus.

## See also

[AtaportDeviceBusy](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportdevicebusy)

[IDE_TASK_FILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_task_file)

[POWER_CHANGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_power_info)

[SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block)