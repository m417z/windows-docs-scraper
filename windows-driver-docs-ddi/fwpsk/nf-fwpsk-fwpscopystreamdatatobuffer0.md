# FwpsCopyStreamDataToBuffer0 function

## Description

The
**FwpsCopyStreamDataToBuffer0** function copies stream data to a buffer.

**Note** **FwpsCopyStreamDataToBuffer0** is a specific version of **FwpsCopyStreamDataToBuffer**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `calloutStreamData` [in]

A pointer to a
[FWPS_STREAM_DATA0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_stream_data0_) structure that contains
the stream data to be copied.

### `buffer` [in, out]

A pointer to a location in memory that will store the copy of the stream data pointed to by the
*calloutStreamData* parameter. The size of the buffer must be greater than or equal to
*bytesToCopy*.

### `bytesToCopy` [in]

The amount of data, in bytes, to be copied into the receiving buffer.

### `bytesCopied` [out]

A pointer to a variable that receives the size, in bytes, of the stream data copied to the memory
location pointed to by the
*buffer* parameter.

## Remarks

To copy all indicated data to the receiving buffer, ensure that the buffer is at least
*calloutStreamData* ->
**DataLength** in size.

## See also

[FWPS_STREAM_DATA0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_stream_data0_)