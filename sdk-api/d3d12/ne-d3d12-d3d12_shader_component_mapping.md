## Description

Specifies how memory gets routed by a shader resource view (SRV).

## Constants

### `D3D12_SHADER_COMPONENT_MAPPING_FROM_MEMORY_COMPONENT_0:0`

Indicates return component 0 (red).

### `D3D12_SHADER_COMPONENT_MAPPING_FROM_MEMORY_COMPONENT_1:1`

Indicates return component 1 (green).

### `D3D12_SHADER_COMPONENT_MAPPING_FROM_MEMORY_COMPONENT_2:2`

Indicates return component 2 (blue).

### `D3D12_SHADER_COMPONENT_MAPPING_FROM_MEMORY_COMPONENT_3:3`

Indicates return component 3 (alpha).

### `D3D12_SHADER_COMPONENT_MAPPING_FORCE_VALUE_0:4`

Indicates forcing the resulting value to 0.

### `D3D12_SHADER_COMPONENT_MAPPING_FORCE_VALUE_1:5`

Indicates forcing the resulting value 1. The value of forcing 1 is either 0x1 or 1.0f depending on the format type for that component in the source format.

## Remarks

This enum allows the SRV to select how memory gets routed to the four return components in a shader after a memory fetch. The options for each shader component [0..3] (corresponding to RGBA) are: component 0..3 from the SRV fetch result or force 0 or force 1.

The default 1:1 mapping can be indicated by specifying **D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING**, otherwise an arbitrary mapping can be specified using the macro **D3D12_ENCODE_SHADER_4_COMPONENT_MAPPING**.

See below.

Note the following defines.

```cpp
#define D3D12_SHADER_COMPONENT_MAPPING_MASK 0x7
#define D3D12_SHADER_COMPONENT_MAPPING_SHIFT 3
#define D3D12_SHADER_COMPONENT_MAPPING_ALWAYS_SET_BIT_AVOIDING_ZEROMEM_MISTAKES \
    (1<<(D3D12_SHADER_COMPONENT_MAPPING_SHIFT*4))
#define D3D12_ENCODE_SHADER_4_COMPONENT_MAPPING(Src0,Src1,Src2,Src3) \
    ((((Src0)&D3D12_SHADER_COMPONENT_MAPPING_MASK)| \
    (((Src1)&D3D12_SHADER_COMPONENT_MAPPING_MASK)<<D3D12_SHADER_COMPONENT_MAPPING_SHIFT)| \
    (((Src2)&D3D12_SHADER_COMPONENT_MAPPING_MASK)<<(D3D12_SHADER_COMPONENT_MAPPING_SHIFT*2))| \
    (((Src3)&D3D12_SHADER_COMPONENT_MAPPING_MASK)<<(D3D12_SHADER_COMPONENT_MAPPING_SHIFT*3))| \
    D3D12_SHADER_COMPONENT_MAPPING_ALWAYS_SET_BIT_AVOIDING_ZEROMEM_MISTAKES))
#define D3D12_DECODE_SHADER_4_COMPONENT_MAPPING(ComponentToExtract,Mapping) \
    ((D3D12_SHADER_COMPONENT_MAPPING)(Mapping >> (D3D12_SHADER_COMPONENT_MAPPING_SHIFT*ComponentToExtract) & D3D12_SHADER_COMPONENT_MAPPING_MASK))
#define D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING D3D12_ENCODE_SHADER_4_COMPONENT_MAPPING(0,1,2,3)
```

## See also

[Core enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)