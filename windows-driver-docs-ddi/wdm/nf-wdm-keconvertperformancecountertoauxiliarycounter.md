# KeConvertPerformanceCounterToAuxiliaryCounter function

## Description

The **KeConvertPerformanceCounterToAuxiliaryCounter** routine converts the specified performance counter value into an auxiliary counter value.

## Parameters

### `PerformanceCounterValue` [in]

The performance counter value to convert.

### `AuxiliaryCounterValue` [out]

A pointer to the variable that contains the converted auxiliary counter value.

### `ConversionError` [out, optional]

A pointer to a variable that contains the estimated conversion error in units of nanosecond.

## Return value

**KeConvertPerformanceCounterToAuxiliaryCounter** can return one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The conversion succeeded. |
| **STATUS_NOT_SUPPORTED** | Auxiliary counter is not supported. |
| **STATUS_INVALID_PARAMETER** | The *PerformanceCounterValue* value is not valid. For example, the value is earlier than the last system boot/recovery, or is out of the +/- 10s range compared to the current performance counter value. |
| **STATUS_UNSUCCESSFUL** | The routine cannot convert the specified value with acceptable accuracy. |

## Remarks

Make sure that the specified performance counter value is:

* Within +/- 10s compared to the current performance counter read value.
* Not earlier than the recorded performance counter value at the last system boot or recovery from S3/S4 state.

The *ConversionError* value is the difference, in nanoseconds, between the expected calculated value and the actual calculated value for the auxiliary counter.
If the *ConversionError* value is greater than the expected value (determined by you), then call the routine again.

## See also

[KeConvertAuxiliaryCounterToPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keconvertauxiliarycountertoperformancecounter)