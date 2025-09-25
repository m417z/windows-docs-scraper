# IMbnVendorSpecificOperation::SetVendorSpecific

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Sends a request to the underlying Mobile Broadband device miniport driver.

## Parameters

### `vendorSpecificData` [in]

A byte array that is passed in to the miniport driver.

### `requestID` [out]

A unique request ID assigned by the Mobile Broadband service to identify this request.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**SetVendorSpecific** exists to implement vendor-specific functionality which is not otherwise covered in the Mobile Broadband API.

The Mobile Broadband service will issue a SET OID request to the underlying miniport driver for OID_WWAN_VENDOR_SPECIFIC OID. *VendorspecificData* will be copied byte by byte into the data buffer passed in the OID request.

This is an asynchronous operation and **SetVendorSpecific** will return immediately. On completion of the operation, the Mobile Broadband service will call the [OnSetVendorSpecificComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnvendorspecificevents-onsetvendorspecificcomplete) method of the [IMbnVendorSpecificEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnvendorspecificevents) interface.

Refer to the Mobile Broadband Driver Model for more information about vendor specific operations.

## See also

[IMbnVendorSpecificOperation](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnvendorspecificoperation)