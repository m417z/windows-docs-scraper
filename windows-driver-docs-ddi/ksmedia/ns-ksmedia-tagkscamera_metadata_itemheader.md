# tagKSCAMERA_METADATA_ITEMHEADER structure

## Description

This structure contains the metadata header information that is filled by the camera driver.

## Members

### `MetadataId`

The identifier for the metadata item. This can be a standard identifier as defined in the [KSCAMERA_MetadataId](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-kscamera_metadataid) enumeration or any custom metadata identifier that starts from MetadataId_Custom_Start (0x80000000).

### `Size`

Set to **sizeof(KSCAMERA_METADATA_ITEMHEADER)** + the size of the metadata payload that follows.

## Remarks

This structure along with the metadata payload that follows must be 8-byte aligned.