# IMbnSubscriberInformation::get_TelephoneNumbers

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The telephone numbers associated with the device.

This property is read-only.

## Parameters

## Remarks

This property provides the list of telephone numbers (TNs) assigned to the subscriber. In GSM the numbers are called Mobile Station ISDN Numbers (MSISDNs). In CDMA they are called Mobile Directory Numbers (MDNs).

This value is not populated until the ready state reaches **MBN_READY_STATE_INITIALIZED**.

## See also

[IMbnSubscriberInformation](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsubscriberinformation)