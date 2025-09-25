# _PEP_RESET_SOC_SUBSYSTEM_ACCOUNTING structure (pep_x.h)

## Description

The **PEP_RESET_SOC_SUBSYSTEM_ACCOUNTING** structure is provided to the platform extension plug-in (PEP) as part of a [PEP_DPM_RESET_SOC_SUBSYSTEM_ACCOUNTING notification](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

## Members

### `PlatformIdleStateIndex` [in]

The platform idle state index for the subsystem accounting to be reset.

### `Flags`

This member is reserved and should be set to zero.

## See also

[PEP_DPM_RESET_SOC_SUBSYSTEM_ACCOUNTING notification](https://learn.microsoft.com/windows-hardware/drivers/ddi/)