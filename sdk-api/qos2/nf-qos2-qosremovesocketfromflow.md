# QOSRemoveSocketFromFlow function

## Description

The **QOSRemoveSocketFromFlow** function notifies the QOS subsystem that a previously added flow has been terminated by the application, and that the subsystem must update its internal information accordingly.

## Parameters

### `QOSHandle` [in]

Handle to the QOS subsystem returned by [QOSCreateHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qoscreatehandle).

### `Socket` [in, optional]

Socket to be removed from the flow.

Only flows created with the **QOS_NON_ADAPTIVE_FLOW** flag may have multiple sockets added to the same flow. By passing the *Socket* parameter in this call, each socket can be removed individually. If the *Socket* parameter is not passed, the entire flow will be destroyed. If only one socket was attached to the flow, passing this socket as a parameter to this function and passing **NULL** as a socket are equivalent calls.

### `FlowId` [in]

A flow identifier. A **QOS_FLOWID** is an unsigned 32-bit integer.

### `Flags`

Reserved for future use. This parameter must be set to 0.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0. To get extended error information, call **GetLastError**. Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The *QOSHandle* parameter is invalid. |
| **ERROR_NOT_FOUND** | The *FlowId* parameter is invalid. |
| **ERROR_NOT_ENOUGH_MEMORY** | A memory allocation failed. |
| **ERROR_NO_SYSTEM_RESOURCES** | There are insufficient system resources to carry out the operation. |
| **ERROR_OPERATION_ABORTED** | The request was blocked. |
| **ERROR_IO_DEVICE** | The request could not be performed because of an I/O device error. |
| **ERROR_DEVICE_REINITIALIZATION_NEEDED** | The indicated device requires reinitialization due to hardware errors. The application should clean up and call [QOSCreateHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qoscreatehandle) again. |
| **ERROR_HOST_UNREACHABLE** | The network location cannot be reached. |

## Remarks

Calling the [QOSCloseHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosclosehandle) function immediately aborts all pending operations and flows added by that handle. If a handle is closed while a **QOSRemoveSocketFromFlow** call is still progress, the call will complete with **ERROR_OPERATION_ABORTED**.

#### Examples

The following code snippet demonstrates the use of **QOSRemoveSocketFromFlow**, [QOSStopTrackingClient](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosclosehandle), and **QOSCloseHandle** in an application function used for "cleaning up" QoS resources. See [QOSCreateHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qoscreatehandle) function for information on initialization of parameters.

See the Windows SDK for a complete sample code listing. SDK folder: Samples\NetDs\GQos\Qos2

**Note** The winsock2.h header file must be included to use WSAGetLastError and other Winsock functions.

```cpp
int CleanUpQos( HANDLE qosHandle,
            SOCKET connSocket,
            QOS_FLOWID qosFlowId,
            DWORD qosFlags,
            addrinfo *ptrAdrinfo) // qosFlags must be 0
{

    int result = 0;
    BOOL removeStatus = FALSE;

    // The global variable gblClientTracking would be set on successful
    // call to the QOSStartTrackingClient function.
    if(gblClientTracking == TRUE && qosHandle != NULL)
    {
        if(!QOSStopTrackingClient(qosHandle, (sockaddr*)ptrAdrinfo->ai_addr, 0))
        {
            gblClientTracking = FALSE;
            std::cerr << std::endl;
            std::cerr << __FILE__ <<" Line: " << __LINE__ ;
            std::cerr << " - QOSStartTrackingClient failed. Exception code: ";
            std::cerr << GetLastError() ;
        }
        else
        {
            std::cout << "QoS client tracking stopped." << std::endl;
        }
    }

    if (qosFlowId != 0 )
    {
        if( QOSRemoveSocketFromFlow(
                qosHandle,
                connSocket,
                qosFlowId,
                qosFlags) != TRUE)
        {
            result = WSAGetLastError();
        }
        else
        {
            // Mutex + Wait function would provide additional protection
            // against the possibility of ERROR_OPERATION_ABORTED exception.
            if( QOSCloseHandle(qosHandle) != TRUE)
                result = WSAGetLastError();
        }
    }

    return(result);
}

```

## See also

[Quality Windows Audio/Video Experience (qWAVE)](https://learn.microsoft.com/previous-versions/windows/desktop/qos/quality-windows-audio-video-experience--qwave-)