# D3D10_MAPPED_TEXTURE2D structure

## Description

Provides access to [subresource](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) data in a 2D texture.

## Members

### `pData`

Type: **void***

Pointer to the data.

### `RowPitch`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The pitch, or width, or physical size (in bytes), of one row of an uncompressed texture. A block-compressed texture is encoded in 4x4 blocks (see [virtual size vs physical size](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-block-compression)) ; therefore, **RowPitch** is the number of bytes in a block of 4x4 texels.

## Remarks

This structure is used in a call to [Map](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10texture2d-map).

To illustrate the row pitch, assume an uncompressed 2D texture with mipmap levels, as shown in the following illustration.

![Illustration of an uncompressed 2D texture with mipmap levels](https://learn.microsoft.com/windows/win32/api/d3d10/images/d3d10_resource_texture2d.png)

Visualize the top-level texture drawn in a single plane like the following illustration.

![Illustration of a single plane](https://learn.microsoft.com/windows/win32/api/d3d10/images/d3d10_2d_texture_conceptual.png)

However, the actual layout of each element in memory looks more like the following illustration.

![Illustration of the row pitch in memory](https://learn.microsoft.com/windows/win32/api/d3d10/images/d3d10_2d_texture_memory.png)

For this example, the row pitch encompasses 5 elements (one row), whose size would be five times the number of bytes per element.

Use row pitch to advance a pointer between rows within a single 2D texture plane.

### Example

To access data in, say, the third mipmap level, you must cast the **pData** pointer as demonstrated in the following example for a floating-point texture.

```

D3D10_MAPPED_TEXTURE2D mappedTexture;
if( SUCCEEDED( pTexture->Map( D3D10CalcSubresource(2, 0, 3), D3D10_MAP_WRITE_DISCARD, 0, &mappedTexture )))
{
    D3D10_TEXTURE2D_DESC desc;
    pTexture->GetDesc( &desc );
	
    // Compute the width and height of the third mipmap level
    const UINT WIDTH = desc.Width >> 2;
    const UINT HEIGHT = desc.Height >> 2;
	
    FLOAT* pTexels = (FLOAT*)mappedTexture.pData;
    for( UINT row = 0; row < HEIGHT; row++ )
    {
      UINT rowStart = row * mappedTexture.RowPitch/4;
      for( UINT col = 0; col < WIDTH; col++ )
      {
        pTexels[rowStart + col*4 + 0]; // Red
        pTexels[rowStart + col*4 + 1]; // Green
        pTexels[rowStart + col*4 + 2]; // Blue
        pTexels[rowStart + col*4 + 3]; // Alpha
      }
    }

    pTexture->Unmap(D3D10CalcSubresource(2, 0, 3));
}

```

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-resource-structures)