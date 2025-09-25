# D3D11_CLASS_INSTANCE_DESC structure

## Description

Describes an HLSL class instance.

## Members

### `InstanceId`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The instance ID of an HLSL class; the default value is 0.

### `InstanceIndex`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The instance index of an HLSL class; the default value is 0.

### `TypeId`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The type ID of an HLSL class; the default value is 0.

### `ConstantBuffer`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Describes the constant buffer associated with an HLSL class; the default value is 0.

### `BaseConstantBufferOffset`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The base constant buffer offset associated with an HLSL class; the default value is 0.

### `BaseTexture`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The base texture associated with an HLSL class; the default value is 127.

### `BaseSampler`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The base sampler associated with an HLSL class; the default value is 15.

### `Created`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

True if the class was created; the default value is false.

## Remarks

The D3D11_CLASS_INSTANCE_DESC structure is returned by the [ID3D11ClassInstance::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11classinstance-getdesc) method.

The members of this structure except **InstanceIndex** are valid (non default values) if they describe a class instance acquired using [ID3D11ClassLinkage::CreateClassInstance](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11classlinkage-createclassinstance). The **InstanceIndex** member is only valid when the class instance is aquired using [ID3D11ClassLinkage::GetClassInstance](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11classlinkage-getclassinstance).

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-shader-structures)