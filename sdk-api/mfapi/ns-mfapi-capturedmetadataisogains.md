# CapturedMetadataISOGains structure

## Description

The CapturedMetadataISOGains structure describes the blob format for **MF_CAPTURE_METADATA_ISO_GAINS**.

## Members

### `AnalogGain`

### `DigitalGain`

## Remarks

The **CapturedMetadataISOGains** structure only describes the blob format for the **MF_CAPTURE_METADATA_ISO_GAINS** attribute. The metadata item structure for ISO gains ([KSCAMERA_METADATA_ITEMHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-tagkscamera_metadata_itemheader) + ISO gains metadata payload) is up to driver and must be 8-byte aligned.