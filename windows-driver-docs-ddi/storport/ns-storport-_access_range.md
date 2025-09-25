# _ACCESS_RANGE structure (storport.h)

## Description

An ACCESS_RANGE describes a memory or I/O port range used by an HBA.

## Members

### `RangeStart`

Contains a physical address that specifies the bus-relative base address of a range used by the HBA. The value of this member can be obtained from one of the **AccessRanges** elements in the [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information) structure. This is an address that can be passed into [**StorPortGetDeviceBase**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetdevicebase).

### `RangeLength`

Specifies the size, in bytes, or number of ports in the range. A miniport driver must ensure that this value matches the range actually decoded by the adapter. For example, if the HBA uses seven registers but responds to eight, this member should be set to 8.

### `RangeInMemory`

Indicates the range is in memory when **TRUE**, rather than in I/O space. When **FALSE**, the range is in I/O space.

## Remarks

Each ACCESS_RANGE is an **AccessRanges** array element within the [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information) structure that is passed to a miniport driver's [**HwStorFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) routine.

Storport allocates memory for the access ranges and initializes the **AccessRanges** member. The miniport driver's **HwStorFindAdapter** routine should use only the supplied addresses and should *never* attempt to find other HBAs on the same bus using addresses of its own devising. Attempting to access other bus-relative port or memory ranges when the port driver has supplied range information, particularly in x86-only systems in which some devices are initialized in x86 real mode, can cause other devices on the bus to fail initialization or even cause the system to fail the boot process.

## See also

[**HwStorFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter)

[**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information)

[**StorPortGetDeviceBase**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetdevicebase)