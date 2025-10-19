# WinBioMonitorPresence function

## Description

Turns on the face-recognition or iris-monitoring mechanism for the specified biometric unit. Starting with Windows 10, build 1607, this function is available to use with a mobile image.

## Parameters

### `SessionHandle` [in]

An asynchronous handle for the biometric session that you obtained by calling the [WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession) function with the *PoolType* parameter set to **WINBIO_POOL_SYSTEM**.

### `UnitId` [in]

The identifier of the biometric unit for which you want to turn on the face-recognition or iris-monitoring mechanism.

## Return value

If the function parameters are acceptable, it returns **S_OK**. If the function parameters are not acceptable, it returns an **HRESULT** value that indicates the error.
Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_HANDLE** | The session handle is not valid. |
| **E_INVALIDARG** | The *UnitId* parameter cannot equal zero. |
| **WINBIO_E_INCORRECT_SESSION_TYPE** | The session handle does not correspond to an asynchronous biometric session. |

The actual success or failure of the operation itself is returned to the your notification function in a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure.

## Remarks

A single biometric session can have only one active presence monitor at any point in time.

After you successfully call **WinBioMonitorPresence**, your notification function receives notifications in the form of a [WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result) structure with an **Operation** member equal to **WINBIO_OPERATION_MONITOR_PRESENCE**. You should then examine the **Parameters.MonitorPresence** member of the **WINBIO_ASYNC_RESULT** structure for more information.

To stop receiving notifications, call either [WinBioCancel](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocancel) or [WinBioCloseSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioclosesession) with the original asynchronous handle value.

## See also

[WINBIO_ASYNC_RESULT](https://learn.microsoft.com/windows/desktop/api/winbio/ns-winbio-winbio_async_result)

[WinBioAsyncOpenSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioasyncopensession)

[WinBioCancel](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocancel)

[WinBioCloseSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioclosesession)