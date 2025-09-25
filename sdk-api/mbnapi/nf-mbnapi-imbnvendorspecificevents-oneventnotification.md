# IMbnVendorSpecificEvents::OnEventNotification

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method signaling a change event from the underlying Mobile Broadband device miniport driver.

## Parameters

### `vendorOperation` [in]

A [IMbnVendorSpecificOperation](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnvendorspecificoperation) interface representing the device on which the event has occurred.

### `vendorSpecificData` [in]

A byte array containing the data returned by underlying miniport driver.

## Return value

This method must return **S_OK**.

## Remarks

This byte array contains the byte by byte copy of data returned by underlying miniport driver. The Mobile Broadband service will free the memory for this field after the function call returns. If an application wants to use this data then it should copy the contents in its own memory.

## See also

[IMbnVendorSpecificEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnvendorspecificevents)