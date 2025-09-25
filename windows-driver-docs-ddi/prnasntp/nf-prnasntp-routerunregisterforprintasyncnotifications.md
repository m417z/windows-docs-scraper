# RouterUnregisterForPrintAsyncNotifications function

## Description

The `RouterUnregisterForPrintAsyncNotifications` function unregisters for receiving asynchronous notifications associated with a printer or print server.

## Parameters

### `hNotify` [in]

The registration handle returned by the [RouterRegisterForPrintAsyncNotifications](https://learn.microsoft.com/windows-hardware/drivers/ddi/prnasntp/nf-prnasntp-routerregisterforprintasyncnotifications) function.

## Return value

This function returns S_OK on success, and a standard COM error code otherwise.

## See also

[RouterRegisterForPrintAsyncNotifications](https://learn.microsoft.com/windows-hardware/drivers/ddi/prnasntp/nf-prnasntp-routerregisterforprintasyncnotifications)