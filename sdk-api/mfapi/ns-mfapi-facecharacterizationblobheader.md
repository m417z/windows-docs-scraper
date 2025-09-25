# FaceCharacterizationBlobHeader structure

## Description

The **FaceCharacterizationBlobHeader** structure describes the size and count information of the blob format for the **MF_CAPTURE_METADATA_FACEROICHARACTERIZATIONS** attribute.

## Members

### `Size`

Size of this header + all following [FaceCharacterization](https://learn.microsoft.com/windows/desktop/api/mfapi/ns-mfapi-facecharacterization) structures.

### `Count`

Number of **FaceCharacterization** structures in the blob. Must match the number of [FaceRectInfo](https://learn.microsoft.com/windows/desktop/api/mfapi/ns-mfapi-facerectinfo) structures in [FaceRectInfoBlobHeader](https://learn.microsoft.com/windows/desktop/api/mfapi/ns-mfapi-facerectinfoblobheader).