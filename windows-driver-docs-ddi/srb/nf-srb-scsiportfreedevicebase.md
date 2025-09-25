# ScsiPortFreeDeviceBase function

## Description

The **ScsiPortFreeDeviceBase** routine frees a range of device I/O or memory space addresses previously mapped into the system address space with **ScsiPortGetDeviceBase**.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the hardware device extension. This is a per-HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the HBA's mapped access ranges. This area is available to the miniport driver in the **DeviceExtension->HwDeviceExtension** member of the HBA's device object immediately after the miniport driver calls [ScsiPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportinitialize). The port driver frees this memory when it removes the device.

### `MappedAddress` [in]

Pointer to the base address of the range to be freed. This address must be the same as that returned by [ScsiPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetdevicebase).

## Return value

None

## Remarks

If a miniport driver's [HwScsiFindAdapter](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85)) routine determines that the driver does not need a particular mapped base address for an adapter, it must release the mapping by calling this routine. For example, when a miniport driver determines there are no supported HBAs on a particular I/O bus, it must call **ScsiPortFreeDeviceBase** with each mapped address returned by **ScsiPortGetDeviceBase**, if any calls to this routine were made.

**ScsiPortFreeDeviceBase** can be called only from miniport driver's [HwScsiFindAdapter](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85)) routine. Calls from other miniport driver routines will result in system failure or incorrect operation for the caller.

## See also

[HwScsiFindAdapter](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85))

[ScsiPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetdevicebase)