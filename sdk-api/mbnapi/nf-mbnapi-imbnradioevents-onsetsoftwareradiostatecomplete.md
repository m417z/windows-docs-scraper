# IMbnRadioEvents::OnSetSoftwareRadioStateComplete

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification that a set software radio state operation has completed.

## Parameters

### `newInterface` [in]

Pointer to an [IMbnRadio](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnradio) interface representing the device for which a set radio state operation has completed.

### `requestID` [in]

The request ID set by the Mobile Broadband service to identify the request.

### `status` [in]

A status code that indicates the outcome of the set radio state operation.

A calling application can expect one of the following values.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |

## Return value

This method must return **S_OK**.

## See also

[IMbnRadioEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnradioevents)