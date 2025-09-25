# PsRemoveCreateThreadNotifyRoutine function

## Description

The **PsRemoveCreateThreadNotifyRoutine** routine removes a callback routine that was registered by the [PsSetCreateThreadNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreatethreadnotifyroutine) routine.

## Parameters

### `NotifyRoutine` [in]

Pointer to the callback routine that the driver has previously registered through [PsSetCreateThreadNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreatethreadnotifyroutine).

## Return value

**PsRemoveCreateThreadNotifyRoutine** returns STATUS_SUCCESS if it successfully removes the callback routine, or STATUS_PROCEDURE_NOT_FOUND if the value of *NotifyRoutine* does not match any registered callback routine.

## Remarks

If the driver's callback routine is currently running, **PsRemoveCreateThreadNotifyRoutine** waits until the callback routine exits before removing it. Therefore, the callback routine itself must not call **PsRemoveCreateThreadNotifyRoutine**.

## See also

[PsSetCreateThreadNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreatethreadnotifyroutine)