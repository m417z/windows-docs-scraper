# QOSAddSocketToFlow function

## Description

The **QOSAddSocketToFlow** function adds a new flow for traffic.

## Parameters

### `QOSHandle` [in]

Handle to the QOS subsystem returned by [QOSCreateHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qoscreatehandle).

### `Socket` [in]

 Identifies the socket that the application will use to flow traffic.

### `DestAddr` [in, optional]

Pointer to a [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure that contains the destination IP address to which the application will send traffic. The sockaddr structure must specify a destination port.

**Note** *DestAddr* is optional if the socket is already connected. If this parameter is specified, the remote IP address and port must match those used in the socket's connect call.

If the socket is not connected, this parameter must be specified. If the socket is already connected, this parameter does not need to be specified. In this case, if the parameter is still specified, the destination host and port must match what was specified during the socket connect call.

Since, under TCP, the socket connect call can be delayed, **QOSAddSocketToFlow** can be called before a connection is established, passing in the remote system's IP address and port number in the *DestAddr* parameter.

### `TrafficType` [in]

A [QOS_TRAFFIC_TYPE](https://learn.microsoft.com/windows/desktop/api/qos2/ne-qos2-qos_traffic_type) constant that specifies the type of traffic for which this flow will be used.

### `Flags` [in, optional]

Optional flag values.

| Value | Meaning |
| --- | --- |
| **QOS_NON_ADAPTIVE_FLOW** | If specified, the QoS subsystem will not gather data about the network path for this flow. As a result, functions which rely on bandwidth estimation techniques will not be available. For example, this would block [QOSQueryFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosqueryflow) with an *Operation* value of **QOSQueryFlowFundamentals** and [QOSNotifyFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosnotifyflow) with an *Operation* value of **QOSNotifyCongested**, **QOSNotifyUncongested**, and **QOSNotifyAvailable**. |

### `FlowId` [in, out]

Pointer to a buffer that receives a flow identifier. On input, this value must be 0. On output, the buffer contains a flow identifier if the call succeeds.

If a socket is being added to an existing flow, this parameter will be the identifier of that flow.

An application can make use of this parameter if multiple sockets used can share the same QoS flow properties. The QoS subsystem, then does not have to incur the overhead of provisioning new flows for subsequent sockets with the same properties. Note that only non-adaptive flows can have multiple sockets attached to an existing flow.

A **QOS_FLOWID** is an unsigned 32-bit integer.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0. To get extended error information, call **GetLastError**. Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **ERROR_CONNECTION_REFUSED** | The remote system refused the network connection. |
| **ERROR_INVALID_HANDLE** | The *QOSHandle* parameter is invalid. |
| **ERROR_INVALID_PARAMETER** | The *FlowId* parameter is invalid.<br><br>**Note** This value is also returned if a IPv4/v6 mixed address was supplied through the *DestAddr* parameter. |
| **ERROR_NOT_ENOUGH_MEMORY** | A memory allocation failed. |
| **ERROR_NO_SYSTEM_RESOURCES** | There are insufficient resources to carry out the operation. |
| **ERROR_IO_DEVICE** | The request could not be performed because of an I/O device error. |
| **ERROR_DEVICE_REINITIALIZATION_NEEDED** | The indicated device requires reinitialization due to hardware errors. The application should clean up and call [QOSCreateHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qoscreatehandle) again. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. |
| **ERROR_ADAP_HDW_ERR** | A network adapter hardware error occurred. |
| **ERROR_HOST_UNREACHABLE** | The network location cannot be reached. |

## Remarks

The use of IPv4/v6 mixed addresses is not supported in qWAVE. The address specified by the *DestAddr* parameter must be either IPv4 or IPv6.

If there is a requirement for network experiments over a specific network interface, the socket must be bound to that particular interface. Otherwise the most appropriate interface for the experiment, as indicated by the network stack, is assigned by the qWAVE subsystem.

Network traffic associated with this flow is not affected by making this call alone. For example, packet prioritization does not occur immediately.

There are two categories of applications that use this function: adaptive and non-adaptive. An adaptive application makes use of notifications and information in the [QOS_FLOW_FUNDAMENTALS](https://learn.microsoft.com/windows/desktop/api/qos2/ns-qos2-qos_flow_fundamentals) structure for adapting to network changes such as congestion. The qWAVE service uses Link Layer Topology Discovery (LLTD) QoS extensions for adaptive flows which can be present on the destination device.

After calling this function adaptive A/V applications should call the [QOSSetFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qossetflow) function with an *Operation* value of **QOSSetFlowRate** to affect network traffic.

A non-adaptive application either does not adapt to changing network characteristics or is sending traffic to an endpoint that does not support adaptive capabilities as indicated by ERROR_NOT_SUPPORTED.

Non-adaptive applications, or adaptive applications making non-adaptive flows, should call this function with the **QOS_NON_ADAPTIVE_FLOW** flag. After calling this function A/V applications should call the [QOSSetFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qossetflow) function with a *Operation*. **QOSSetFlow** does not need to be called unless shaping is desired.

#### Examples

The following code illustrates the use of **QOSAddSocketFromFlow**. The [QOSCreateHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qoscreatehandle) function is also shown to provide information on initialization of parameters used by **QOSAddSocketFromFlow**.

See the Windows SDK for a complete sample code listing. SDK folder: Samples\NetDs\GQos\Qos2

The Winsock2.h header file must be included to use WSAGetLastError and other Winsock functions.

```cpp
QOS_VERSION    Version;
HANDLE         QoSHandle = NULL;
QOS_FLOWID     QoSFlowId = 0; // Flow Id must be 0.
SOCKET        ConnectionSocket;
BOOL          QoSResult;

// Initialize the QoS version parameter.
Version.MajorVersion = 1;
Version.MinorVersion = 0;

// Get a handle to the QoS subsystem.
QoSResult = QOSCreateHandle(
    &Version,
    &QoSHandle );

if (QoSResult != TRUE)
{
    std::cerr << "QOSCreateHandle failed. Error: ";
    std::cerr << WSAGetLastError() << std::endl;
}

// Initialization of ConnectionSocket
// omitted for brevity, but is needed.
/////////////////////////////////////

// Add socket to flow.
QoSResult = QOSAddSocketToFlow(
    QoSHandle,
    ConnectionSocket,
    NULL,
    QOSTrafficTypeExcellentEffort,
     QOS_NON_ADAPTIVE_FLOW,
    &QoSFlowId);

if (QoSResult != TRUE)
{
    std::cerr << "QOSAddSocketToFlow failed. Error: ";
    std::cerr << WSAGetLastError() << std::endl;
}

```

## See also

[QOSCreateHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qoscreatehandle)

[Quality Windows Audio/Video Experience (qWAVE)](https://learn.microsoft.com/previous-versions/windows/desktop/qos/quality-windows-audio-video-experience--qwave-)