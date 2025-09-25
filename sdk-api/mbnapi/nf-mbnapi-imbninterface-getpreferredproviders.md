# IMbnInterface::GetPreferredProviders

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the list of preferred providers.

## Parameters

### `preferredProviders` [out, retval]

Pointer to an array of [MBN_PROVIDER](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_provider) structures that contains the list of preferred providers. If this method returns any value other than **S_OK**, this parameter is **NULL**. When **GetPreferredProviders** returns **S_OK**, the calling application must free the allocated memory by calling [SafeArrayDestroy](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-safearraydestroy).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. *preferredProviders* contains valid values. |
| **E_PENDING** | The information is not available. The Mobile Broadband service is currently probing for the list of preferred providers. The calling application can get notified when the data is available by registering for the [OnPreferredProvidersChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterfaceevents-onpreferredproviderschange) method of [IMbnInterfaceEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfaceevents). |
| **E_MBN_PIN_REQUIRED** | The device requires that a PIN must be entered for this operation. |
| **E_MBN_SIM_NOT_INSERTED** | The SIM is not inserted. |
| **E_MBN_BAD_SIM** | A bad SIM is inserted in the device. |
| **HRESULT_FROM_WIN32(ERROR_READ_FAULT)** | Unable to read from the SIM or device memory. For example, the SIM does not have preferred provider information provisioned. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The device does not support this operation. CDMA devices will always return this value. |

## Remarks

**GetPreferredProviders** returns the list of providers that are stored in the interface's preferred provider list.

For the recoverable errors **E_MBN_PIN_REQUIRED**, **E_MBN_SIM_NOT_INSERTED**, and **E_MBN_BAD_SIM**, the Mobile Broadband service will query the device again for the provider list when the error condition is over. For example, if the device requires a PIN to be entered to get the provider list, then **GetPreferredProviders** will return **E_MBN_PIN_REQUIRED**. When an application enters a PIN to unlock the device, then the Mobile Broadband service will again try to get this information from the device.

When the operating system is querying the device to get the provider list after a recoverable error has occurred, **GetPreferredProviders** immediately returns **E_PENDING**. Once the new query has completed, a notification is sent to the calling application using the appropriate callback method. For example, after a successful PIN unlock operation, the [OnEnterComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpinevents-onentercomplete) method of [IMbnPinEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinevents) would be called. After recovering from a SIM card error, the [OnReadyStateChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterfaceevents-onreadystatechange) method of [IMbnInterfaceEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfaceevents) would be called.

The Mobile Broadband service will update the application about the status of any new query by calling the [OnPreferredProvidersChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterfaceevents-onpreferredproviderschange) method of [IMbnInterfaceEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfaceevents).

In some cases, the device's preferred provider list can be updated through the network by SMS or OTA (over-the-air update). The operating system will notify the application of any change in the preferred provider list by calling the [OnPreferredProvidersChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterfaceevents-onpreferredproviderschange) method of [IMbnInterfaceEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfaceevents).

## See also

[IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface)