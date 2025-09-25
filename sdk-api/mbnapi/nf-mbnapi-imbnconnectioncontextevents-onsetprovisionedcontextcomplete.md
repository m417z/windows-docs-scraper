# IMbnConnectionContextEvents::OnSetProvisionedContextComplete

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method called by the Mobile Broadband service to indicate that the provisioned context in the device has been set.

## Parameters

### `newInterface` [in]

An [IMbnConnectionContext](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectioncontext) interface that represents the device for which the context has been set.

### `requestID` [in]

A request ID set by the Mobile Broadband service to identify the operation that set the context.

### `status` [in]

A status code that indicates the outcome of the operation.

A calling application can expect one of the following values.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The device does not support this operation. |
| **E_MBN_PIN_REQUIRED** | A PIN is required for the operation to complete. |
| **E_INVALIDARG** | The context ID or provider ID given in the request is not valid. |
| **E_MBN_BAD_SIM** | There is a bad SIM in the device. |
| **HRESULT_FROM_WIN32(ERROR_WRITE_FAULT)** | An update in either SIM or device memory failed. |

## Return value

This method must return **S_OK**.

## Remarks

A calling application can pass an [IMbnConnectionContext](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectioncontext) interface to *newInterface* to get the updated list of provisioned contexts in the device.
However, since this operation is asynchronous, the application must wait for the [OnProvisionedContextListChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnconnectioncontextevents-onprovisionedcontextlistchange) notification before using this interface to get the contexts.

If there are multiple applications registered to receive notifications then all of them will receive this notification even though only one of them could have initiated this operation.

## See also

[IMbnConnectionContextEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectioncontextevents)