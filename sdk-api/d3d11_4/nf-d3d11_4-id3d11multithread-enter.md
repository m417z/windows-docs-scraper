# ID3D11Multithread::Enter

## Description

Enter a device's critical section.

## Remarks

If [SetMultithreadProtected](https://learn.microsoft.com/windows/desktop/api/d3d11_4/nf-d3d11_4-id3d11multithread-setmultithreadprotected) is set to true, then entering a device's critical section prevents other threads from simultaneously calling that device's methods, calling DXGI methods, and calling the methods of all resource, view, shader, state, and asynchronous interfaces.

This function should be used in multithreaded applications when there is a series of graphics commands that must happen in order. This function is typically called at the beginning of the series of graphics commands, and [Leave](https://learn.microsoft.com/windows/desktop/api/d3d11_4/nf-d3d11_4-id3d11multithread-leave) is typically called after those graphics commands.

## See also

[ID3D11Multithread](https://learn.microsoft.com/windows/desktop/api/d3d11_4/nn-d3d11_4-id3d11multithread)