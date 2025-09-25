# IMbnSmsEvents::OnSmsConfigurationChange

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method that indicates that SMS configuration has changed or is available.

## Parameters

### `sms` [in]

A pointer to an [IMbnSms](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsms) interface representing the Mobile Broadband device for which the SMS configuration is now available.

## Return value

This method must return **S_OK**.

## Remarks

An application can use the [IMbnSms](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsms) to get the new configuration details.

## See also

[IMbnSmsEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsevents)