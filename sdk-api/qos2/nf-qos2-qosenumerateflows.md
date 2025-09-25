# QOSEnumerateFlows function

## Description

The **QOSEnumerateFlows** function enumerates all existing flows.

## Parameters

### `QOSHandle` [in]

Handle to the QOS subsystem returned by [QOSCreateHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qoscreatehandle).

### `Size` [in, out]

Indicates the size of the *Buffer* parameter, in bytes.

On function return, if successful, this parameter will specify the number of bytes copied into *Buffer*.

If this call fails with **ERROR_INSUFFICIENT_BUFFER**, this parameter will indicate the minimum required *Buffer* size in order to successfully complete this operation.

### `Buffer` [out]

Pointer to an array of **QOS_FlowId** flow identifiers. A **QOS_FlowId** is an unsigned 32-bit integer.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0. To get extended error information, call **GetLastError**. Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The *QOSHandle* parameter is invalid. |
| **ERROR_INSUFFICIENT_BUFFER** | Buffer is too small. On output, *Size* will contain the minimum required buffer size. This function should then be called again with a buffer of the indicated size. |
| **ERROR_INVALID_PARAMETER** | The *DestAddr* parameter is invalid. |
| **ERROR_NOT_ENOUGH_MEMORY** | Indicates that a memory allocation failed. |
| **ERROR_NO_SYSTEM_RESOURCES** | There are insufficient resources to carry out the operation. |
| **ERROR_IO_DEVICE** | The request could not be performed because of an I/O device error. |
| **ERROR_DEVICE_REINITIALIZATION_NEEDED** | The indicated device requires reinitialization due to hardware errors. The application should clean up and call [QOSCreateHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qoscreatehandle) again. |

## Remarks

Successfully calling this function requires administrative privileges

Calling the **QOSEnumerateFlows** function retrieves a list of **QOS_FlowId**s currently active on the QOS subsystem. These **QOS_FlowId**s could then be used to call the [QOSQueryFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosqueryflow) function in order to gain more information on individual flows.

This function has call-twice semantics. First call to get the *Buffer* size, then call again (with an appropriately sized *Buffer* if the first call failed with **ERROR_INSUFFICIENT_BUFFER**) to retrieve the list of flows. The second call may fail again with **ERROR_INSUFFICIENT_BUFFER** if new flows ere added since the first call.

Flows from another process cannot be modified.

## See also

[Quality Windows Audio/Video Experience (qWAVE)](https://learn.microsoft.com/previous-versions/windows/desktop/qos/quality-windows-audio-video-experience--qwave-)