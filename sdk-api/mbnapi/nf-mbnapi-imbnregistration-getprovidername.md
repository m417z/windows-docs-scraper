# IMbnRegistration::GetProviderName

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the provider name for the currently registered network.

## Parameters

### `providerName` [out]

Pointer to a string that contains the name of the currently registered provider. The maximum length of this string is **MBN_PROVIDERNAME_LEN** characters. The string is filled only when the method returns **S_OK** for success. Upon success, the calling application must free the allocated memory by calling [SysFreeString](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysfreestring).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_PENDING** | The provider name is not available. The Mobile Broadband service is currently probing the device for the information. When the provider name is available, the Mobile Broadband service will call the [OnRegisterModeAvailable](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnregistrationevents-onregistermodeavailable) method of [IMbnRegistrationEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistrationevents). |
| **E_MBN_PIN_REQUIRED** | A PIN is required to get the provider name. |
| **E_MBN_SIM_NOT_INSERTED** | A SIM is not inserted in the device. |
| **E_MBN_BAD_SIM** | A bad SIM is inserted in the device. |

## Remarks

The provider name may change when the Mobile Broadband device moves from one network to another. This includes whenever there is change from **MBN_REGISTER_STATE_HOME** to **MBN_REGISTER_STATE_SEARCHING** in the network registration state. This also occurs when there is a change in the registered network, such as when a network changes its registration from one provider to another. After such changes, the Mobile Broadband service will call the [OnRegisterStateChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnregistrationevents-onregisterstatechange) method of [IMbnRegistrationEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistrationevents). When this happens, the application should call [GetProviderID](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnregistration-getproviderid).

For the recoverable error **E_MBN_PIN_REQUIRED**, the Mobile Broadband service will try to refetch this information from the device when the error condition is over (when a PIN is entered). Then it will call the [OnRegisterStateChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnregistrationevents-onregisterstatechange) method of [IMbnRegistrationEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistrationevents).

## See also

[IMbnRegistration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistration)