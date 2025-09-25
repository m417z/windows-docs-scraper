# FaceCharacterization structure

## Description

The **FaceCharacterization** structure describes the blob format for the **MF_CAPTURE_METADATA_FACEROICHARACTERIZATIONS** attribute.

## Members

### `BlinkScoreLeft`

0 indicates no blink for the left eye, 100 indicates definite blink for the left eye (0 - 100).

### `BlinkScoreRight`

0 indicates no blink for the right eye, 100 indicates definite blink for the right eye (0 - 100).

### `FacialExpression`

A defined facial expression value.

### `FacialExpressionScore`

0 indicates no such facial expression as identified, 100 indicates definite such facial expression as defined (0 - 100).

## Remarks

The **MF_CAPTURE_METADATA_FACEROICHARACTERIZATIONS** attribute contains the blink and facial expression state for the face ROIs identified in **MF_CAPTURE_METADATA_FACEROIS**. For a device that does not support blink or facial expression detection, this attribute should be omitted.

The facial expressions that can be detected are defined as follows:

```
#define MF_METADATAFACIALEXPRESSION_SMILE             0x00000001
```

The [FaceCharacterizationBlobHeader](https://learn.microsoft.com/windows/desktop/api/mfapi/ns-mfapi-facecharacterizationblobheader) and **FaceCharacterization** structures only describe the blob format for the **MF_CAPTURE_METADATA_FACEROICHARACTERIZATIONS** attribute. The metadata item structure for the face characterizations ([KSCAMERA_METADATA_ITEMHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-tagkscamera_metadata_itemheader) + face characterizations metadata payload) is up to driver and must be 8-byte aligned.