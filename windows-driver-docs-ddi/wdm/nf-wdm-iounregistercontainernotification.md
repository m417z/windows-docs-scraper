# IoUnregisterContainerNotification function

## Description

The **IoUnregisterContainerNotification** routine cancels a container notification registration that was previously created by the [IoRegisterContainerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregistercontainernotification) routine.

## Parameters

### `CallbackRegistration` [in]

A pointer to a callback registration object that was created by a previous call to **IoRegisterContainerNotification**.

## Remarks

After this routine returns, the *CallbackRegistration* pointer value is no longer valid.

## See also

[IoRegisterContainerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregistercontainernotification)