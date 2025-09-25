# QOSQueryFlow function

## Description

The **QOSQueryFlow** function requests information about a specific flow added to the QoS subsystem. This function may be called asynchronously.

## Parameters

### `QOSHandle` [in]

Handle to the QOS subsystem returned by [QOSCreateHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qoscreatehandle).

### `FlowId` [in]

Specifies a flow identifier. A **QOS_FLOWID** is an unsigned 32-bit integer.

### `Operation` [in]

Specifies which type of flow information is being queried. This parameter specifies what structure the *Buffer* will contain.

| Value | Meaning |
| --- | --- |
| **QOSQueryFlowFundamentals** | *Buffer* will contain a [QOS_FLOW_FUNDAMENTALS](https://learn.microsoft.com/windows/desktop/api/qos2/ns-qos2-qos_flow_fundamentals) structure. |
| **QOSQueryPacketPriority** | *Buffer* will contain a [QOS_PACKET_PRIORITY](https://learn.microsoft.com/windows/desktop/api/qos2/ns-qos2-qos_packet_priority) structure. |
| **QOSQueryOutgoingRate** | *Buffer* will contain a **UINT64** value that indicates the flow rate specified when requesting the contract, in bits per second. |

### `Size` [in, out]

Indicates the size of the *Buffer* parameter, in bytes.

On function return, if successful, this parameter will specify the number of bytes copied into *Buffer*.

If this call fails with **ERROR_INSUFFICIENT_BUFFER**, this parameter will indicate the minimum required *Buffer* size in order to successfully complete this operation.

### `Buffer` [out]

Pointer to the structure specified by the value of the *Operation* parameter.

### `Flags` [in, optional]

Flags pertaining to the data being returned.

| Value | Meaning |
| --- | --- |
| **QOS_QUERYFLOW_FRESH** | The QOS subsystem will only return fresh, not cached, data. If fresh data is unavailable, it will try to obtain such data, at the expense of possibly taking more time. If this is not possible, the call will fail with the error code **ERROR_RETRY**.<br><br>This flag is only applicable when the *Operation* parameter is set to **QOSQueryFlowFundamentals**. |

### `Overlapped` [out, optional]

Pointer to an OVERLAPPED structure used for asynchronous output. This must be set to **NULL** if this function is not being called asynchronously.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0. To get extended error information, call **GetLastError**. Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DISABLED_BY_POLICY** | The QoS subsystem is currently configured by policy to not allow this operation on the network path between this host and the destination host. For example, the default policy prevents qWAVE experiments from running to off-link destinations. |
| **ERROR_TIMEOUT** | The request to the QOS subsystem timed out before enough useful information could be gathered. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer length as specified by the **Size** parameter is not sufficient for the queried data. The **Size** parameter now contains the minimum required size. |
| **ERROR_INVALID_HANDLE** | The *QOSHandle* parameter is invalid. |
| **ERROR_INVALID_PARAMETER** | The *FlowId* parameter or *Buffer* size is insufficient. |
| **ERROR_NOT_FOUND** | Invalid *FlowId* specified. |
| **ERROR_NOT_ENOUGH_MEMORY** | Indicates that a memory allocation failed. |
| **ERROR_NOT_SUPPORTED** | The operation being performed requires information that the QoS subsystem does not have. Obtaining this information on this network is currently not supported. For example, bandwidth estimations cannot be obtained on a network path where the destination host is off-link. |
| **ERROR_NO_SYSTEM_RESOURCES** | There are insufficient resources to carry out the operation. |
| **ERROR_IO_DEVICE** | The request could not be performed because of an I/O device error. |
| **ERROR_IO_PENDING** | Indicates that the update flow request was successfully initiated. |
| **ERROR_DEVICE_REINITIALIZATION_NEEDED** | The indicated device requires reinitialization due to hardware errors. The application should clean up and call [QOSCreateHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qoscreatehandle) again. |
| **ERROR_ADAP_HDW_ERR** | A network adapter hardware error occurred. |
| **ERROR_HOST_UNREACHABLE** | The network location cannot be reached. |
| **ERROR_NO_DATA** | The is no valid data to be returned. |
| **ERROR_RETRY** | There is currently insufficient data about networking conditions to answer the query. This is typically a transient state where qWAVE has erred on the side of caution as it awaits more data before ascertaining the state of the network. |

## See also

[Quality Windows Audio/Video Experience (qWAVE)](https://learn.microsoft.com/previous-versions/windows/desktop/qos/quality-windows-audio-video-experience--qwave-)