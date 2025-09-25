# tagKSCAMERA_METADATA_PHOTOCONFIRMATION structure

## Description

This structure contains the photo confirmation metadata information that is filled by the camera driver.

## Members

### `Header`

A [KSCAMERA_METADATA_ITEMHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagkscamera_metadata_itemheader) structure that contains the metadata header information that is filled by the camera driver.

### `PhotoConfirmationIndex`

Stores the index of the still confirmation frame. For single photo capture, this is always 0. For multishot, this corresponds to the index of the photo frame captured.

### `Reserved`

Reserved for future use.