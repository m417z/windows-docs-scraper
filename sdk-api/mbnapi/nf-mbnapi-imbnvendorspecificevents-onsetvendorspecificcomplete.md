# IMbnVendorSpecificEvents::OnSetVendorSpecificComplete

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method indicating that a vendor-specific operation has completed.

## Parameters

### `vendorOperation` [in]

An [IMbnVendorSpecificOperation](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnvendorspecificoperation) interface representing the operation that completed.

### `vendorSpecificData` [in]

A byte array containing the data returned by underlying miniport driver.

### `requestID` [in]

A request ID assigned by the Mobile Broadband service to identify the vendor-specific operation request.

## Return value

This method must return **S_OK**.

## Remarks

This byte array contains the byte by byte copy of data returned by underlying miniport driver. The Mobile Broadband service will free the memory for this field after the function call returns. If an application wants to use this data then it should copy the contents in its own memory.

## See also

[IMbnVendorSpecificEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnvendorspecificevents)