## Description

The **PsUnregisterAvailableCpusChangeNotification** function unregisters a registration previously performed by [**PsRegisterProcessAvailableCpusChangeNotification**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psregisterprocessavailablecpuschangenotification) or [**PsRegisterSystemAvailableCpusChangeNotification**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psregistersystemavailablecpuschangenotification).

## Parameters

### `RegistrationHandle` [in]

Handle returned by a call to [**PsRegisterProcessAvailableCpusChangeNotification**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psregisterprocessavailablecpuschangenotification) or [**PsRegisterSystemAvailableCpusChangeNotification**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psregistersystemavailablecpuschangenotification).

## Remarks

This routine must be called at PASSIVE_LEVEL.

After this function returns, the callback associated with the registration handle will no longer be invoked for CPU availability changes.

This function can be used to unregister callbacks registered for both process-specific and system-wide CPU availability change notifications.

## See also

[**PsRegisterProcessAvailableCpusChangeNotification**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psregisterprocessavailablecpuschangenotification)

[**PsRegisterSystemAvailableCpusChangeNotification**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-psregistersystemavailablecpuschangenotification)