# WIA_EXTENDED_TRANSFER_INFO structure

## Description

The **WIA_EXTENDED_TRANSFER_INFO** structure specifies extended transfer information for the [IWiaDataTransfer::idtGetExtendedTransferInfo](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiadatatransfer-idtgetextendedtransferinfo) method.

## Members

### `ulSize`

Type: **ULONG**

Size of this structure.

### `ulMinBufferSize`

Type: **ULONG**

Minimum buffer size the application should request in a call to [IWiaDataTransfer::idtGetBandedData](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiadatatransfer-idtgetbandeddata).

### `ulOptimalBufferSize`

Type: **ULONG**

Driver-recommended buffer size the application should request in a call to [IWiaDataTransfer::idtGetBandedData](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiadatatransfer-idtgetbandeddata).

### `ulMaxBufferSize`

Type: **ULONG**

Driver-recommended maximum buffer size the application could request in a call to [IWiaDataTransfer::idtGetBandedData](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiadatatransfer-idtgetbandeddata). Going over this limit is not detrimental, however, the driver can simply not use the whole buffer and limit each band of data to this maximum size.

### `ulNumBuffers`

Type: **ULONG**

This value is not used and should be ignored.