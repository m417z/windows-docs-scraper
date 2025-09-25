# WMP_WMDM_METADATA_ROUND_TRIP_PC2DEVICE structure

## Description

The **WMP_WMDM_METADATA_ROUND_TRIP_PC2DEVICE** structure is used by Windows Media Player to request accelerated metadata synchronization information from portable devices that do not support MTP.

## Members

### `dwChangesSinceTransactionID`

The transaction identifier supplied by the device during the previous session. This value is zero for the first session ever.

### `dwResultSetStartingIndex`

The index of the first value to retrieve. This value is always zero for the first call of a session.

## See also

[Windows Media Device Manager Device Extensions for Metadata Transfer](https://learn.microsoft.com/windows/desktop/WMP/windows-media-device-manager-device-extensions-for-metadata-transfer)