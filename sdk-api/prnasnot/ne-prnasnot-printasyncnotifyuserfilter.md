# PrintAsyncNotifyUserFilter enumeration

## Description

Specifies whether notifications will go only to listening applications that are associated with the same user as the Print Spooler-hosted sender, or go to a broader set of listening applications.

## Constants

### `kPerUser`

When passed to [CreatePrintAsyncNotifyChannel](https://learn.microsoft.com/windows/desktop/api/prnasnot/nf-prnasnot-createprintasyncnotifychannel), kPerUser indicates that notifications will go only to listening applications that are using [Client Impersonation](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-impersonation) to impersonate the same user as the Print Spooler-hosted sender. For example, if the Print Spooler-hosted sender sends a notification that a print job has finished printing, only listening applications impersonating the user that submitted the job will receive notification. When passed to [RegisterForPrintAsyncNotifications](https://learn.microsoft.com/windows/desktop/api/prnasnot/nf-prnasnot-registerforprintasyncnotifications), kPerUser indicates that the listener will receive notifications only from senders that are impersonating the same user as the listener.

### `kAllUsers`

When passed to [CreatePrintAsyncNotifyChannel](https://learn.microsoft.com/windows/desktop/api/prnasnot/nf-prnasnot-createprintasyncnotifychannel), kAllUsers indicates that notifications will go to all listening applications, regardless of the user; as long as the sender has administration privileges on the associated print queue or print server. When passed to [RegisterForPrintAsyncNotifications](https://learn.microsoft.com/windows/desktop/api/prnasnot/nf-prnasnot-registerforprintasyncnotifications), kAllUsers indicates that notifications will go to all listening applications whose associated user has administration privileges on the print queue or print server.

## Remarks

Regardless of which value is passed, listeners will receive only the types of notifications for which they have registered.

A user may be simultaneously logged on to multiple terminal server sessions. All of the user's applications, regardless of which session hosts them, will receive notifications for which they have registered.