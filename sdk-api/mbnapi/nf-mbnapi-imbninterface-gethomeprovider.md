# IMbnInterface::GetHomeProvider

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the home provider.

## Parameters

### `homeProvider` [out, retval]

A pointer to an [MBN_PROVIDER](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_provider) structure that represents the home provider. If this method returns any value other than **S_OK**, this parameter is **NULL**. Upon completion, the calling application must free the memory allocated to the **providerID** and **providerName** members of **MBN_PROVIDER** by calling [SysFreeString](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysfreestring)

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. *homeProvider* contains valid values. |
| **E_PENDING** | The information is not available. The Mobile Broadband service is currently probing to get the home provider. The calling application can get notified when the home provider is available by registering for the [OnHomeProviderAvailable](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterfaceevents-onhomeprovideravailable) method of [IMbnInterfaceEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfaceevents). |
| **E_MBN_PIN_REQUIRED** | The device requires that a PIN must be entered for this operation. |
| **E_MBN_SIM_NOT_INSERTED** | The SIM is not inserted. |
| **E_MBN_BAD_SIM** | A bad SIM is inserted in the device. |
| **HRESULT_FROM_WIN32(ERROR_READ_FAULT)** | Unable to read from the SIM or device memory. For example, the SIM does not have home provider information provisioned. |

## Remarks

**GetHomeProvider** returns the home provider information for the device. The **dataClass** field of returned [MBN_PROVIDER](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_provider) structure should be ignored.

For the recoverable errors **E_MBN_PIN_REQUIRED**, **E_MBN_SIM_NOT_INSERTED**, and **E_MBN_BAD_SIM**, the Mobile Broadband service will query the device again for the home provider when the error condition is over. For example, if the device requires a PIN to be entered to retrieve this information, then it will return **E_MBN_PIN_REQUIRED**. When the application enters the PIN to unlock the device, then the Mobile Broadband service will again try to get this information from the device. The system will update the application about the status of new query by calling the [OnHomeProviderAvailable](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterfaceevents-onhomeprovideravailable) method of [IMbnInterfaceEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfaceevents).

The registered [OnHomeProviderAvailable](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterfaceevents-onhomeprovideravailable) method of [IMbnInterfaceEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfaceevents) can be either called when home provider information is available or the new query completed with error. Once this function returns success then this information will never change.

## See also

[IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface)