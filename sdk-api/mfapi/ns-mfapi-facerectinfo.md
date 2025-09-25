## Description

The **FaceRectInfo** structure describes the blob format for the **MF_CAPTURE_METADATA_FACEROIS** attribute.

## Members

### `Region`

Relative coordinates on the frame that face detection is running (Q31 format).

### `confidenceLevel`

Confidence level of the region being a face (0 - 100).

## Remarks

The **MF_CAPTURE_METADATA_FACEROIS** attribute contains the face rectangle info detected by the driver. By default driver\MFT0 should provide the face information on preview stream. If the driver advertises the capability on other streams, driver\MFT must provide the face info on the corresponding streams if the application enables face detection on those streams. When video stabilization is enabled on the driver, the face information should be provided post-video stabilization. The dominate face must be the first **FaceRectInfo** in the blob.

The [FaceRectInfoBlobHeader](https://learn.microsoft.com/windows/desktop/api/mfapi/ns-mfapi-facerectinfoblobheader) and **FaceRectInfo** structures only describe the blob format for the **MF_CAPTURE_METADATA_FACEROIS** attribute. The metadata item structure for face ROIs ([KSCAMERA_METADATA_ITEMHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-tagkscamera_metadata_itemheader) + face ROIs metadata payload) is up to driver and must be 8-byte aligned.