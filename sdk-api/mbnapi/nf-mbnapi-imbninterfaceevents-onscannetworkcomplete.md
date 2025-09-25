# IMbnInterfaceEvents::OnScanNetworkComplete

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

This notification method is called by the Mobile Broadband service to indicate the completion of a network scan.

## Parameters

### `newInterface` [in]

An [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface) that represents a device on which this operation was performed.

### `requestID` [in]

The request ID assigned by the Mobile Broadband service for this notification.

### `status` [in]

The operation completion status

A calling application can expect one of the following values.

**S_OK**

The operation was successful.

**E_MBN_RADIO_POWER_OFF**

Can't get a visible network list because the device radio is off. The application can issue a network scan request when it gets the radio-turned-on notification.

**E_MBN_DEVICE_BUSY**

The device is busy and can't currently perform a network scan operation. This is returned by devices which don't support a network scan operation when it has a data connection established.

**E_MBN_ALREADY_ACTIVE**

A network scan operation is already in progress.

## Return value

This method must return **S_OK**.

## Remarks

If the operation completed successfully, that is, when *status* is S_OK, the Mobile Broadband service successfully updated the cached list of visible providers. An application can then call the [GetVisibleProviders](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterface-getvisibleproviders) method of the passed [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface) to get the list of visible providers.

If multiple applications registered for notifications, then this method will be called on all registered applications. This means that an application that did not initiate the update operation will receive a notification.

## See also

[IMbnInterfaceEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfaceevents)