# FaceRectInfoBlobHeader structure

## Description

The **FaceRectInfoBlobHeader** structure describes the size and count information of the blob format for the **MF_CAPTURE_METADATA_FACEROIS** attribute.

## Members

### `Size`

Size of this header + all following [FaceRectInfo](https://learn.microsoft.com/windows/desktop/api/mfapi/ns-mfapi-facerectinfo) structures.

### `Count`

Number of **FaceRectInfo** structures in the blob.