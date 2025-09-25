# IMbnRegistration::GetRegisterMode

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the network registration mode of a Mobile Broadband device.

## Parameters

### `registerMode` [out]

A pointer to a [MBN_REGISTER_MODE](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_register_mode) value that specifies the current network registration mode of the device. The value is meaningful only if the method returns **S_OK**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_PENDING** | The registration mode is not available. The Mobile Broadband service is currently probing the device for the information. When the registration mode is available, the Mobile Broadband service will call the [OnRegisterModeAvailable](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnregistrationevents-onregistermodeavailable) method of [IMbnRegistrationEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistrationevents). |
| **E_MBN_PIN_REQUIRED** | A PIN is required to get the register mode. |
| **E_MBN_SIM_NOT_INSERTED** | A SIM is not inserted in the device. |
| **E_MBN_BAD_SIM** | A bad SIM is inserted in the device. |

## Remarks

See [MBN_REGISTER_MODE](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_register_mode) for details on possible registration modes.

For recoverable error **E_MBN_PIN_REQUIRED**, the Mobile Broadband service will again try to fetch this information from the device when the error condition is over (when a PIN is entered). Then the Mobile Broadband service will call the [OnRegisterModeAvailable](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnregistrationevents-onregistermodeavailable) method of [IMbnRegistrationEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistrationevents).

## See also

[IMbnRegistration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistration)