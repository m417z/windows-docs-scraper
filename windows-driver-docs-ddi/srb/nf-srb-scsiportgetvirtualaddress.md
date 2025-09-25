# ScsiPortGetVirtualAddress function

## Description

The **ScsiPortGetVirtualAddress** routine returns a virtual address associated with a physical address if the physical address was obtained by a call to **ScsiPortGetPhysicalAddress**.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the hardware device extension. This is a per-HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the HBA's mapped access ranges. This area is available to the miniport driver in the **DeviceExtension->HwDeviceExtension** member of the HBA's device object immediately after the miniport driver calls [ScsiPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportinitialize). The port driver frees this memory when it removes the device.

### `PhysicalAddress` [in]

Specifies the physical address to be mapped. This value must have been returned by **ScsiPortGetPhysicalAddress** and must be from an uncached device extension or SRB extension.

## Return value

**ScsiPortGetVirtualAddress** returns a mapped pointer for the given input address. If the *PhysicalAddress* value is invalid, it returns **NULL**.

## Remarks

**ScsiPortGetVirtualAddress** uses **SCSI_PHYSICAL_ADDRESS** to represent physical addresses.

```cpp
typedef PHYSICAL_ADDRESS SCSI_PHYSICAL_ADDRESS, *PSCSI_PHYSICAL_ADDRESS;

```

The **SCSI_PHYSICAL_ADDRESS** type is an operating system-independent data type that SCSI miniport drivers use to represent either a physical addresses or a bus-relative address.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## See also

[ScsiPortGetPhysicalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetphysicaladdress)

[ScsiPortGetUncachedExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetuncachedextension)