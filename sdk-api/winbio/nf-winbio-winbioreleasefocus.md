# WinBioReleaseFocus function

## Description

Releases window focus.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The calling process must be running under the Local System account. |

## Remarks

The Windows Biometric Framework uses window focus to arbitrate among multiple sessions connected to the system pool.

The manner in which you acquire focus depends on the type of application you are writing. For example, if you are creating a GUI application you can implement a message handler that captures a [WM_ACTIVATE](https://learn.microsoft.com/windows/desktop/inputdev/wm-activate), [WM_SETFOCUS](https://learn.microsoft.com/windows/desktop/inputdev/wm-setfocus), or other appropriate message. If you are writing a CUI application, call **GetConsoleWindow** to retrieve a handle to the console window and pass that handle to the **SetForegroundWindow** function to force the console window into the foreground and assign it focus. If your application is running in a detached process or is a Windows service and has no window, use [WinBioAcquireFocus](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioacquirefocus) and **WinBioReleaseFocus** to manually control focus.

The following list summarizes the major points to consider before calling [WinBioAcquireFocus](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioacquirefocus) and **WinBioReleaseFocus**.

* The calling process must be running under the Local System account.
* A process that directly displays a user interface should not call [WinBioAcquireFocus](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioacquirefocus). See the preceding discussion to determine how to acquire focus for GUI and CUI applications.
* Only a service or a detached process that does not directly display a user interface during biometric API calls should call this function.

If you do not acquire focus when calling the following functions, they will behave in unexpected ways:

* [WinBioEnrollBegin](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollbegin)
* [WinBioEnrollCapture](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollcapture)
* [WinBioEnrollCaptureWithCallback](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollcapturewithcallback)

## See also

[Client Application Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/client-application-functions)

[WinBioEnrollBegin](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollbegin)