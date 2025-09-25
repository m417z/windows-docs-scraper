# ID3D11Multithread::Leave

## Description

Leave a device's critical section.

## Remarks

This function is typically used in multithreaded applications when there is a series of graphics commands
that must happen in order. [Enter](https://learn.microsoft.com/windows/desktop/api/d3d11_4/nf-d3d11_4-id3d11multithread-enter) is typically called at the beginning of a series of graphics commands, and this function is typically
called after those graphics commands.

## See also

[ID3D11Multithread](https://learn.microsoft.com/windows/desktop/api/d3d11_4/nn-d3d11_4-id3d11multithread)