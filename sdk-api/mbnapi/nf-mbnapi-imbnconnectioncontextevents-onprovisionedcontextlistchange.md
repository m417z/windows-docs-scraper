# IMbnConnectionContextEvents::OnProvisionedContextListChange

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method called by the Mobile Broadband service to indicate that a provisioned context stored in the device is available or updated.

## Parameters

### `newInterface` [in]

An [IMbnConnectionContext](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectioncontext) interface that represents the device for which the context is available or updated.

## Return value

This method must return **S_OK**.

## Remarks

An application can use the passed [IMbnConnectionContext](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectioncontext) interface to get the list of provisioned contexts for the device.

**OnProvisionedContextListChange** is not called as the result of an update to an existing provisioned context from an application call of the [SetProvisionedContext](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnconnectioncontext-setprovisionedcontext) method of [IMbnConnectionContext](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectioncontext).

## See also

[IMbnConnectionContextEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectioncontextevents)