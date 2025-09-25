# _PEP_QUERY_SOC_SUBSYSTEM_METADATA structure (pepfx.h)

## Description

The **PEP_QUERY_SOC_SUBSYSTEM_METADATA** structure is used with the **PEP_DPM_QUERY_SOC_SUBSYSTEM_METADATA** notification to collect optional metadata about the system on a chip (SoC) subsystem whose blocking time has just been queried.

## Members

### `PlatformIdleStateIndex` [in]

The platform idle state index for the SoC subsystem that the OS is querying.

### `SubsystemHandle` [in]

A context pointer that the PEP previously provided on subsystem initialization. The context pointer is optional, so if none was provided then the value will be zero. The PEP is free to ignore this field.

### `SubsystemName` [in]

The name of the subsystem whose metadata is being queried.

### `Flags`

This member is reserved and should be set to zero.

### `MetadataCount` [in]

The number of entries in the **Metadata** array. The PEP previously provided this value as **PEP_QUERY_SOC_SUBSYSTEM.MetadataCount**.

### `Metadata` [in/out]

An array of pointers to [PEP_SOC_SUBSYSTEM_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_soc_subsystem_metadata) structures. Each entry holds one key/value metadata string-pair.

## See also

**PEP_DPM_QUERY_SOC_SUBSYSTEM_METADATA**

[PEP_SOC_SUBSYSTEM_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_soc_subsystem_metadata)