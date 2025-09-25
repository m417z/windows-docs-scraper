# QOSStartTrackingClient function

## Description

The **QOSStartTrackingClient** function notifies the QOS subsystem of the existence of a new client. Calling this function increases the likelihood that the QOS subsystem will have gathered sufficient information on the network path to assist when calling [QOSSetFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qossetflow) to set the flow.

**Note** This call is not required to add a flow with the [QOSAddSocketToFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosaddsockettoflow) function although it is highly recommended. Not calling this function may require network experiments to be started during the [QOSSetFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qossetflow) call and can result in **QOSSetFlow** failing with **ERROR_NETWORK_BUSY** on initial use.

## Parameters

### `QOSHandle` [in]

Handle to the QOS subsystem returned by [QOSCreateHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qoscreatehandle).

### `DestAddr` [in]

A pointer to a [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure that contains the IP address of the client device. Clients are identified by their IP address and address family. Any port number specified in the sockaddr structure will be ignored.

### `Flags`

Reserved for future use. Must be set to 0.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0. To get extended error information, call **GetLastError**. Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The *QOSHandle* parameter is invalid. |
| **ERROR_INVALID_PARAMETER** | The *DestAddr* parameter is invalid. |
| **ERROR_NOT_ENOUGH_MEMORY** | Indicates that a memory allocation failed. |
| **ERROR_NO_SYSTEM_RESOURCES** | There are insufficient resources to carry out the operation. |
| **ERROR_IO_DEVICE** | The request could not be performed because of an I/O device error. |
| **ERROR_DEVICE_REINITIALIZATION_NEEDED** | The indicated device requires reinitialization due to hardware errors. The application should clean up and call [QOSCreateHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qoscreatehandle) again. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. |
| **ERROR_ADAP_HDW_ERR** | A network adapter hardware error occurred. |
| **ERROR_HOST_UNREACHABLE** | The network location cannot be reached. |

## Remarks

On receipt of a **QOSStartTrackingClient** call the QoS subsystem begins gathering information about the client such as the QoS capabilities and available bandwidth on the end-to-end path.

An application should call this function as soon as it becomes aware of a client device that may need QoS flow. For example this function should be called when a media player device first connects to a media server application.

Network experiments performed by **QOSStartTrackingClient** do not introduce noteworthy load on the network even if no stream is started for a long period of time. The qWAVE service dynamically adjusts experiment traffic based on QoS subsystem activity.

Link Layer Topology Discovery (LLTD) must be implemented on the sink PC or device for this function to work.

#### Examples

The following code illustrates function use, handling a common exception, and required parameter initializations. Actual parameter values can vary depending on QoS version. The Winsock2.h header file must be included to use Winsock defined identifiers or functions.

```cpp
QOS_VERSION    Version;
HANDLE         QoSHandle = NULL;
BOOL        QoSResult = FALSE;

Version.MajorVersion = 1;
Version.MinorVersion = 0;

// Get a handle to the QoS subsystem (required for tracking).
QoSResult = QOSCreateHandle(
    &Version,
    &QoSHandle );

if(!QOSStartTrackingClient(QoSHandle, (sockaddr*)ptr->ai_addr, 0))
{
    std::cerr << std::endl;
    std::cerr << __FILE__ <<" Line: " << __LINE__ ;
    std::cerr << " - QOSStartTrackingClient failed. Exception code: ";
    std::cerr << GetLastError();

    if (GetLastError() == ERROR_NOT_SUPPORTED)
    {
        std::cerr << std::endl;
        std::cerr << " ERROR_NOT_SUPPORTED" << std::endl;
        std::cerr << "This operation requires information";
        std::cerr << "that the QoS subsystem does not have. " << std::endl;
    }
}
else
    std::cout << "QoS client tracking started." << std::endl;

```

## See also

[QOSCreateHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qoscreatehandle)

[Quality Windows Audio/Video Experience (qWAVE)](https://learn.microsoft.com/previous-versions/windows/desktop/qos/quality-windows-audio-video-experience--qwave-)