# MetadataTimeStamps structure

## Description

The **MetadataTimeStamps** structure describes the blob format for the **MF_CAPTURE_METADATA_FACEROITIMESTAMPS** attribute.

## Members

### `Flags`

Bitwise OR of the **MF_METADATATIMESTAMPS_*** flags.

### `Device`

QPC time for the sample the face rectangle is derived from (in 100ns).

### `Presentation`

PTS for the sample the face rectangle is derived from (in 100ns).

## Remarks

The **MF_CAPTURE_METADATA_FACEROITIMESTAMPS** attribute contains the time stamp information for the face ROIs identified in **MF_CAPTURE_METADATA_FACEROIS**. For a device that cannot provide the time stamp for face ROIs, this attribute should be omitted.

For the **Flags** field, the following bit flags indicate which time stamp is valid:

```
#define MF_METADATATIMESTAMPS_DEVICE        0x00000001
#define MF_METADATATIMESTAMPS_PRESENTATION  0x00000002
```

MFT0 must set **Flags** to **MF_METADATATIEMSTAMPS_DEVICE** and the appropriate QPC time for **Device**, if the driver provides the timestamp metadata for the face ROIs.

The **MetadataTimeStamps** structure only describes the blob format for the **MF_CAPTURE_METADATA_FACEROITIMESTAMPS** attribute. The metadata item structure for timestamp ([KSCAMERA_METADATA_ITEMHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-tagkscamera_metadata_itemheader) + timestamp metadata payload) is up to driver and must be 8-byte aligned.