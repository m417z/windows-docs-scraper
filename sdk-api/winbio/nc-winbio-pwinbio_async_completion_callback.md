# PWINBIO_ASYNC_COMPLETION_CALLBACK callback function

## Description

Called by the Windows Biometric Framework to notify the client application that an asynchronous operation has completed. The callback is defined by the client application and called by the Windows Biometric Framework.

## Parameters

### `AsyncResult` [in]

Pointer to a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure that contains information about the completed operation. The structure is created by the Windows Biometric Framework. You must call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release the structure.

## Remarks

You must create this callback if you open a biometric session by using the [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession) function or the [WinBioAsyncOpenFramework](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopenframework) function and you set **WINBIO_ASYNC_NOTIFY_CALLBACK** in the *NotificationMethod* parameter of either function.

**Important** The [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure is allocated internally by the Windows Biometric Framework. Therefore, when you are through using it, call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release the allocated memory and avoid leaks. Because this also releases all nested data structures, you should not keep a copy of any pointers returned in the **WINBIO_ASYNC_RESULT** structure. If you want to save any data returned in a nested structure, make a private copy of that data before calling **WinBioFree**.

## See also

[WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession)

[WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession)