# IMbnConnectionContext::GetProvisionedContexts

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets a list of connection contexts.

## Parameters

### `provisionedContexts` [out, retval]

A list of [MBN_CONTEXT](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_context) values that represent connection contexts stored in the device. On error, this array is **NULL**. When successful, the calling application must free the allocated memory by calling [SafeArrayDestroy](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-safearraydestroy).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_PENDING** | The connection contexts are not available. The Mobile Broadband service is probing the device for the information. The calling application can get notified when the connection contexts are available by registering for the [OnProvisionedContextListChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnconnectioncontextevents-onprovisionedcontextlistchange) method of [IMbnConnectionContextEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectioncontextevents). |
| **E_MBN_PIN_REQUIRED** | A PIN is required to get the connection contexts. |
| **E_MBN_SIM_NOT_INSERTED** | A SIM is not inserted in the device. |
| **E_MBN_BAD_SIM** | A bad SIM is inserted in the device. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The device does not support retrieval of provisioned contexts. |

## Remarks

A connection context is an abstraction of a specific set of network configuration parameters for setting up a virtual circuit or flow on top of the physical Mobile Broadband connection at layer 2. In GSM, it corresponds to the concept of a PDP context; in CDMA, it corresponds to a network profile.

In some cases, connection parameters are already available in device/SIM memory. This method can be used to get a list of stored connection contexts stored in device for the current home provider network.

Only contexts of type **MBN_CONTEXT_TYPE_INTERNET** should be used for making data connections.

A device will return all of the stored contexts for the current home provider. Some of the contexts can be empty and they will be reported as **MBN_CONTEXT_TYPE_NONE**.

Sometimes, stored provisioned contexts can be updated by the network through SMS or OTA. Whenever there is a change in the device-provisioned contexts, the Mobile Broadband service will call the [OnProvisionedContextListChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnconnectioncontextevents-onprovisionedcontextlistchange) method of [IMbnConnectionContextEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectioncontextevents). An application can then use this method to get the updated list of provisioned contexts.

For the recoverable errors **E_MBN_PIN_REQUIRED**, **E_MBN_SIM_NOT_INSERTED**, and **E_MBN_BAD_SIM**, the Mobile Broadband service will query the device again for this information when the error condition is over. For example, if the device required a PIN to be entered to retrieve the connection contexts, then it will return **E_MBN_PIN_REQUIRED**. When the application enters a PIN to unlock the device, then the service will again try to get this information from the device. The service will update the application about the status of the new query by calling the [OnProvisionedContextListChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnconnectioncontextevents-onprovisionedcontextlistchange) method of [IMbnConnectionContextEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectioncontextevents).

## See also

[IMbnConnectionContext](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectioncontext)