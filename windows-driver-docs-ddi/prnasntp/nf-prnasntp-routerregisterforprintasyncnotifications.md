# RouterRegisterForPrintAsyncNotifications function

## Description

The `RouterRegisterForPrintAsyncNotifications` function registers for asynchronous notifications associated with a printer or print server.

## Parameters

### `pName` [in]

A pointer to a null-terminated string that specifies the name of the printer or print server.

### `pNotificationType` [in]

A pointer to the GUID that represents the type of notifications of interest to the caller.

### `eNotifyFilter` [in]

The filter for the session or user of interest to the caller when receiving notifications.

### `eConversationStyle` [in]

The type of communication: unidirectional or bidirectional.

### `pCallback` [in]

A pointer to the callback that is used deliver the notifications.

### `phNotify` [out]

A pointer to an opaque handle. The caller can use this handle to discontinue receiving notifications.

## Return value

This function returns S_OK on success, and a standard COM error code otherwise.

## See also

[RouterUnregisterForPrintAsyncNotifications](https://learn.microsoft.com/windows-hardware/drivers/ddi/prnasntp/nf-prnasntp-routerunregisterforprintasyncnotifications)