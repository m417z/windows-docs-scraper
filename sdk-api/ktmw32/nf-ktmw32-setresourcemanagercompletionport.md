# SetResourceManagerCompletionPort function

## Description

Associates the specified I/O completion port with the specified resource manager (RM). This port receives all notifications for the RM.

## Parameters

### `ResourceManagerHandle` [in]

A handle to the resource manager.

### `IoCompletionPortHandle` [in]

A handle to the I/O completion port.

### `CompletionKey` [in]

The user-defined identifier. Typically, it is used to associate the receive notification with a specific resource manager.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0 (zero). To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

The following list identifies the possible error codes:

## Remarks

This function must be used in conjunction with the [GetNotificationResourceManagerAsync](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-getnotificationresourcemanagerasync) function, which provides the buffers that KTM uses to deliver notifications asynchronously. These functions provide a different way to receive notifications from KTM. You can use these two functions instead of the [GetNotificationResourceManager](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-getnotificationresourcemanager) function.

This function must be called before calling [GetNotificationResourceManagerAsync](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-getnotificationresourcemanagerasync).

## See also

[GetNotificationResourceManager](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-getnotificationresourcemanager)

[GetNotificationResourceManagerAsync](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-getnotificationresourcemanagerasync)

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)