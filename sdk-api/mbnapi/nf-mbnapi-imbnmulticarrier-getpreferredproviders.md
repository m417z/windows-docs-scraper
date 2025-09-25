# IMbnMultiCarrier::GetPreferredProviders

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the list of subscribed providers visible in the current area for a multi-carrier device minus the current registered provider.

## Parameters

### `preferredMulticarrierProviders` [out, retval]

Pointer to an array of [MBN_PROVIDER2](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_provider2) structures that contain the list of preferred providers. If this method returns any value other than **S_OK**, *preferredMultiCarrierProviders* is **NULL**. When **GetPreferredProviders** returns **S_OK**, the calling application must free the allocated memory by calling [SafeArrayDestroy](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-safearraydestroy).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. *preferredMultiCarrierProviders* contains valid values. |
| **E_PENDING** | The information is not available. The Mobile Broadband service is currently probing for the list of preferred providers. The calling application can get notified when the data is available by registering for the [OnPreferredProvidersChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnmulticarrierevents-onpreferredproviderschange) method of [IMbnMultiCarrierEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnmulticarrierevents). |
| **E_MBN_PIN_REQUIRED** | The device requires that a PIN must be entered for this operation. |
| **E_MBN_SIM_NOT_INSERTED** | The SIM is not inserted. |
| **E_MBN_BAD_SIM** | A bad SIM is inserted in the device. |
| **HRESULT_FROM_WIN32(ERROR_READ_FAULT)** | Unable to read from the SIM or device memory. For example, the SIM does not have preferred provider information provisioned. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The device does not support this operation. CDMA devices will always return this value. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The operation is not supported by the device. This may be returned by devices which do not support multi-carrier. |

## Remarks

**GetPreferredProviders** returns the list of providers that are stored in the interface's preferred provider list.

For the recoverable errors **E_MBN_PIN_REQUIRED**, **E_MBN_SIM_NOT_INSERTED**, and **E_MBN_BAD_SIM**, the Mobile Broadband service will query the device again for the provider list when the error condition is over. For example, if the device requires a PIN to be entered to get the provider list, then **GetPreferredProviders** will return **E_MBN_PIN_REQUIRED**. When an application enters a PIN to unlock the device, the Mobile Broadband service will again try to get this information from the device.

When Windows is querying the device to get the provider list after a recoverable error has occurred, **GetPreferredProviders** immediately returns **E_PENDING**. Once the new query has completed, a notification is sent to the calling application using the appropriate callback method. For example, after a successful PIN unlock operation, the [OnEnterComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpinevents-onentercomplete) method of [IMbnPinEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinevents) would be called.

The Mobile Broadband service will update the application about the status of any new query by calling the [OnPreferredProvidersChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnmulticarrierevents-onpreferredproviderschange) method of [IMbnMultiCarrier](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnmulticarrier).

In some cases, the device's preferred provider list can be updated through the network by SMS or OTA (over-the-air update). Windows will notify the application of any change in the preferred provider list by calling the [OnPreferredProvidersChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnmulticarrierevents-onpreferredproviderschange) method of [IMbnMultiCarrier](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnmulticarrier).

A preferred list of providers is available if the user has multiple subscriptions (at least more than one) or the device has pre-provisioned for preferred networks and is in the coverage area of any of the networks. This list may be empty even if the user has subscribed to multiple networks and is outside of those coverage areas. This list will contain all of the currently visible networks that the user has subscribed to or the device has pre-provisioned for except for the currently registered network.

Provisioning can also result in a new home provider being added to the existing preferred list on a multi-carrier device. This is accomplished using [SetHomeProvider](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnmulticarrier-sethomeprovider).

## See also

[IMbnMultiCarrier](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnmulticarrier)