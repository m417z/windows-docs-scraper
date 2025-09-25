## Description

The **RouterCreatePrintAsyncNotificationChannel** function creates an asynchronous notification channel that is associated with a printer or print server.

## Parameters

### `pName` [in]

A pointer to a null-terminated string that specifies the name of the printer or print server.

### `pNotificationType` [in]

A pointer to a GUID that represents the type of notifications sent through this channel.

### `eNotifyFilter`

A filter for the session or user that receives the notifications.

### `eConversationStyle` [in]

The type of communication: unidirectional or bidirectional.

### `pCallback` [in]

A pointer to the callback function that is called to deliver the response notifications, when bidirectional communication is in effect. This parameter is ignored when unidirectional communication is in effect.

### `ppIAsynchNotification`

A pointer to a variable that receives the address of the interface object that represents the notification channel.

## Return value

**RouterCreatePrintAsyncNotificationChannel** returns **S_OK** on success and returns a standard COM error code otherwise.

## Remarks

In some cases, you must release the channel that you created with the **RouterCreatePrintAsyncNotificationChannel** function by calling **Release** on **IPrintAsyncNotifyChannel**.

For information about when to release a channel, see [Notification Channel](https://learn.microsoft.com/windows-hardware/drivers/print/notification-channel).