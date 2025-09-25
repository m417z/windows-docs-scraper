# ID3D11DeviceContext2::EndEvent

## Description

Allows applications to annotate the end of a range of graphics commands.

## Remarks

**EndEvent** allows applications to annotate the end of a range of graphics commands, in order to provide more context to what the GPU is executing. When the appropriate [ETW](https://learn.microsoft.com/previous-versions/dotnet/netframework-3.0/ms751538(v=vs.85)) logging is not enabled, this method does nothing. When ETW logging is enabled, an additional marker is correlated between the CPU and GPU timelines.

## See also

[ID3D11DeviceContext2](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nn-d3d11_2-id3d11devicecontext2)