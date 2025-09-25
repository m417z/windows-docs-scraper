# ID3D11DeviceContext2::BeginEventInt

## Description

Allows applications to annotate the beginning of a range of graphics commands.

## Parameters

### `pLabel` [in]

An optional string that will be logged to [ETW](https://learn.microsoft.com/previous-versions/dotnet/netframework-3.0/ms751538(v=vs.85)) when ETW logging is active. If **‘#d’** appears in the string, it will be replaced by the value of the *Data* parameter similar to the way **printf** works.

### `Data`

A signed data value that will be logged to ETW when ETW logging is active.

## Remarks

**BeginEventInt** allows applications to annotate the beginning of a range of graphics commands, in order to provide more context to what the GPU is executing. When [ETW](https://learn.microsoft.com/previous-versions/dotnet/netframework-3.0/ms751538(v=vs.85)) logging (or a supported tool) is enabled, an additional marker is correlated between the CPU and GPU timelines. The *pLabel* and *Data* value are logged to ETW. When the appropriate ETW logging is not enabled, this method does nothing.

## See also

[ID3D11DeviceContext2](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nn-d3d11_2-id3d11devicecontext2)