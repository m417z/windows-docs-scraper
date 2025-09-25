# _PEP_QUERY_SOC_SUBSYSTEM_COUNT structure (pepfx.h)

## Description

The **PEP_QUERY_SOC_SUBSYSTEM_COUNT** structure is used to tell the OS whether the PEP supports system on a chip (SoC) subsystem accounting for a given platform idle state.

## Members

### `PlatformIdleStateIndex` [in]

The platform idle state index for which the kernel is querying about.

### `SubsystemCount` [out]

The number of SoC subsystems tallied by the PEP for the specified platform idle state. The PEP cannot return 0 in this parameter; instead the PEP should return **FALSE** to the [PEP_DPM_QUERY_SOC_SUBSYSTEM_COUNT notification](https://learn.microsoft.com/windows-hardware/drivers/ddi/) that provided this structure.

### `Flags`

This member is reserved and should be set to zero.

## See also

[PEP_DPM_QUERY_SOC_SUBSYSTEM_COUNT notification](https://learn.microsoft.com/windows-hardware/drivers/ddi/)