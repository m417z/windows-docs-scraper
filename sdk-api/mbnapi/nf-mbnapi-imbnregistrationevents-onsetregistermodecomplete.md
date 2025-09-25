# IMbnRegistrationEvents::OnSetRegisterModeComplete

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method called by the Mobile Broadband service to indicate that it has completed a set registration operation.

## Parameters

### `newInterface` [in]

Pointer to an [IMbnRegistration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistration) interface that represents the applicable device. The handling application can use this interface to get the current registration state of the device.

### `requestID` [in]

The request ID assigned by the Mobile Broadband service to track the set registration operation.

### `status` [in]

A status code that indicates the outcome of the operation.

A calling application can expect one of the possible values.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_STATE)** | There is already an active network connection. The registration mode cannot be changed when there is an already established data connection. The application should first disconnect the connection and then try changing registration mode. If the device is already in the requested mode and connected to requested provider, then the return code will be **S_OK**. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The operation is not supported by the device. This may be returned by devices which do not support the requested registration mode. For example, a CDMA device will return this error when requested to switch to manual registration mode. |
| **E_FAIL** | The operation could not be completed. More information is available in the network error code. |
| **E_INVALIDARG** | Invalid registration mode input or the provider ID provided as input is longer than maximum length 7 characters or data class provided is invalid. the Mobile Broadband service will not send the request to the device when invalid arguments are provided in the input.<br><br>In manual registration mode, this indicates that the requested provider is forbidden. |
| **E_MBN_PIN_REQUIRED** | A PIN is needed for the operation to complete. |
| **E_MBN_SERVICE_NOT_ACTIVATED** | The network service subscription has expired. |
| **E_MBN_PROVIDER_NOT_VISIBLE** | This occurs only when switching to manual registration mode. The switch is successful but the requested provider is not visible. The device will register to the requested provider when it is visible. |

## Return value

This method must return **S_OK**.

## See also

[IMbnRegistrationEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistrationevents)