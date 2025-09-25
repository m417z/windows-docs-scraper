# _AVCSTRM_OPEN_STRUCT structure

## Description

The AVCSTRM_OPEN_STRUCT structure describes a data stream to be opened.

## Members

### `DataFlow`

Specifies the direction of the data-flow.

### `AVCFormatInfo`

Pointer to a description of the subunit stream format.

### `AVCStreamContext`

Pointer to a stream context (handle) that is passed to subsequent *avcstrm.sys* operations. Its content should not be used or altered.

### `hPlugLocal`

Specifies a local plug created by an AV/C subunit, which is used to connect to the target device.

## Remarks

The **AVCSTRM_OPEN** function code uses this structure to describe the open operation. If the operation is successful, a stream context (handle) is returned to the caller in the **AVCStrmContext** member of this structure, *not* the **AVCStrmContext** member in the AVC_STREAM_REQUEST_BLOCK structure.

This value can then be used in subsequent *avcstrm.sys* operations by placing it in the **AVCStrmContext** member of the AVC_STREAM_REQUEST_BLOCK structure.

## See also

[AVCSTRM_FORMAT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ns-avcstrm-_avcstrm_format_info)

[AVCSTRM_OPEN](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-open)