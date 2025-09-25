# ID3D10Multithread::Enter

## Description

Enter a device's critical section.

## Remarks

Entering a device's critical section prevents other threads from simultaneously calling that device's methods (if [multithread protection](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10multithread-setmultithreadprotected) is set to true), calling DXGI methods, and calling the methods of all resource, view, shader, state, and asynchronous interfaces.

This function should be used in multithreaded applications when there is a series of graphics commands that must happen in order. This function is typically called at the beginning of the series of graphics commands, and [ID3D10Multithread::Leave](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10multithread-leave) is typically called after those graphics commands.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)

[ID3D10Multithread](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10multithread)