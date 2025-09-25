# IMbnSubscriberInformation::get_SimIccID

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The SIM International circuit card number (SimICCID) for the device.

This property is read-only.

## Parameters

## Remarks

The International Circuit Card Id of the SIM varies between 15 to 20 digits in length and is represented in characters. This value is available only when the ready state of the device is **MBN_READY_STATE_INITIALIZED**. In some cases, it may also be populated in states such as **MBN_READY_STATE_DEVICE_LOCKED**, **MBN_READY_STATE_BAD_SIM**, and **MBN_READY_STATE_FAILURE**. When this information is not available it is returned as an empty string.

## See also

[IMbnSubscriberInformation](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsubscriberinformation)