## Description

**STOR_SYSTEM_POWER_HINTS** is the structure pointed to by the **Parameters** parameter when a miniport's [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) routine is called with a **ControlType** of **ScsiAdapterSystemPowerHints**.

## Members

### `Version`

Version number of this structure. Currently set to STOR_SYSTEM_POWER_HINTS_V1.

### `Size`

Size of this structure, in bytes. Set to ```sizeof(STOR_SYSTEM_POWER_HINTS)```.

### `SystemPower`

A [**RAID_SYSTEM_POWER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-raid_system_power) enum value that indicates the system's current power usage.

### `ResumeLatencyMSec`

The maximum resume latency tolerated for the given system power hint, in milliseconds.

## See also

[**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control)

[**RAID_SYSTEM_POWER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-raid_system_power)