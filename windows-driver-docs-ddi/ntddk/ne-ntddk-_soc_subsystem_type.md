# _SOC_SUBSYSTEM_TYPE enumeration

## Description

The **SOC_SYBSYSTEM_TYPE** enumeration defines different types of System on a Chip (SoC) subsystems.

The **SybsysType** member of the [SOC_SUBSYSTEM_FAILURE_DETAILS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_soc_subsystem_failure_details) structure is a value from this enumeration. The **SOC_SUBSYSTEM_FAILURE_DETAILS** structure is used by these bug codes:

* [Bug Check 0x14B SOC_SUBSYSTEM_FAILURE](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-0x14b--soc-subsystem-failure)
* [Bug Check 0x15D SOC_SUBSYSTEM_FAILURE_LIVEDUMP](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-0x15d-soc-subsystem-failure-livedump)

## Constants

### `SOC_SUBSYS_WIRELESS_MODEM`

Wireless modem.

### `SOC_SUBSYS_AUDIO_DSP`

Audio digital signal processor (DSP).

### `SOC_SUBSYS_WIRELSS_CONNECTIVITY`

Wireless connectivity.

### `SOC_SUBSYS_SENSORS`

Sensors.

### `SOC_SUBSYS_COMPUTE_DSP` :

Compute digital signal processor (DSP).

### `SOC_SUBSYS_VENDOR_DEFINED`

Subsystem types in the range 0x10000 through 0x80000000 are reserved for independent hardware vendors.

### `SOC_SUBSYS_SECURE_PROC`