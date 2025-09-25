## Description

The **DXVA_Status_AV1** structure is sent by the accelerator to the host software decoder to convey decoding status information.

## Members

### `StatusReportFeedbackNumber`

Contains the value of **StatusReportFeedbackNumber** set by the host software decoder in the [**DXVA_PicParams_AV1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-dxva_picparams_av1) structure for the associated operation.

### `CurrPic`

The uncompressed destination surface that was affected by the operation.

### `BufType`

The type of compressed buffer associated with this status report. If **Status** is 0, **bBufType** may be 0xFF, which indicates that the status report applies to all of the compressed buffers conveyed in the associated Execute call. Otherwise, if **bBufType** is not 0xFF, it must contain one of the following values, defined in *dxva.h*:

| Value | Description |
| ----- | ----------- |
| DXVA_PICTURE_DECODE_BUFFER (1) | Picture decoding parameter buffer. |
| DXVA_SLICE_CONTROL_BUFFER (6) | Slice control buffer. |
| DXVA_BITSTREAM_DATA_BUFFER (7) | Bitstream data buffer. |

### `Status`

The status of the operation. **Status** can be one of the following values:

| Value | Description |
| ----- | ----------- |
| 0 | The operation succeeded. |
| 1 | Minor problem in the data format. The host decoder should continue processing. |
| 2 | Significant problem in the data format. The host decoder may continue executing or skip the display of the output picture. |
| 3 | Severe problem in the data format. The host decoder should restart the entire decoding process, starting at a sequence or random-access entry point. |
| 4 | Other severe problem. The host decoder should restart the entire decoding process, starting at a sequence or random-access entry point. |

If the value is 3 or 4, the host software decoder should halt the decoding process unless it can take corrective action.

### `Reserved8Bits`

Reserved; set to 0. The accelerator ignores this field.

### `NumMbsAffected`

If **Status** is not 0, this member contains the accelerator's estimate of the number of super-blocks in the decoded frame that were adversely affected by the reported problem. If the accelerator does not provide an estimate, the value is 0xFFFF.

If **Status** is 0, the accelerator may set **NumMbsAffected** to the number of super-blocks that were successfully decoded by the operation. If the accelerator does not provide an estimate, it shall set the value either to 0 or to 0xFFFF.

## Remarks

See the [Direct X Video Acceleration Specification for AV1 Video Coding](https://www.microsoft.com/download/details.aspx?id=101577) for detailed information, including how to use this structure.