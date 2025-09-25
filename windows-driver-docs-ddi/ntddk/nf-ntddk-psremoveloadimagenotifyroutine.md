# PsRemoveLoadImageNotifyRoutine function

## Description

The **PsRemoveLoadImageNotifyRoutine** routine removes a callback routine that was registered by the [PsSetLoadImageNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetloadimagenotifyroutine) routine.

## Parameters

### `NotifyRoutine` [in]

Pointer to the callback routine that the driver has previously registered through [PsSetLoadImageNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetloadimagenotifyroutine).

## Return value

**PsRemoveLoadImageNotifyRoutine** returns STATUS_SUCCESS if it successfully removes the callback routine, or STATUS_PROCEDURE_NOT_FOUND if the value of *NotifyRoutine* does not match any registered callback routine.

## Remarks

If the driver's callback routine is currently running, **PsRemoveLoadImageNotifyRoutine** waits until the callback routine exits before removing it. Therefore, the callback routine itself must not call **PsRemoveLoadImageNotifyRoutine**.

## See also

[PsSetLoadImageNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetloadimagenotifyroutine)