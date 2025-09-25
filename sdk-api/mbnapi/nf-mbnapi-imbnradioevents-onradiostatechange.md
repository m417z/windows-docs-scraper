# IMbnRadioEvents::OnRadioStateChange

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

A notification signaling that the radio state of the device has changed.

## Parameters

### `newInterface` [in]

Pointer to an [IMbnRadio](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnradio) interface representing the device for which the radio state has changed.

## Return value

This method must return **S_OK**.

## Remarks

New software and hardware radio states can be obtained from the passed *newInterface* object.

## See also

[IMbnRadioEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnradioevents)