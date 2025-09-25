# ID3D10Buffer::Map

## Description

Get a pointer to the data contained in the resource and deny GPU access to the resource.

## Parameters

### `MapType` [in]

Type: **[D3D10_MAP](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_map)**

Flag that specifies the CPU's permissions for the reading and writing of a resource. For possible values, see [D3D10_MAP](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_map).

### `MapFlags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flag that specifies what the CPU should do when the GPU is busy (see [D3D10_MAP_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_map_flag)). This flag is optional.

### `ppData` [out]

Type: **void****

Pointer to the buffer resource data.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this function succeeds, it returns S_OK. The following list contains some of the reasons that **Map** can fail:

* If *MapFlags* specifies D3D10_MAP_FLAG_DO_NOT_WAIT and the GPU is not yet finished with the resource, **ID3D10Buffer::Map**
  returns DXGI_ERROR_WAS_STILL_DRAWING.
* **ID3D10Buffer::Map** returns DXGI_ERROR_DEVICE_REMOVED if *MapType* includes any flags that permit reading and the hardware
  device (that is, the video card) has been removed.

For more information about the preceding return values, see [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## Remarks

For the CPU to write the contents of a resource, the resource must be created with the dynamic usage flag, D3D10_USAGE_DYNAMIC.
To both read and write those contents, the resource must be created with the staging usage flag, D3D10_USAGE_STAGING. (For more information about
these flags, see [D3D10_USAGE](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_usage).) **ID3D10Buffer::Map** will retrieve a pointer to the resource data.
For a discussion on how to access resources efficiently, see [Copying and Accessing Resource Data (Direct3D 10)](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-mapping).

Call [ID3D10Buffer::Unmap](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10buffer-unmap) to signify that the application has finished accessing the resource.

**ID3D10Buffer::Map** has a few other restrictions. For example:

* The same buffer cannot be mapped multiple times; in other words, do not call **ID3D10Buffer::Map** on a buffer that is already mapped.
* Any buffer that is bound to the pipeline must be unmapped before any rendering operation (that is, [ID3D10Device::Draw](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-draw))
  can be executed.

|  |
| --- |
| Differences between Direct3D 9 and Direct3D 10:<br><br>**ID3D10Buffer::Map** in Direct3D 10 is analogous to resource [Lock](https://learn.microsoft.com/windows/desktop/direct3d9/locking-resources) in Direct3D 9. |

## See also

[ID3D10Buffer Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10buffer)