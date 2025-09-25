# ExInitializeDeleteTimerParameters function

## Description

The **ExInitializeDeleteTimerParameters** routine initializes an [EXT_DELETE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ext_delete_parameters) structure.

## Parameters

### `Parameters`

A pointer to the **EXT_DELETE_PARAMETERS** structure that is to be initialized.

## Remarks

Your driver must call **ExInitializeDeleteTimerParameters** to initialize an **EXT_DELETE_PARAMETERS** structure before the driver passes this structure to the [ExDeleteTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exdeletetimer) routine. For more information about the member values that **ExInitializeDeleteTimerParameters** writes to the members of this structure, see [EXT_DELETE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ext_delete_parameters).

## See also

[EXT_DELETE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ext_delete_parameters)

[ExDeleteTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exdeletetimer)