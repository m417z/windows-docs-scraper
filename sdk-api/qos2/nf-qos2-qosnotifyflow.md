# QOSNotifyFlow function

## Description

The **QOSNotifyFlow** function registers the calling application to receive a notification about changes in network characteristics, such as congestion. Notifications may also be sent when a desired throughput is able to be achieved.

## Parameters

### `QOSHandle` [in]

Handle to the QOS subsystem returned by [QOSCreateHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qoscreatehandle).

### `FlowId` [in]

Specifies the flow identifier from which the application wishes to receive notifications. A **QOS_FLOWID** is an unsigned 32-bit integer.

### `Operation` [in]

A [QOS_NOTIFY_FLOW](https://learn.microsoft.com/windows/desktop/api/qos2/ne-qos2-qos_notify_flow) value that indicates what the type of notification being requested.

### `Size` [in, out, optional]

Indicates the size of the *Buffer* parameter, in bytes.

On function return, if successful, this parameter will specify the number of bytes copied into *Buffer*.

If this call fails with **ERROR_INSUFFICIENT_BUFFER**, this parameter will indicate the minimum required *Buffer* size in order to successfully complete this operation.

### `Buffer` [in, out]

Pointer to a UINT64 that indicates the bandwidth at which point a notification will be sent. This parameter is only used if the *Operation* parameter is set to **QOSNotifyAvailable**. For the **QOSNotifyCongested** and **QOSNotifyUncongested** options, this parameter must be set to **NULL** on input.

### `Flags`

Reserved for future use. This parameter must be set to 0.

### `Overlapped` [out, optional]

Pointer to an OVERLAPPED structure used for asynchronous output. This must be se to **NULL** if this function is not being called asynchronously.

## Return value

If the function succeeds, a return value of nonzero is sent when the conditions set by the *Operation* parameter are met.

If the function fails, the return value is 0. To get extended error information, call **GetLastError**. Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DISABLED_BY_POLICY** | The QoS subsystem is currently configured by policy to not allow this operation on the network path between this host and the destination host. For example, the default policy prevents qWAVE experiments from running to off-link destinations. |
| **ERROR_IO_PENDING** | Indicates that notification request was successfully received. Results will be returned during overlapped completion. |
| **ERROR_INVALID_HANDLE** | The *QOSHandle* parameter is invalid. |
| **ERROR_INVALID_PARAMETER** | The *FlowId* parameter is invalid. |
| **ERROR_NOT_ENOUGH_MEMORY** | Indicates that a memory allocation failed. |
| **ERROR_NOT_FOUND** | Invalid *FlowId* specified. |
| **ERROR_NOT_SUPPORTED** | The operation being performed requires information that the QoS subsystem does not have. Obtaining this information on this network is currently not supported. For example, bandwidth estimations cannot be obtained on a network path where the destination host is off-link. |
| **ERROR_NO_SYSTEM_RESOURCES** | There are insufficient resources to carry out the operation. |
| **ERROR_IO_DEVICE** | The request could not be performed because of an I/O device error. |
| **ERROR_DEVICE_REINITIALIZATION_NEEDED** | The indicated device requires reinitialization due to hardware errors. The application should clean up and call [QOSCreateHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qoscreatehandle) again. |
| **ERROR_NOT_SUPPORTED** | The QOS subsystem has determined that the operation requested could not be completed on the network path specified. |
| **ERROR_ADAP_HDW_ERR** | A network adapter hardware error occurred. |
| **ERROR_HOST_UNREACHABLE** | The network location cannot be reached. |
| **ERROR_UNEXP_NET_ERR** | The network connection with the remote host failed. |
| **ERROR_ALREADY_EXISTS** | There is already a request for notifications of the same type pending on this flow. |

## Remarks

This function may be called asynchronously.

## See also

[Quality Windows Audio/Video Experience (qWAVE)](https://learn.microsoft.com/previous-versions/windows/desktop/qos/quality-windows-audio-video-experience--qwave-)