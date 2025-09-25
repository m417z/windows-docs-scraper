# ScsiPortGetLogicalUnit function

## Description

The **ScsiPortGetLogicalUnit** routine returns a pointer to the miniport driver's per-LU storage area for a given peripheral.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the hardware device extension. This is a per-HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the HBA's mapped access ranges. This area is available to the miniport driver in the **DeviceExtension->HwDeviceExtension** member of the HBA's device object immediately after the miniport driver calls [ScsiPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportinitialize). The port driver frees this memory when it removes the device.

### `PathId` [in]

Identifies the SCSI bus.

### `TargetId` [in]

Identifies the target controller or device on the bus.

### `Lun` [in]

Identifies the logical unit number of the target device.

## Return value

**ScsiPortGetLogicalUnit** returns a pointer to the miniport driver's storage area for the requested logical unit. If the operating system-specific port driver considers this logical unit to be nonexistent, it returns **NULL**.

## Remarks

**ScsiPortGetLogicalUnit** is irrelevant if the miniport driver's **DriverEntry** routine specified zero for the **LuExtensionSize** in the HW_INITIALIZATION_DATA when it called **ScsiPortInitialize**. Otherwise, the operating system-specific port driver allocates and initializes with zeros a set of LU extensions of the specified size for the miniport driver to use.

Per-LU storage can be used to store data relevant to a particular peripheral, such as saved data pointers. To access this area, the miniport driver calls **ScsiPortGetLogicalUnit** when the driver is maintaining information about the state of or current operation for any particular peripheral.

The operating system-specific port driver can consider a logical unit to be nonexistent if there is no active request for that logical unit and the device has never been successfully selected.

## See also

[DriverEntry of SCSI Miniport Driver](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[HW_INITIALIZATION_DATA (SCSI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_hw_initialization_data)

[ScsiPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportinitialize)

[ScsiPortMoveMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportmovememory)