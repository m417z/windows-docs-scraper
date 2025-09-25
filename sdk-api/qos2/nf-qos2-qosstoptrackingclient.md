# QOSStopTrackingClient function

## Description

The **QOSStopTrackingClient** function notifies the QoS subsystem to stop tracking a client that has previously used the [QOSStartTrackingClient](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosstarttrackingclient) function. If a flow is currently in progress, this function will not affect it.

## Parameters

### `QOSHandle` [in]

Handle to the QOS subsystem returned by [QOSCreateHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qoscreatehandle).

### `DestAddr` [in]

Pointer to a [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure that contains the IP address of the client device. Clients are identified by their IP address and address family. A port number is not required and will be ignored.

### `Flags`

Reserved for future use.

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
| **ERROR_DEVICE_REINITIALIZATION_NEEDER** | The indicated device requires reinitialization due to hardware errors. The application should clean up and call [QOSCreateHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qoscreatehandle) again. |
| **ERROR_ADAP_HDW_ERR** | A network adapter hardware error occurred. |

## Remarks

The Winsock2.h header file must be included to use Winsock defined identifiers or functions.

#### Examples

The following code shows this function called in an application setting. See [QOSStartTrackingClient](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosstarttrackingclient) for parameter information.

```cpp
if(!QOSStopTrackingClient(QoSHandle, (sockaddr*)ptr->ai_addr, 0))
{
    std::cerr << std::endl;
    std::cerr << __FILE__ <<" Line: " << __LINE__ ;
    std::cerr << " - QOSStartTrackingClient failed. Exception code: ";
    std::cerr << GetLastError() ;
}
else
{
    std::cout << "QoS client tracking stopped." << std::endl;
}

```

## See also

[QOSStartTrackingClient](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosstarttrackingclient)

[Quality Windows Audio/Video Experience (qWAVE)](https://learn.microsoft.com/previous-versions/windows/desktop/qos/quality-windows-audio-video-experience--qwave-)