# IMbnRegistration::SetRegisterMode

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Sets the registration mode for the device.

## Parameters

### `registerMode` [in]

An [MBN_REGISTER_MODE](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_register_mode) value that specifies the new registration mode.

### `providerID` [in]

A string that specifies the provider ID of the network provider to which to register. Must be **NULL** when *registerMode* is **MBN_REGISTER_MODE_AUTOMATIC**.

### `dataClass` [in]

A bitwise combination of OR [MBN_DATA_CLASS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_data_class) values that specify the preferred data access technologies for the connection. The Mobile Broadband service will register the highest available data class technology from this list. If no data class from this list can be registered to, then the Mobile Broadband service will register to the best available data class.

### `requestID` [out]

A request ID set by the Mobile Broadband service to identify this asynchronous request.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **HRESULT_FROM_WIN32(ERROR_SERVICE_NOT_ACTIVE)** | The Mobile Broadband service is not running on this system. |
| **E_HANDLE** | The interface is invalid, most likely because the Mobile Broadband device has been removed from the system. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The interface is invalid. Most likely the Mobile Broadband device has been removed from the system. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_STATE)** | There is already an active network connection. The registration mode cannot be changed while there is an already established data connection. The calling application should first disconnect the connection and then try changing registration mode. If the device is already in the requested mode and connected to the requested provider, then the return code will be **S_OK**. |

## Remarks

The **SetRegisterMode** method can be used to set a device into automatic or manual network selection mode. For manual registration mode the network ID to which the device should register is supplied in *providerID*.

Support for manual registration mode is optional and the application should verify that the device supports manual registration by checking for **MBN_CTRL_CAPS_REG_MANUAL** in the *interfaceCaps* parameter filled by the [GetInterfaceCapability](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterface-getinterfacecapability) method of [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface). If an application sets the manual registration mode and it is not supported by the device, then this call will return **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)**.

**SetRegisterMode** is asynchronous and will return immediately. If there is no error, on completion of the operation, the Mobile Broadband service will call the [OnSetRegisterModeComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnregistrationevents-onsetregistermodecomplete) method of [IMbnRegistrationEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistrationevents).

## See also

[IMbnRegistration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistration)