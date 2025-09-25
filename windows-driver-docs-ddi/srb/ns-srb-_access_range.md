# _ACCESS_RANGE structure (srb.h)

## Description

An ACCESS_RANGE describes a memory or I/O port range used by an HBA.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `RangeStart`

Contains an address of type [SCSI_PHYSICAL_ADDRESS](https://learn.microsoft.com/previous-versions/ff565350(v=vs.85)) that specifies the bus-relative base address of the range. This is an address that can be passed into [ScsiPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetdevicebase).

### `RangeLength`

Specifies the size, in bytes, or number of ports in the range. A miniport driver must ensure that this value matches the range actually decoded by the adapter. For example, if the HBA uses seven registers but responds to eight, this member should be set to 8.

### `RangeInMemory`

Indicates the range is in memory when **TRUE**, rather than in I/O space. When **FALSE**, the range is in I/O space.

## Remarks

Each ACCESS_RANGE is an **AccessRanges** array element within the PORT_CONFIGURATION_INFORMATION structure that is passed to a miniport driver's HwScsiFindAdapter routine.

If possible, the OS-specific port driver sets up each access range element with a bus-relative HBA range for the miniport driver before calling the miniport driver's HwScsiFindAdapter routine. Otherwise, the port driver zeros range elements for which it cannot supply configuration information.

If the port driver does supply a range, the miniport driver's HwScsiFindAdapter routine should use only the supplied addresses and should *never* attempt to find other HBAs on the same bus using addresses of its own devising. Attempting to access other bus-relative port or memory ranges when the port driver has supplied range information, particularly in x86-only systems in which some devices are initialized in x86 real mode, can cause other devices on the bus to fail initialization or even cause the system to fail the boot process.

Each miniport driver should have a set of bus-relative default ranges to try if the OS-specific port driver cannot supply the information. A miniport driver must call **ScsiPortValidateRange** to check the safety of any miniport driver-supplied access range *before* it attempts to map such a range with **ScsiPortGetDeviceBase** and use the returned logical addresses to access an adapter, particularly if one of its HBAs has a BIOS.

Any access range that a miniport driver fills in for the OS-specific port driver in the PORT_CONFIGURATION_INFORMATION must have the **RangeStart** member set to a bus-relative address, such as a value returned by **ScsiPortGetBusData**.

The corresponding base logical address returned by **ScsiPortGetDeviceBase** should be stored, usually in the miniport driver's device extension, as the **RangeStart** address for a mapped range of I/O ports or memory addresses used to call the **ScsiPortRead***Xxx* and **ScsiPortWrite***Xxx* routines.

## See also

[HwScsiFindAdapter](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85))

[PORT_CONFIGURATION_INFORMATION (SCSI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_port_configuration_information)

[ScsiPortConvertUlongToPhysicalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportconvertulongtophysicaladdress)

[ScsiPortGetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetbusdata)

[ScsiPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetdevicebase)

[ScsiPortValidateRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportvalidaterange)