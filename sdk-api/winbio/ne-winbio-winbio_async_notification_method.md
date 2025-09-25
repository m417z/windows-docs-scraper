# WINBIO_ASYNC_NOTIFICATION_METHOD enumeration

## Description

Defines constants that specify how completion notifications for asynchronous operations are to be delivered to the client application. This enumeration is used by the [WinBioAsyncOpenFramework](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopenframework) and [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession) functions.

## Constants

### `WINBIO_ASYNC_NOTIFY_NONE:0`

The operation is synchronous.

### `WINBIO_ASYNC_NOTIFY_CALLBACK`

The client-implemented [PWINBIO_ASYNC_COMPLETION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winbio/nc-winbio-pwinbio_async_completion_callback) function is called by the framework.

### `WINBIO_ASYNC_NOTIFY_MESSAGE`

The framework sends completion notices to the client application window message queue.

### `WINBIO_ASYNC_NOTIFY_MAXIMUM_VALUE`

The maximum enumeration value. This constant is not directly used by the [WinBioAsyncOpenFramework](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopenframework) and [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession).

## Remarks

This enumeration was introduced in Windows 8.

## See also

[Client Application Enumerations](https://learn.microsoft.com/windows/desktop/SecBioMet/client-application-enumerations)

[WinBioAsyncOpenFramework](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopenframework)

[WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession)