# XFILECOMPRESSEDANIMATIONSET structure

Identifies compressed key frame animation data.

## Members

**CompressedBlockSize**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Total size, in bytes, of the compressed data in the compressed key frame animation data buffer.

**TicksPerSec**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of animation key frame ticks that occur per second.

**PlaybackType**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Type of the animation set playback loop. See [**D3DXPLAYBACK\_TYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxplayback-type).

**BufferLength**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Minimum buffer size, in bytes, required to hold compressed key frame animation data. Value is equal to ( ( CompressedBlockSize + 3 ) / 4 ).

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9mesh.h |

## See also

[D3DX X File Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-x-file-structures)

[**ID3DXCompressedAnimationSet**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxcompressedanimationset)

