# _SOC_SUBSYSTEM_FAILURE_DETAILS structure

## Description

The **SOC_SUBSYSTEM_FAILURE_DETAILS** structure holds information related to a System on a Chip (SoC) bug code.

These bug codes store information in a
this structure.

* [Bug Check 0x14B SOC_SUBSYSTEM_FAILURE](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-0x14b--soc-subsystem-failure)
* [Bug Check 0x15D SOC_SUBSYSTEM_FAILURE_LIVEDUMP](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-0x15d-soc-subsystem-failure-livedump)

## Members

### `SubsysType`

A value in the [SOC_SUBSYSTEM_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_soc_subsystem_type) enumeration or a vendor-defined subsystem type. Subsystem types in the range 0x10000 through 0x80000000 are reserved for independent hardware vendors.

### `FirmwareVersion`

A vendor-defined SoC firmware version number.

### `HardwareVersion`

A vendor-defined SoC hardware version number.

### `UnifiedFailureRegionSize`

The size, in bytes, of the **UnifiedFailureRegion** string including the **NULL** terminator.

### `UnifiedFailureRegion`

A null-terminated string, defined by the vendor, that contains classification details about the error that occurred.