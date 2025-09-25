## Description

Allows you to transition logically-adjacent ranges of subresources.

## Members

### `IndexOrFirstMipLevel`

The index of the first mip level in the range; or a subresource index, if *NumMipLevels* is zero. If a subresource index, then you can use the value `0xffffffff` to specify all subresources.

### `NumMipLevels`

Number of mip levels in the range, or zero to indicate that *IndexOrFirstMipLevel* is a subresource index.

### `FirstArraySlice`

Index of first array slice in the range. Ignored if *NumMipLevels* is zero.

### `NumArraySlices`

Number of array slices in the range. Ignored if *NumMipLevels* is zero.

### `FirstPlane`

First plane slice in the range. Ignored if *NumMipLevels* is zero.

### `NumPlanes`

Number of plane slices in the range. Ignored if *NumMipLevels* is zero.

## Remarks

## See also