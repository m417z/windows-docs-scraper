# IMAPI_READ_TRACK_ADDRESS_TYPE enumeration

## Description

Defines values that indicate how to interpret track addresses for the current disc profile of a randomly-writable, hardware-defect-managed media type.

## Constants

### `IMAPI_READ_TRACK_ADDRESS_TYPE_LBA:0`

Interpret the address field as an LBA (sector address). The returned data should reflect the information for the track which contains the specified LBA.

### `IMAPI_READ_TRACK_ADDRESS_TYPE_TRACK:1`

Interpret the address field as a track number. The returned data should reflect the information for the specified track. This version of the command has the greatest compatibility with legacy devices.

### `IMAPI_READ_TRACK_ADDRESS_TYPE_SESSION:2`

Interpret the address field as a session number. The returned data should reflect the information for the first track which exists in the specified session. Note that not all drives support this method.