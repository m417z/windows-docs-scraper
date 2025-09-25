# IWCNDevice::SetVendorExtension

## Description

The **IWCNDevice::SetVendorExtension** method queues a vendor extension for use in the pending session. This function may only be called prior to [IWCNDevice::Connect](https://learn.microsoft.com/windows/desktop/api/wcndevice/nf-wcndevice-iwcndevice-connect).

## Parameters

### `pVendorExtSpec` [in]

A pointer to a **WCN_VENDOR_EXTENSION_SPEC** structure that contains the vendor extension specification.

### `cbBuffer` [in]

The number of bytes contained in *pbBuffer*.

### `pbBuffer` [in]

Pointer to a buffer that contains the data to set in the vendor extension.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The vendor extension will be sent in the pending session. |
| **E_INVALIDARG** | The specified **WCN_VENDOR_EXTENSION_SPEC** contains an illegal VendorID, sub-type, or flag. |
| **HRESULT_FROM_WIN32(ERROR_IMPLEMENTATION_LIMIT)** | The number of vendor extensions has exceeded the current implementation limit, which is currently equal to 25 vendor extensions per session. |

## See also

[IWCNDevice](https://learn.microsoft.com/windows/desktop/api/wcndevice/nn-wcndevice-iwcndevice)

[IWCNDevice::Connect](https://learn.microsoft.com/windows/desktop/api/wcndevice/nf-wcndevice-iwcndevice-connect)

**WCN_VENDOR_EXTENSION_SPEC**