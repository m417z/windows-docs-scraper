# IMbnRegistration::GetRegisterState

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the registration state.

## Parameters

### `registerState` [out]

A pointer an [MBN_REGISTER_STATE](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_register_state) value that specifies to the current registration state of the device. The value is meaningful only if the method returned **S_OK**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_PENDING** | The registration state is not available. The Mobile Broadband service is currently probing the device for the information. When the registration state is available, the Mobile Broadband service will call the [OnRegisterStateChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnregistrationevents-onregisterstatechange) method of [IMbnRegistrationEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistrationevents). |
| **E_MBN_PIN_REQUIRED** | A PIN is required to get the registration state. |

## Remarks

The **GetRegisterState** method gets the current network registration state of the device. The device can be registered to a network, searching the network for registration, or it can be denied registration.

The registration state of device can change automatically. For example, when the device goes out of the network coverage area, it changes the registration state from **MBN_REGISTER_STATE_HOME** to **MBN_REGISTER_STATE_SEARCHING**.

An application can register for receiving registration state change updates by connecting [IMbnRegistrationEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistrationevents) interface. Windows will call the [OnRegisterStateChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnregistrationevents-onregisterstatechange) method of **IMbnRegistrationEvents** to notify the application about these changes.

For the recoverable error **E_MBN_PIN_REQUIRED**, the Mobile Broadband service will again try to fetch this information from the device when the error condition is over (when a PIN is entered). Then it will call the [OnRegisterStateChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnregistrationevents-onregisterstatechange) method of [IMbnRegistrationEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistrationevents).

## See also

[IMbnRegistration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistration)