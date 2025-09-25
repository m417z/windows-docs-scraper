# QOSSetFlow function

## Description

The **QOSSetFlow** function is called by an application to request the QOS subsystem to prioritize the application's packets and change the flow traffic. This function is also used to notify the QoS subsystem of a flow change: for example, if the flow rate is changed in order to account for network congestion, or if the QoS priority value requires adjustment for transferring or streaming different types of content over a single persistent socket connection.

## Parameters

### `QOSHandle` [in]

Handle to the QOS subsystem returned by [QOSCreateHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qoscreatehandle).

### `FlowId` [in]

A flow identifier. A **QOS_FLOWID** is an unsigned 32-bit integer.

### `Operation` [in]

A [QOS_SET_FLOW](https://learn.microsoft.com/windows/desktop/api/qos2/ne-qos2-qos_set_flow) enumerated type that identifies what will be changed in the flow. This parameter specifies what structure the *Buffer* will contain.

| Value | Meaning |
| --- | --- |
| **QOSSetTrafficType**<br><br>0 | The traffic type of the flow will be changed. The *Buffer* will contain a pointer to a [QOS_TRAFFIC_TYPE](https://learn.microsoft.com/windows/desktop/api/qos2/ne-qos2-qos_traffic_type) constant. |
| **QOSSetOutgoingRate**<br><br>1 | The flow rate will be changed. The *Buffer* will contain a pointer to a [QOS_FLOWRATE_OUTGOING](https://learn.microsoft.com/windows/desktop/api/qos2/ns-qos2-qos_flowrate_outgoing) structure. |
| **QOSSetOutgoingDSCPValue**<br><br>2 | Windows 7, Windows Server 2008 R2, and later: The outgoing DSCP value will be changed. The *Buffer* will contain a pointer to a **DWORD** value that defines the arbitrary DSCP value.<br><br>**Note** This setting requires the calling application be a member of the Administrators or the Network Configuration Operators group. |

### `Size` [in]

The size of the *Buffer* parameter, in bytes.

### `Buffer` [in]

Pointer to the structure specified by the value of the *Operation* parameter.

### `Flags`

Reserved for future use. This parameter must be set to 0.

### `Overlapped` [out, optional]

Pointer to an OVERLAPPED structure used for asynchronous output. This must be set to **NULL** if this function is not being called asynchronously.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0. To get extended error information, call **GetLastError**. Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DISABLED_BY_POLICY** | The QoS subsystem is currently configured by policy to not allow this operation on the network path between this host and the destination host. For example, the default policy prevents qWAVE experiments from running to off-link destinations. |
| **ERROR_IO_PENDING** | The update flow request was successfully received. Results will be returned during overlapped completion. |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges for the requested operation. |
| **ERROR_INVALID_HANDLE** | The *QOSHandle* parameter is invalid. |
| **ERROR_INVALID_PARAMETER** | The *FlowId* parameter is invalid. |
| **ERROR_NETWORK_BUSY** | The requested flow properties were not available on this path. |
| **ERROR_NOT_FOUND** | The *FlowId* parameter specified cannot be found. |
| **ERROR_NOT_ENOUGH_MEMORY** | A memory allocation failed. |
| **ERROR_NOT_SUPPORTED** | The operation being performed requires information that the QoS subsystem does not have. Obtaining this information on this network is currently not supported. For example, bandwidth estimations cannot be obtained on a network path where the destination host is off-link. |
| **ERROR_NO_SYSTEM_RESOURCES** | There are insufficient resources to carry out the operation. |
| **ERROR_IO_DEVICE** | The request could not be performed because of an I/O device error. |
| **ERROR_DEVICE_REINITIALIZATION_NEEDED** | The indicated device requires reinitialization due to hardware errors. The application should clean up and call [QOSCreateHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qoscreatehandle) again. |
| **ERROR_ADAP_HDW_ERR** | A network adapter hardware error occurred. |
| **ERROR_HOST_UNREACHABLE** | The network location cannot be reached. |
| **ERROR_RETRY** | There is currently insufficient data about networking conditions to answer the query. This is typically a transient state where qWAVE has erred on the side of caution as it awaits more data before ascertaining the state of the network. |
| **ERROR_UNEXP_NET_ERR** | The network connection with the remote host failed. |

## Remarks

If [QOSStartTrackingClient](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosstarttrackingclient) has not already been called, calling **QOSSetFlow** will cause the QOS subsystem to perform the following.

* Discover whether the end-to-end network path supports prioritization.
* Track end-to-end network characteristics by way of network experiments. These experiments do not place any noteworthy stress on the network.

If **QOSSetFlow** returns **ERROR_NETWORK_BUSY** there is insufficient bandwidth for the specified flow rate and network priority cannot be granted. The application can still transmit a data stream but the flow will not receive priority marking. Ideally an application would not attempt to stream at the requested rate if there is insufficient bandwidth. If **ERROR_NETWORK_BUSY** is returned the following safe strategy is available:

1. Query the QoS subsystem with [QOSNotifyFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosnotifyflow) in order to determine the current available bandwidth and begin to stream at the received lower rate with priority if the network supports it.
2. Request notification with [QOSNotifyFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosnotifyflow) for when the originally desired amount of bandwidth is available. When notification is received call **QOSSetFlow** with the new bandwidth request and send at the new rate again with prioritization if supported.

This function may optionally be called asynchronously.

#### Examples

The following code snippet demonstrates the use of QOSSetFlow in an application. Input parameters *QOSHandle*, *FlowId*, *FlowId*, *QOSSetOutgoingRate*, and **sizeof**(*QoSOutgoingFlowrate*) must be previously initialized by other QoS functions and calculations within the application.

Other QoS function examples that show initialization of parameters include [QOSCreateHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qoscreatehandle), [QOSAddSocketToFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosaddsockettoflow), and [QOSQueryFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosqueryflow).

See the Windows SDK for a complete sample code listing. SDK folder: Samples\NetDs\GQos\Qos2

```cpp
if( QOSSetFlow( QOSHandle,
        FlowId,
        QOSSetOutgoingRate,           // Operation
        sizeof(QoSOutgoingFlowrate),  // Size
        &QoSOutgoingFlowrate,         // Buffer
        0,                            // Flags (Must be set to 0 with QoS Version 1.0)
        NULL)                         // Overlapped
        == 0 )
{
    if( ERROR_INVALID_PARAMETER == GetLastError())
    {
        std::cerr << __FILE__ <<" Line: " << __LINE__ ;
        std::cerr << " - QOSSetFlow failed. Exception code: ";
        std::cerr << GetLastError() << " - Invalid parameter";
        std::cerr << std::endl;
    }
    else
    {
        std::cerr << __FILE__ <<" Line: " << __LINE__ ;
        std::cerr << " - QOSSetFlow failed. Exception code: ";
        std::cerr << GetLastError() << std::endl;
    }

}
else
{
    std::cout << "QOSSetFlow set outgoing flowrate bandwidth to ";
    std::cout << QoSOutgoingFlowrate.Bandwidth;
    std::cerr << std::endl;
}

```

## See also

[Quality Windows Audio/Video Experience (qWAVE)](https://learn.microsoft.com/previous-versions/windows/desktop/qos/quality-windows-audio-video-experience--qwave-)