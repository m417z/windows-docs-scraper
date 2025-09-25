# DetermineProximateHandwritingTarget function

## Description

Determines whether an edit control exists (or might exist in a dynamic user experience) proximate to the the pointer input.

## Parameters

### `determineProximateHandwritingTargetArgs` [in]

[ITfDetermineProximateHandwritingTargetArgs interface](https://learn.microsoft.com/windows/win32/api/shellhandwriting/nn-shellhandwriting-itfdetermineproximatehandwritingtargetargs)

## Return value

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

This method is called when the system has detected pen input indicating a handwriting experience might be appropriate.

Secondary clients (frameworks) are called only if a primary client (application) does not provide a response to the callback.

Secondary clients are called in reverse order of registration until either S_OK or TF_S_ASYNC response is received from the callback. An example of a secondary client could be a control that provides custom handwriting logic regardless of the application instantiating the control. Secondary clients can register by obtaining an [ITfSource](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfsource) interface from an [ITfThreadMgr](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfthreadmgr) instance and then calling [AdviseSink](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfsource-advisesink) with an [ITfHandwritingSink interface](https://learn.microsoft.com/windows/win32/api/shellhandwriting/nn-shellhandwriting-itfhandwritingsink) object.

If neither primary or secondary clients allow the system to continue with the next client (or fall back to User Interface Automation (UIA)), they should return E_INVALIDARG.

If a client responds with TF_USE_SYSTEM_DEFAULT, and returns S_OK, subsequent clients will be skipped and the system will use its default UIA-based determination logic.

## See also