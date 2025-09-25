# StorPortGetLogicalUnit function

## Description

The **StorPortGetLogicalUnit** routine returns a pointer to the miniport driver's per-logical-unit storage area.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver as soon as the miniport driver's [**HwStorFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) routine is called. The port driver frees this memory when it removes the device.

### `PathId` [in]

Identifies the SCSI bus.

### `TargetId` [in]

Identifies the target controller or device on the bus.

### `Lun` [in]

Identifies the logical unit (LU) number of the target device.

## Return value

**StorPortGetLogicalUnit** returns a pointer to the miniport driver's storage area for the requested logical unit. If the logical unit does not exist, it returns **NULL**.

## Remarks

**StorPortGetLogicalUnit** is irrelevant if the miniport driver's **DriverEntry** routine specified zero for the **LuExtensionSize** in the [**HW_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_hw_initialization_data-r1)
when it called [**StorPortInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). Otherwise, the operating system-specific port driver allocates and initializes with zeros a set of LU extensions of the specified size for the miniport driver to use.

Per-LU storage can be used to store data relevant to a particular peripheral, such as saved data pointers. To access this area, the miniport driver calls **StorPortGetLogicalUnit** when the driver is maintaining information about the state of or current operation for any particular peripheral.

The operating system-specific port driver can consider a logical unit to be nonexistent if there is no active request for that logical unit and the device has never been successfully selected.

> [!NOTE]
>
> When the miniport driver calls **StorPortGetLogicalUnit** at IRQL = DISPATCH_LEVEL, the function acquires the interrupt lock. Calling **StorPortGetLogicalUnit** too often at this IRQL level impacts the performance and scalability of the miniport driver.

## See also

[**HW_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_hw_initialization_data-r1)

[**StorPortInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize)