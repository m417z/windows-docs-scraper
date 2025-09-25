# QOSCreateHandle function

## Description

This function initializes the QOS subsystem and the *QOSHandle* parameter. The *QOSHandle* parameter is used when calling other QOS functions. **QOSCreateHandle** must be called before any other functions.

[QOSCloseHandle](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosclosehandle) closes handles created by this function.

## Parameters

### `Version` [in]

Pointer to a [QOS_VERSION](https://learn.microsoft.com/windows/desktop/api/qos2/ns-qos2-qos_version) structure that indicates the version of QOS being used. The **MajorVersion** member must be set to 1, and the **MinorVersion** member must be set to 0.

### `QOSHandle` [out]

Pointer to a variable that receives a QOS handle. This handle is used when calling other QOS functions.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0. To get extended error information, call **GetLastError**. Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **ERROR_GEN_FAILURE** | Internal logic error. Initialization failed. For example, if the host goes into sleep or standby mode, all existing handles and flows are rendered invalid. |
| **ERROR_INVALID_PARAMETER** | The *QOSHandle* parameter is invalid. |
| **ERROR_NOT_ENOUGH_MEMORY** | Indicates that a memory allocation failed. |
| **ERROR_NO_SYSTEM_RESOURCES** | There are insufficient resources to carry out the operation. |
| **ERROR_RESOURCE_DISABLED** | A resource required by the service is unavailable. This error may be returned if the user has not enabled the firewall exception for the qWAVE service. |
| **ERROR_SERVICE_DEPENDENCY_FAIL** | One of the dependencies of this service is unavailable. The qWAVE service could not be started. |

## Remarks

Every process intending to use qWAVE must first call **QOSCreateHandle**. The handle returned can be used for performing overlapped I/O. For example, this handle can be associated with an I/O completion port (IOCP) to receive overlapped completion notifications. This function can be called multiple times to obtain multiple handles although a single handle is sufficient for most applications.

If a machine enters a power save mode that interrupts connectivity such as sleep or standby, existing and active network experiments such as [QOSStartTrackingClient](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosstarttrackingclient) must be reinitiated. This recreation of the flow mirrors the cleanup and creation activities also necessary for existing sockets. A new handle must be created, and the flow must be recreated and readmitted.

#### Examples

The following code illustrates function use and required parameter initializations. Actual values will vary depending on QoS version.

Winsock.h must be included to use the [WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) function.

See the Windows SDK for a complete sample code listing. SDK folder: Samples\NetDs\GQos\Qos2

```cpp
QOS_VERSION Version;
HANDLE      QoSHandle = NULL;
BOOL        QoSResult = FALSE;

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

```

## See also

[Quality Windows Audio/Video Experience (qWAVE)](https://learn.microsoft.com/previous-versions/windows/desktop/qos/quality-windows-audio-video-experience--qwave-)