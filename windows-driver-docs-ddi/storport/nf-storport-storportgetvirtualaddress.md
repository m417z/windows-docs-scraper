# StorPortGetVirtualAddress function

## Description

The **StorPortGetVirtualAddress** routine obtains a virtual address that maps to the indicated physical address.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [StorPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `PhysicalAddress` [in]

Specifies the physical address to be mapped. This value must have been returned by [StorPortGetPhysicalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetphysicaladdress) and must be from an uncached device extension or SRB extension.

## Return value

**StorPortGetVirtualAddress** returns a virtual address associated with the physical address indicated in the *PhysicalAddress* parameter. Typically, this physical address was obtained by a call to [StorPortGetPhysicalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetphysicaladdress).

## Remarks

The physical address must be an address that is obtained through a call to [StorPortGetPhysicalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetphysicaladdress).

**StorPortGetVirtualAddress** uses **STOR_PHYSICAL_ADDRESS** to represent physical addresses.

```cpp
typedef PHYSICAL_ADDRESS STOR_PHYSICAL_ADDRESS, *PSTOR_PHYSICAL_ADDRESS;

```

The **STOR_PHYSICAL_ADDRESS** type is an operating system-independent data type that Storport miniport drivers use to represent either a physical addresses or a bus-relative address.

## See also

[ScsiPortGetVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetvirtualaddress)