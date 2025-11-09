# StorPortGetPhysicalAddress function

## Description

The **StorPortGetPhysicalAddress** routine converts a given virtual address range to a physical address range for a DMA operation.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver in the **DeviceExtension->HwDeviceExtension** member of the device object for the HBA immediately after the miniport driver calls [StorPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `Srb` [in, optional]

Pointer to the SCSI request block if the virtual address to be converted comes from that SRB's **DataBuffer**, **SenseInfoBuffer**, or **SrbExtension** member. Otherwise, this parameter must be **NULL**.

### `VirtualAddress` [in]

Pointer to the base virtual address to be converted. If this virtual address falls within the range for an SRB-supplied **DataBuffer**, the caller also must provide the *Srb* pointer.

### `Length` [out]

Pointer to a value indicating the number of bytes mapped, starting at the returned physical address.

## Return value

**StorPortGetPhysicalAddress** returns the corresponding physical address for a given virtual address. If the given address cannot be converted, the function returns **NULL**.

## Remarks

If the virtual address passed to **StorPortGetPhysicalAddress** is obtained from [StorPortAllocateContiguousMemorySpecifyCacheNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportallocatecontiguousmemoryspecifycachenode), the value returned for *Length* should be ignored.

Starting in Windows 8, the *Srb* parameter may point to either [SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block) or [STORAGE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block). If the function identifier in the **Function** field of *Srb* is **SRB_FUNCTION_STORAGE_REQUEST_BLOCK**, the SRB is a **STORAGE_REQUEST_BLOCK** request structure.

**StorPortGetPhysicalAddress** uses **STOR_PHYSICAL_ADDRESS** to represent physical addresses.

```cpp
typedef PHYSICAL_ADDRESS STOR_PHYSICAL_ADDRESS, *PSTOR_PHYSICAL_ADDRESS;

```

The **STOR_PHYSICAL_ADDRESS** type is an operating system-independent data type that Storport miniport drivers use to represent either a physical addresses or a bus-relative address.

## See also

[SCSI_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_scsi_request_block)

[STORAGE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_storage_request_block)

[ScsiPortGetPhysicalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetphysicaladdress)