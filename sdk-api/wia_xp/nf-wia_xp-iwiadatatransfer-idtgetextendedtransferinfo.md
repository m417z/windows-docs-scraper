# IWiaDataTransfer::idtGetExtendedTransferInfo

## Description

The **IWiaDataTransfer::idtGetExtendedTransferInfo** retrieves extended information relating to data transfer buffers in the case of banded data transfers. Applications typically use this method to retrieve driver recommended settings for minimum buffer size, maximum buffer size, and optimal buffer size for banded data transfers.

## Parameters

### `pExtendedTransferInfo` [out]

Type: **PWIA_EXTENDED_TRANSFER_INFO**

Pointer to a [WIA_EXTENDED_TRANSFER_INFO](https://learn.microsoft.com/windows/desktop/api/wia_xp/ns-wia_xp-wia_extended_transfer_info) structure containing the extended information.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.