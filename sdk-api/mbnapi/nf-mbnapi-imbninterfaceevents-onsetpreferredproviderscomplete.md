# IMbnInterfaceEvents::OnSetPreferredProvidersComplete

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

This notification method is called by the Mobile Broadband service to indicate the completion of a [SetPreferredProviders](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterface-setpreferredproviders) operation.

## Parameters

### `newInterface` [in]

An [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface) that represents a device on which this operation was performed.

### `requestID` [in]

The request ID assigned by the Mobile Broadband service for this asynchronous operation.

### `status` [in]

The operation completion status.

The following table lists the valid values for this status.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_MBN_PIN_REQUIRED** | The device requires a PIN to be entered for this operation to complete. |
| **E_MBN_SIM_NOT_INSERTED** | The SIM is not inserted. |
| **E_MBN_BAD_SIM** | A bad SIM is inserted in the device. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The device does not support this operation. |

## Return value

This method must return **S_OK**.

## Remarks

If the operation completed successfully, that is, when *status* is **S_OK**, then the application can call the [GetPreferredProviders](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterface-getpreferredproviders) method of the passed [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface) to get an updated list of preferred providers.

If multiple applications registered for notifications, then this method will be called on all registered applications. This means that an application that did not initiate the update operation will also receive a notification.

If a call to the [SetPreferredProviders](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterface-setpreferredproviders) method of [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface) results in a change in the preferred provider list, then the [OnPreferredProvidersChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterfaceevents-onpreferredproviderschange) method of [IMbnInterfaceEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfaceevents) will not be called.

## See also

[IMbnInterfaceEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfaceevents)