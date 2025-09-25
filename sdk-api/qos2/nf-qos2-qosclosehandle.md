# QOSCloseHandle function

## Description

The **QOSCloseHandle** function closes a handle returned by the [QOSCreateHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qoscreatehandle) function.

## Parameters

### `QOSHandle` [in]

Handle to the QOS subsystem returned by [QOSCreateHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qoscreatehandle).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0. To get extended error information, call **GetLastError**.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *QOSHandle* parameter is invalid. |

## Remarks

All flows added on the handle being closed are immediately removed from the system. Any traffic going out of a socket used to create these flows will no longer be marked with priority values. Any pending operations on these flows are immediately completed with **ERROR_ABORTED**.

If any clients were being tracked through the handle being closed by a previous call to the [QOSStartTrackingClient](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosstarttrackingclient) function, **QOSCloseHandle** indicates that the application is no longer using the client endpoint.

#### Examples

The following "CleanUpQos" function illustrates the use of [QOSRemoveSocketFromFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosremovesocketfromflow) and **QOSCloseHandle**:

See the Windows SDK for a complete sample code listing. SDK folder: Samples\NetDs\GQos\Qos2

The Winsock2.h header file must be included to use Winsock defined identifiers or functions.

```cpp
int CleanUpQos( HANDLE qosHandle,
           SOCKET connSocket,
           QOS_FLOWID qosFlowId,
           DWORD qosFlags // qosFlags must be 0
           )
{
  // To ensure against generating an ERROR_OPERATION_ABORTED exception
  // use a separate thread and Mutex protection to verify completion
  // of QOSRemoveSocketFromFlow before calling QOSCloseHandle.

  int result = 0;

  if (qosFlowId != 0)
  {
    if( QOSRemoveSocketFromFlow(
        qosHandle,
        connSocket,
        qosFlowId,
        qosFlags) != TRUE)

            result = WSAGetLastError();
  }

  // Under Mutex protection, add Wait function here.

  if (qosHandle != NULL)
  {
    if( QOSCloseHandle(qosHandle) != TRUE)
        result = WSAGetLastError();
  }

  return(result);

}

```

## See also

[Quality Windows Audio/Video Experience (qWAVE)](https://learn.microsoft.com/previous-versions/windows/desktop/qos/quality-windows-audio-video-experience--qwave-)