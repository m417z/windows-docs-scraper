# ScsiPortGetPhysicalAddress function

## Description

The **ScsiPortGetPhysicalAddress** routine converts a given virtual address range to a physical address range for a DMA operation.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the hardware device extension. This is a per-HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the HBA's mapped access ranges. This area is available to the miniport driver in the **DeviceExtension->HwDeviceExtension** member of the HBA's device object immediately after the miniport driver calls [ScsiPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportinitialize). The port driver frees this memory when it removes the device.

### `Srb` [in]

Pointer to the SCSI request block if the *VirtualAddress* to be converted comes from that SRB's **DataBuffer** member or, possibly, from the **SenseInfoBuffer**. Otherwise, this parameter must be **NULL**.

### `VirtualAddress` [in]

Pointer to the base virtual address to be converted. If this virtual address falls within the range for an SRB-supplied **DataBuffer**, the caller also must provide the *Srb* pointer.

### `Length` [out]

Returns the number of bytes mapped, starting at the returned physical address.

## Return value

**ScsiPortGetPhysicalAddress** returns the corresponding physical address for a given *VirtualAddress*. If the given address cannot be converted, it returns **NULL**.

## Remarks

Miniport drivers of bus-master HBAs call **ScsiPortGetPhysicalAddress** to get mapped physical address ranges to be used during DMA operations. For example, **ScsiPortGetPhysicalAddress** can be used to build a scatter/gather list for data transfers that span pages. Note that the *Length* returned can be greater than the size of the **DataBuffer** in a given SRB.

If a non-**NULL***Srb* is passed, the *VirtualAddress* either must be within the range of the **DataBuffer** of the SRB or must be a pointer from the **SenseInfoBuffer**. Otherwise, the given *VirtualAddress* must be in the miniport driver's uncached extension, the **SrbExtension**, or the **SenseInfoBuffer**.

A miniport driver can call **ScsiPortGetPhysicalAddress** to translate an extension address only if that miniport driver's **DriverEntry** routine set **NeedPhysicalAddresses** to **TRUE** in the HW_INITIALIZATION_DATA when it called **ScsiPortInitialize**.

Due to constraints on some buses, such as ISA, the address returned by this routine is not guaranteed to match the address returned by an analogous outside routine (such as **MmGetPhysicalAddress**). A miniport driver should call only **ScsiPort***Xxx* routines to be portable.

**ScsiPortGetPhysicalAddress** uses **SCSI_PHYSICAL_ADDRESS** to represent physical addresses.

```cpp
typedef PHYSICAL_ADDRESS SCSI_PHYSICAL_ADDRESS, *PSCSI_PHYSICAL_ADDRESS;

```

The **SCSI_PHYSICAL_ADDRESS** type is an operating system-independent data type that SCSI miniport drivers use to represent either a physical addresses or a bus-relative address.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## See also

[DriverEntry of SCSI Miniport Driver](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[HW_INITIALIZATION_DATA (SCSI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_hw_initialization_data)

[SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block)

[ScsiPortGetUncachedExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetuncachedextension)

[ScsiPortGetVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetvirtualaddress)