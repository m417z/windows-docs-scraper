# IMbnSignalEvents::OnSignalStateChange

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

This notification method is called by the Mobile Broadband service to indicate that a signal quality update is available.

## Parameters

### `newInterface` [in]

Pointer to an [IMbnSignal](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsignal) interface for which the signal quality update was received.

## Return value

This method must return **S_OK**.

## Remarks

**OnSignalStateChange** is called by the Mobile Broadband service to notify a calling application that a signal quality update is available. This includes an update of the signal notification period, threshold for signal notification, signal strength received, and error rate in the received signal.
An application can get updated values from the [IMbnSignal](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsignal) interface passed in this method.

## See also

[IMbnSignalEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsignalevents)