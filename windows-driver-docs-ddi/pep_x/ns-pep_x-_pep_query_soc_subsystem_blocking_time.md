# _PEP_QUERY_SOC_SUBSYSTEM_BLOCKING_TIME structure (pep_x.h)

## Description

The **PEP_QUERY_SOC_SUBSYSTEM_BLOCKING_TIME** structure is used by the [PEP_DPM_QUERY_SOC_SUBSYSTEM_BLOCKING_TIME notification](https://learn.microsoft.com/windows-hardware/drivers/ddi/) to collect details about the blocking duration for a particular system on a chip (SoC) subsystem.

## Members

### `PlatformIdleStateIndex` [in]

The platform idle state index for the SoC subsystem that the OS is querying.

### `SubsystemHandle` [in]

A context pointer that the PEP previously provided on subsystem initialization. The context pointer is optional, so if none was provided then the value will be zero. The PEP is free to ignore this field.

### `SubsystemName` [in]

The name of the subsystem whose blocking time is being queried. This name was provided by the PEP on subsystem initialization.

### `BlockingTime` [out]

The blocking time tallied for this subsystem in 100 nanosecond units since the previous [PEP_DPM_RESET_SOC_SUBSYSTEM_ACCOUNTING notification](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

### `Flags`

This member is reserved and should be set to zero.

## See also

[PEP_DPM_QUERY_SOC_SUBSYSTEM_BLOCKING_TIME notification](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[PEP_DPM_RESET_SOC_SUBSYSTEM_ACCOUNTING notification](https://learn.microsoft.com/windows-hardware/drivers/ddi/)