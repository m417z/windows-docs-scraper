# ExInitializeSetTimerParameters function

## Description

The **ExInitializeSetTimerParameters** routine initializes an [EXT_SET_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ext_set_parameters_v0) structure.

## Parameters

### `Parameters` [out]

A pointer to the **EXT_SET_PARAMETER** structure that is to be initialized.

## Remarks

Your driver must call **ExInitializeSetTimerParameters** to initialize an **EXT_SET_PARAMETERS** structure before the driver passes this structure to the [ExSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsettimer) routine. For more information about the member values that **ExInitializeSetTimerParameters** writes to the members of this structure, see [EXT_SET_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ext_set_parameters_v0).

## See also

[EXT_SET_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ext_set_parameters_v0)

[ExSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsettimer)