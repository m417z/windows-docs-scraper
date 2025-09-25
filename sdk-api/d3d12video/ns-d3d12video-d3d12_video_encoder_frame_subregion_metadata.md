## Description

Represents video encoder frame subregion metadata.

## Members

### `bSize`

Output field that receives the sizes in bytes of each subregion. Subregions sizes must include both the subregion initial padding, the subregion header and the subregion payload.

### `bStartOffset`

Output field that receives the padding size in bytes that needs to be skipped at the beginning of every subregion. This padding size is included in the size reported above.

For example, let *pFrameSubregionsSizes* be an array of *bSize* for each slice. With this information, along with *pFrameSubregionsSizes*, the user can extract individual subregions from the output bitstream buffer by calculating i-th subregion start offset as `pBuffer + FrameStartOffset + sum j = (0, (i-1)){ pFrameSubregionsSizes[j] } + pFrameSubregionsStartOffsets[i]` and reading `pFrameSubregionsSizes[i]` bytes.

### `bHeaderSize`

Output parameter that receives the sizes in bits of each subregion header.
With this information, in addition to extracting the full subregion from the bitstream as explained above, the user can extract the subregions payload/headers directly without needing to parse the full subregion bitstream.

## Remarks

## See also