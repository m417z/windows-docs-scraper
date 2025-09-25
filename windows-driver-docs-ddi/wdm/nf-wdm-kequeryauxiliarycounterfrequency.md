# KeQueryAuxiliaryCounterFrequency function

## Description

The **KeQueryAuxiliaryCounterFrequency** routine returns frequency of the auxiliary counter in units of Hz.

## Parameters

### `AuxiliaryCounterFrequency` [out, optional]

A pointer to a variable to which **KeQueryAuxiliaryCounterFrequency** writes the auxiliary counter frequency, in ticks per second. This parameter can be NULL.

## Return value

**KeQueryAuxiliaryCounterFrequency** can return one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The query succeeded. |
| **STATUS_NOT_SUPPORTED** | Auxiliary counter is not supported. |

## Remarks

Call this routine to programmatically determine whether auxiliary counter is supported. In that call, if you do not need the frequency of the counter, pass NULL. If not supported, the routine returns STATUS_NOT_SUPPORTED.

## See also

[KeConvertAuxiliaryCounterToPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keconvertauxiliarycountertoperformancecounter)

[KeConvertPerformanceCounterToAuxiliaryCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keconvertperformancecountertoauxiliarycounter)