# IMbnConnectionContext::SetProvisionedContext

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Adds or updates a provisioned context.

## Parameters

### `provisionedContexts` [in]

An [MBN_CONTEXT](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_context) structure that specifies the provisioned context to be stored in the device or SIM.

### `providerID` [in]

A string that represents the network provider ID for which the provisioned context should be stored. The device should return the added provisioned context in response to any subsequent query when a SIM with this home provider ID is in the device.

### `requestID` [out]

A request ID set by the Mobile Broadband service to identify this asynchronous request.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_HANDLE** | Invalid interface. Most likely the Mobile Broadband device has been removed from the system. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | Invalid interface. Most likely the Mobile Broadband device has been removed from the system. |
| **HRESULT_FROM_WIN32(ERROR_SERVICE_NOT_ACTIVE)** | The Mobile Broadband service is not running on this system. |
| **E_INVALID_ARG** | *providerID* is not valid. |

## Remarks

The **contextID** of *provisionedContexts* specifies the index in the device or SIM memory where the context is to be stored. If it is set to [MBN_CONTEXT_ID_APPEND](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_context_constants), then the device shall find the appropriate index to store the context.

This is an asynchronous operation and **SetProvisionedContext** will return immediately. When the operation is complete, the Mobile Broadband service will notify the application by calling the [OnSetProvisionedContextComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnconnectioncontextevents-onsetprovisionedcontextcomplete) method of [IMbnConnectionContextEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectioncontextevents).

Additions to the provisioned context list for the current home provider ID will not be available for querying until the [OnProvisionedContextListChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnconnectioncontextevents-onprovisionedcontextlistchange) method of [IMbnConnectionContextEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectioncontextevents) has been called.

## See also

[IMbnConnectionContext](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectioncontext)