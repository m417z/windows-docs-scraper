# QOSCancel function

## Description

The **QOSCancel** function cancels a pending overlapped operation, like [QOSSetFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qossetflow).

## Parameters

### `QOSHandle` [in]

Handle to the QOS subsystem returned by [QOSCreateHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qoscreatehandle).

### `Overlapped` [in]

Pointer to the OVERLAPPED structure used in the operation to be canceled.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0. To get extended error information, call **GetLastError**. Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The *QOSHandle* parameter is invalid. |
| **ERROR_INVALID_PARAMETER** | The *Overlapped* parameter is invalid. |
| **ERROR_NOT_ENOUGH_MEMORY** | A memory allocation failed. |
| **ERROR_NO_SYSTEM_RESOURCES** | There are insufficient resources to carry out the operation. |
| **ERROR_IO_DEVICE** | The request could not be performed because of an I/O device error. |
| **ERROR_DEVICE_REINITIALIZATION_NEEDED** | The indicated device requires reinitialization due to hardware errors. The application should clean up and call [QOSCreateHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qoscreatehandle) again. |
| **ERROR_ADAP_HDW_ERR** | A network adapter hardware error occurred. |

## Remarks

This function would never be called with a **NULL***Overlapped* parameter.

Successfully canceled operations complete normal completion mechanisms and return **ERROR_OPERATION_ABORTED** as their completion return code.

Closing a handle with the [QOSCloseHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosclosehandle) will automatically abort all pending operations issued with that handle. If the handle is closed while a **QOSCancel** is still in progress, the call will complete with **ERROR_OPERATION_ABORTED** as the return code.

## See also

[Quality Windows Audio/Video Experience (qWAVE)](https://learn.microsoft.com/previous-versions/windows/desktop/qos/quality-windows-audio-video-experience--qwave-)