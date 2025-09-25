# ID3D10Multithread::Leave

## Description

Leave a device's critical section.

## Remarks

This function is typically used in multithreaded applications when there is a series of graphics commands that must happen in order. [ID3D10Multithread::Enter](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10multithread-enter) is typically called at the beginning of a series of graphics commands, and this function is typically called after those graphics commands.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)

[ID3D10Multithread](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10multithread)