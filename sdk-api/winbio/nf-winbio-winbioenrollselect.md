# WinBioEnrollSelect function

## Description

Specifies the individual that you want to enroll when data that represents multiple individuals is present in the sample buffer. Starting with Windows 10, build 1607, this function is available to use with a mobile image.

## Parameters

### `SessionHandle` [in]

A **WINBIO_SESSION_HANDLE** value that identifies an open biometric session. Open a synchronous session handle by calling [WinBioOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioopensession). Open an asynchronous session handle by calling [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession).

For enrollment in facial recognition, use [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession) with the *PoolType* parameter set to **WINBIO_POOL_SYSTEM** to get the handle.

### `SelectorValue` [in]

A value that identifies that individual that you want to select for enrollment.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_HANDLE** | The session handle is not valid. |
| **E_INVALIDARG** | The *SelectorValue* parameter cannot equal zero. |
| **WINBIO_E_INCORRECT_SESSION_TYPE** | The session handle does not correspond to a biometric session. |

## Remarks

For enrollment in facial recognition, you can find the correct selector value in either of two ways:

* The value of the **Id** member of one of the [WINBIO_PRESENCE](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-presence) structures previously sent.
* The data produced by the NUI face-tracking APIs.

Call **WinBioEnrollSelect** to set the selector value after you call [WinBioEnrollBegin](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollbegin) to start an enrollment sequence. The selector value applies to all subsequent [WinBioEnrollCapture](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollcapture) calls. The selection setting is temporary and is automatically cleared when you finish the enrollment sequence by calling [WinBioEnrollCommit](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollcommit) or [WinBioEnrollDiscard](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrolldiscard).

If you call **WinBioEnrollSelect** for biometric factors that do not require disambiguation, such as fingerprints, the return value for the function indicates success, but function ignores the selector value.

If you do not call **WinBioEnrollSelect** for a biometric factor that requires you to call the function, subsequent calls to [WinBioEnrollCapture](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollcapture) fail with the **WINBIO_E_SELECTION_REQUIRED** error.

 For Windows 10, the factors that require you to call **WinBioEnrollSelect** are facial features and iris.

You can call **WinBioEnrollSelect** by using either a synchronous or asynchronous session handle. As with other calls to Windows Biometric Framework API functions, when you call **WinBioEnrollSelect** with an asynchronous session handle, the return value indicates only that the function parameters were acceptable. The actual success or failure of the operation itself will be returned to your notification routine in a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure.

## See also

[WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result)

[WINBIO_PRESENCE](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-presence)

[WinBioEnrollBegin](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollbegin)

[WinBioEnrollCapture](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollcapture)

[WinBioEnrollCommit](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrollcommit)

[WinBioEnrollDiscard](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenrolldiscard)