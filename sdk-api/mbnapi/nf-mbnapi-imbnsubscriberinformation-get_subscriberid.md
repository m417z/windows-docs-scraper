# IMbnSubscriberInformation::get_SubscriberID

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The subscriber ID of the device.

This property is read-only.

## Parameters

## Remarks

This is a null terminated string of digits. For GSM device this represents the International Mobile Equipment Identity (IMSI) string (up to 15 digits). For CDMA device this represents the Mobile Identification Number (MIN) string or the International Roaming MIN (IRM) string (10 digits).

Normally, this value is available only when the ready state of the device is **MBN_READY_STATE_INITIALIZED** In some cases, it may be populated in other states such as **MBN_READY_STATE_DEVICE_LOCKED**, **MBN_READY_STATE_BAD_SIM**, and **MBN_READY_STATE_FAILURE**. When this information is not available it is returned as an empty string "".

## See also

[IMbnSubscriberInformation](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsubscriberinformation)