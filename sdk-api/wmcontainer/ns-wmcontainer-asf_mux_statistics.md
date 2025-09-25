# ASF_MUX_STATISTICS structure

## Description

Contains statistics about the progress of the ASF multiplexer.

## Members

### `cFramesWritten`

Number of frames written by the ASF multiplexer.

### `cFramesDropped`

Number of frames dropped by the ASF multiplexer.

## Remarks

Use [IMFASFMultiplexer::GetStatistics](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfmultiplexer-getstatistics) to retrieve this structure.

## See also

[IMFASFMultiplexer::GetStatistics](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfmultiplexer-getstatistics)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)