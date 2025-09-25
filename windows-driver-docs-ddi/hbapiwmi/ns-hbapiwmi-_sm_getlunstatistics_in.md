# _SM_GetLUNStatistics_IN structure

## Description

The SM_GetLUNStatistics_IN structure is used to provide input parameters to the SM_GetLUNStatistics_IN method.

## Members

### `Lunit`

A structure of type [HBA_ScsiId](https://learn.microsoft.com/previous-versions/ff557191(v=vs.85)) that contains information that is used by the operating system to identify a SCSI logical unit.

## Remarks

When the WMI tool suite compiles the MS_SM_TargetInformationMethods WMI class, it generates a declaration of the SM_GetLUNStatistics_IN structure in *Hbapiwmi.h*.