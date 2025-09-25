# IWCNDevice::GetVendorExtension

## Description

The **GetVendorExtension** method gets a cached vendor extension from the device.

## Parameters

### `pVendorExtSpec` [in]

A pointer to a user-defined **WCN_VENDOR_EXTENSION_SPEC** structure that describes the vendor extension to query for.

### `dwMaxBufferSize` [in]

The size, in bytes, of *pbBuffer*.

### `pbBuffer` [out]

An allocated buffer that, on return, contains the contents of the vendor extension.

### `pdwBufferUsed` [out]

On return, contains the size of the vendor extension in bytes.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The vendor extension was retrieved successfully. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The vendor extension specified is not available. |
| **HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)** | The buffer specified by *pbBuffer* is not large enough to contain the returned vendor extension. |

## Remarks

 To query the size of a vendor extension, you can pass a value of 0 with the *dwMaxBufferSize* parameter, and *pdwBufferUsed* will receive the size.

## See also

[IWCNDevice](https://learn.microsoft.com/windows/desktop/api/wcndevice/nn-wcndevice-iwcndevice)