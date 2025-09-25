# StorPortValidateRange function

## Description

The **StorPortValidateRange** routine determines whether a specified range of I/O addresses is in use by another adapter. This routine is obsolete in Windows NT 4.0 and later operating systems.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [**StorPortInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `BusType` [in]

Contains a value of type [**STORAGE_BUS_TYPE**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff566356(v=vs.85)) that indicates the bus type.

### `SystemIoBusNumber`

Contains an integer identifying a system bus.

### `IoAddress` [in]

Contains the beginning address of the range of addresses to be validated.

### `NumberOfBytes` [in]

Contains the length in bytes of the range of addresses to be validated.

### `InIoSpace` [in]

Indicates, when **TRUE**, that the address range is in I/O space. If **FALSE**, the address is in memory space.

## Return value

**StorPortValidateRange** returns **TRUE** if a specified range of addresses is not claimed by another driver. This routine returns **FALSE** if another driver has claimed the address range.

## Remarks

For compatibility with older versions of Windows, this routine always returns **TRUE**.

Miniport drivers are given valid I/O ranges in the **AccessRanges** member of the [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information) structure when the Storport driver calls the miniport's [**HwStorFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) callback routine.

**StorPortValidateRange** uses **STOR_PHYSICAL_ADDRESS** to represent bus-relative addresses.

```cpp
typedef PHYSICAL_ADDRESS STOR_PHYSICAL_ADDRESS, *PSTOR_PHYSICAL_ADDRESS;
```

The **STOR_PHYSICAL_ADDRESS** type is an operating system-independent data type that Storport miniport drivers use to represent either a physical addresses or a bus-relative address.

## See also

[**ScsiPortValidateRange**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportvalidaterange)