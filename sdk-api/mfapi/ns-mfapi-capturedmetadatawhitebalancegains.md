# CapturedMetadataWhiteBalanceGains structure

## Description

This structure describes the blob format for the **MF_CAPTURE_METADATA_WHITEBALANCE_GAINS** attribute.

## Members

### `R`

The **R** value of the blob.

### `G`

The **G** value of the blob.

### `B`

The **B** value of the blob.

## Remarks

The **MF_CAPTURE_METADATA_WHITEBALANCE_GAINS** attribute contains the white balance gains applied to R, G, B by the sensor or ISP when the preview frame was captured. This is a unitless.

The **CapturedMetadataWhiteBalanceGains** structure only describes the blob format for the **MF_CAPTURE_METADATA_WHITEBALANCE_GAINS** attribute. The metadata item structure for white balance gains ([KSCAMERA_METADATA_ITEMHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-tagkscamera_metadata_itemheader) + white balance gains metadata payload) is up to driver and must be 8-byte aligned.