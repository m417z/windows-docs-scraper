# D3D12DDI_VIDEO_DECODE_BITSTREAM_ENCRYPTION_SCHEME_COUNT_DATA_0032 structure

## Description

Structure used to retrieve the number of encryption schemes supported for a given decode profile.

## Members

### `NodeIndex`

In multi-adapter operation, this indicates which physical adapter of the device this operation applies to.

### `DecodeProfile`

The decode profile GUID to retrieve the count of supported encryption guids.

### `BitstreamEncryptionSchemeCount`

Driver returns the number of supported bitstream encryption schemes.