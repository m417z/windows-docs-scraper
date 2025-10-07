# D3DXSHGPUSIMOPT enumeration

Describes the resolution of the shadow z-buffer that will be used in Precomputed Radiance Transfer (PRT) direct lighting simulation on the GPU. A higher quality z-buffer can also be specified to reduce noise in the results of the direct lighting simulation, although the simulation will be slower.

## Constants

**D3DXSHGPUSIMOPT\_SHADOWRES256**

Low resolution simulation. A 256 x 256 pixel texture is used in the simulation to encode the shadow z-buffer.

**D3DXSHGPUSIMOPT\_SHADOWRES512**

Medium resolution simulation. A 512 x 512 pixel texture is used in the simulation to encode the shadow z-buffer. This is the default value.

**D3DXSHGPUSIMOPT\_SHADOWRES1024**

High resolution simulation. A 1024 x 1024 pixel texture is used in the simulation to encode the shadow z-buffer.

**D3DXSHGPUSIMOPT\_SHADOWRES2048**

Highest resolution simulation. A 2048 x 2048 pixel texture is used in the simulation to encode the shadow z-buffer.

**D3DXSHGPUSIMOPT\_HIGHQUALITY**

The simulation is of high precision, regardless of the selected resolution. Setting this value will reduce noise in the results of the direct lighting simulation, although the simulation will be slower. May be combined with one of the resolution values.

**D3DXSHGPUSIMOPT\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

Only one of the resolution values may be specified, and may be combined with the high-quality value.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9mesh.h |

## See also

[D3DX Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-enums)

