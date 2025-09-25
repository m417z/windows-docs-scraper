# IMbnInterfaceEvents::OnReadyStateChange

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

This notification method is called by the Mobile Broadband service to indicate a change in an interface's ready state.

## Parameters

### `newInterface` [in]

An [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface) that represents the Mobile Broadband device whose ready state has changed.

## Return value

This method must return **S_OK**.

## Remarks

An application can call the [GetReadyState](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterface-getreadystate) method of the passed [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface) to get latest ready state of the device. For a list of ready states, see [MBN_READY_STATE](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_ready_state).

## See also

[IMbnInterfaceEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfaceevents)