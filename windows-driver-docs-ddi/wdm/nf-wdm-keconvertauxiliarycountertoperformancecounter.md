# KeConvertAuxiliaryCounterToPerformanceCounter function

## Description

The **KeConvertAuxiliaryCounterToPerformanceCounter** routine converts the specified auxiliary counter value into a performance counter value.

## Parameters

### `AuxiliaryCounterValue` [in]

The auxiliary counter value to convert.

### `PerformanceCounterValue` [out]

A pointer to the variable that contains the converted performance counter value.

### `ConversionError` [out, optional]

A pointer to a variable that contains the estimated conversion error in units of nanosecond.

## Return value

**KeConvertAuxiliaryCounterToPerformanceCounter** can return one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The conversion succeeded. |
| **STATUS_NOT_SUPPORTED** | Auxiliary counter is not supported. |
| **STATUS_INVALID_PARAMETER** | The *AuxiliaryCounterValue* value is not valid. For example, the value is earlier than the last system boot/recovery, or is out of the +/- 10s range compared to the current auxiliary counter value. |
| **STATUS_UNSUCCESSFUL** | The routine cannot convert the specified value with acceptable accuracy. |

## Remarks

Make sure that the specified auxiliary counter value is within +/- 10s compared to the current value.

## See also

[KeConvertPerformanceCounterToAuxiliaryCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keconvertperformancecountertoauxiliarycounter)