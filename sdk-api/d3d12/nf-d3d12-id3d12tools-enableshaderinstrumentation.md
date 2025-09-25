# ID3D12Tools::EnableShaderInstrumentation

## Description

This method enables tools such as PIX to instrument shaders.

## Parameters

### `bEnable`

Type: **BOOL**

TRUE to enable shader instrumentation; otherwise, FALSE.

## Remarks

Do not use this interface in your application, it's not intended or supported for any scenario other than to enable tooling such as PIX.

Developer Mode must be enabled for this interface to respond.

## See also

[ID3D12Tools](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12tools)