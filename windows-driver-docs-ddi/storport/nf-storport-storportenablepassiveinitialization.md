# StorPortEnablePassiveInitialization function

## Description

The **StorPortEnablePassiveInitialization** routine enables the miniport's [HwStorPassiveInitializeRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_passive_initialize_routine) callback routine to execute at PASSIVE_LEVEL during miniport initialization.

## Parameters

### `DeviceExtension` [in]

Pointer to the per-adapter device extension.

### `HwPassiveInitializeRoutine` [in]

Pointer to a callback routine that the port driver calls at PASSIVE_LEVEL to initialize the DPCs that the miniport driver will use. For a description of this callback routine, see [HwStorPassiveInitializeRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_passive_initialize_routine).

## Return value

The **StorPortEnablePassiveInitialization** routine returns **TRUE** if the operating system supports DPCs, and **FALSE** if not.

## Remarks

A miniport must call the **StorPortEnablePassiveInitialization** routine only from within [HwStorInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_initialize). Otherwise, **StorPortEnablePassiveInitialization** will return **FALSE** and the [HwStorPassiveInitializeRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_passive_initialize_routine) routine will not execute.

This routine is implemented using inline function definitions, so that miniport drivers that use this routine will not have to link to libraries that are dependent on the version of the operating system. Miniport drivers can use this routine without sacrificing backward compatibility with versions of the operating system that do not support DPCs in storage miniport drivers.

## See also

[HwStorPassiveInitializeRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_passive_initialize_routine)