# WIA_DATA_TRANSFER_INFO structure

## Description

The **WIA_DATA_TRANSFER_INFO** structure is used by applications to describe the buffer used to retrieve bands of data from Windows Image Acquisition (WIA) devices. It is primarily used in conjunction with the methods of the [IWiaDataTransfer](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiadatatransfer) interface.

## Members

### `ulSize`

Type: **ULONG**

Contains the size of this structure. Must be set to **sizeof(WIA_DATA_TRANSFER_INFO)** before your application passes this structure to any WIA interface methods.

### `ulSection`

Type: **ULONG**

Specifies an optional handle to a shared section of memory allocated by the application. If this member is set to **NULL**, [IWiaDataTransfer::idtGetBandedData](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiadatatransfer-idtgetbandeddata) allocates the shared memory itself.

### `ulBufferSize`

Type: **ULONG**

The size in bytes of the buffer that is used for the data transfer.

### `bDoubleBuffer`

Type: **BOOL**

Contains **TRUE** if the device is double buffered, **FALSE** if the device is not double buffered.

### `ulReserved1`

Type: **ULONG**

Reserved for use by the WIA system DLLs. Must be set to zero.

### `ulReserved2`

Type: **ULONG**

Reserved for use by the WIA system DLLs. Must be set to zero.

### `ulReserved3`

Type: **ULONG**

Reserved for use by the WIA system DLLs. Must be set to zero.