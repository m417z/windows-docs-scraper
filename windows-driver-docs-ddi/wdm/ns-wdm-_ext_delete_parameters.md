# _EXT_DELETE_PARAMETERS structure

## Description

The **EXT_DELETE_PARAMETERS** structure contains an extended set of parameters for the [ExDeleteTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exdeletetimer) routine.

## Members

### `Version`

The version number of this **EXT_DELETE_PARAMETERS** structure. The [ExInitializeDeleteTimerParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializedeletetimerparameters) routine sets this member to the correct version number.

### `Reserved`

Set to zero. The **ExInitializeDeleteTimerParameters** routine sets this member to zero.

### `DeleteCallback`

A pointer to a driver-implemented [ExTimerDeleteCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ext_delete_callback) callback routine. The operating system calls this routine when the timer is deleted. This parameter is optional and can be **NULL** if no timer-deletion callback routine is needed.

The **ExInitializeDeleteTimerParameters** routine sets this member to **NULL**. For more information, see Remarks.

### `DeleteContext`

A context value for the timer-deletion callback routine. The operating system passes this value as a parameter to the timer-deletion callback routine, if one is specified. This parameter is typically a pointer to a caller-defined structure that contains context information used by the callback routine. This parameter is optional and can be set to **NULL** if no context information is needed.

The **ExInitializeDeleteTimerParameters** routine sets this member to **NULL**.

## Remarks

The *Parameters* parameter of the [ExDeleteTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exdeletetimer) routine is a pointer to an **EXT_DELETE_PARAMETERS** structure. Before passing an **EXT_DELETE_PARAMETERS** structure to this routine, call the [ExInitializeDeleteTimerParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializedeletetimerparameters) routine to initialize the structure.

Your driver can use an [ExTimerDeleteCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ext_delete_callback) callback routine to free any storage or other system resources that the driver might have previously allocated to use with the timer object that is being deleted. For example, the driver's context value might point to a caller-allocated structure that needs to be freed if the timer object is to be deleted. The operating system calls the *ExTimerDeleteCallback* routine only after the timer object has been disabled to prevent further timer operations and any pending timer operation on the timer object is canceled or completed.

## See also

[ExDeleteTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exdeletetimer)

[ExInitializeDeleteTimerParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializedeletetimerparameters)

[ExTimerDeleteCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ext_delete_callback)