## Description

See the [Basic hologram sample](https://github.com/microsoft/Windows-classic-samples/tree/master/Samples/BasicHologram).

The CPU copies data from memory to a subresource created in non-mappable memory.

## Parameters

### `pDstResource` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)***

A pointer to the destination resource (see [ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)).

### `DstSubresource` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A zero-based index, that identifies the destination subresource. See [D3D11CalcSubresource](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-d3d11calcsubresource) for more details.

### `pDstBox` [in, optional]

Type: **const [D3D11_BOX](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_box)***

A pointer to a box that defines the portion of the destination subresource to copy the resource data into. Coordinates are in bytes for buffers and in texels for textures. If **NULL**, the data is written to the destination subresource with no offset. The dimensions of the source must fit the destination (see [D3D11_BOX](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_box)).

An empty box results in a no-op. A box is empty if the top value is greater than or equal to the bottom value, or the left value is greater than or equal to the right value, or the front value is greater than or equal to the back value. When the box is empty, **UpdateSubresource** doesn't perform an update operation.

### `pSrcData` [in]

Type: **const void***

A pointer to the source data in memory.

### `SrcRowPitch` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size of one row of the source data.

### `SrcDepthPitch` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size of one depth slice of source data.

## Remarks

For a shader-constant buffer; set *pDstBox* to **NULL**. It is not possible to use this method to partially update a shader-constant buffer.

A resource cannot be used as a destination if:

* the resource is created with [immutable](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_usage) or [dynamic](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_usage) usage.
* the resource is created as a depth-stencil resource.
* the resource is created with multisampling capability (see [DXGI_SAMPLE_DESC](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_sample_desc)).

When **UpdateSubresource** returns, the application is free to change or even free the data pointed to by *pSrcData* because the method has already copied/snapped away the original contents.

The performance of **UpdateSubresource** depends on whether or not there is contention for the destination resource. For example, contention for a vertex buffer resource occurs when the application executes a **Draw** call and later calls **UpdateSubresource** on the same vertex buffer before the **Draw** call is actually executed by the GPU.

* When there is contention for the resource, **UpdateSubresource** will perform 2 copies of the source data. First, the data is copied by the CPU to a temporary storage space accessible by the command buffer. This copy happens before the method returns. A second copy is then performed by the GPU to copy the source data into non-mappable memory. This second copy happens asynchronously because it is executed by GPU when the command buffer is flushed.
* When there is no resource contention, the behavior of **UpdateSubresource** is dependent on which is faster (from the CPU's perspective): copying the data to the command buffer and then having a second copy execute when the command buffer is flushed, or having the CPU copy the data to the final resource location. This is dependent on the architecture of the underlying system.

**Note** **Applies only to feature level 9_x hardware** If you use **UpdateSubresource** or [ID3D11DeviceContext::CopySubresourceRegion](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-copysubresourceregion) to copy from a staging resource to a default resource, you can corrupt the destination contents. This occurs if you pass a **NULL** source box and if the source resource has different dimensions from those of the destination resource or if you use destination offsets, (x, y, and z). In this situation, always pass a source box that is the full size of the source resource.

To better understand the source row pitch and source depth pitch parameters, the following illustration shows a 3D volume texture.

![Illustration of a 3D volume texture](https://learn.microsoft.com/windows/win32/api/d3d11/images/D3D10_pitches_conceptual.png)

Each block in this visual represents an element of data, and the size of each element is dependent on the resource's format. For example, if the resource format is DXGI_FORMAT_R32G32B32A32_FLOAT, the size of each element would be 128 bits, or 16 bytes. This 3D volume texture has a width of two, a height of three, and a depth of four.

To calculate the source row pitch and source depth pitch for a given resource, use the following formulas:

* Source Row Pitch = [size of one element in bytes] * [number of elements in one row]
* Source Depth Pitch = [Source Row Pitch] * [number of rows (height)]

In the case of this example 3D volume texture where the size of each element is 16 bytes, the formulas are as follows:

* Source Row Pitch = 16 * 2 = 32
* Source Depth Pitch = 16 * 2 * 3 = 96

The following illustration shows the resource as it is laid out in memory.

![Illustration of a 3D volume texture laid out in memory](https://learn.microsoft.com/windows/win32/api/d3d11/images/D3D10_pitches.png)

For example, the following code snippet shows how to specify a destination region in a 2D texture. Assume the destination texture is 512x512 and the operation will copy the data pointed to by *pData* to [(120,100)..(200,220)] in the destination texture. Also assume that *rowPitch* has been initialized with the proper value (as explained above). **front** and **back** are set to 0 and 1 respectively, because by having **front** equal to **back**, the box is technically empty.

```

D3D11_BOX destRegion;
destRegion.left = 120;
destRegion.right = 200;
destRegion.top = 100;
destRegion.bottom = 220;
destRegion.front = 0;
destRegion.back = 1;

pd3dDeviceContext->UpdateSubresource( pDestTexture, 0, &destRegion, pData, rowPitch, 0 );

```

The 1D case is similar. The following snippet shows how to specify a destination region in a 1D texture. Use the same assumptions as above, except that the texture is 512 in length.

```

D3D11_BOX destRegion;
destRegion.left = 120;
destRegion.right = 200;
destRegion.top = 0;
destRegion.bottom = 1;
destRegion.front = 0;
destRegion.back = 1;

pd3dDeviceContext->UpdateSubresource( pDestTexture, 0, &destRegion, pData, rowPitch, 0 );

```

For info about various resource types and how **UpdateSubresource** might work with each resource type, see [Introduction to a Resource in Direct3D 11](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-resources-intro).

### Calling UpdateSubresource on a Deferred Context

If your application calls **UpdateSubresource** on a deferred context with a destination box—to which *pDstBox* points—that has a non-(0,0,0) offset, and if the driver does not support command lists, **UpdateSubresource** inappropriately applies that destination-box offset to the *pSrcData* parameter. To work around this behavior, use the following code:

```

HRESULT UpdateSubresource_Workaround(
  ID3D11Device *pDevice,
  ID3D11DeviceContext *pDeviceContext,
  ID3D11Resource *pDstResource,
  UINT dstSubresource,
  const D3D11_BOX *pDstBox,
  const void *pSrcData,
  UINT srcBytesPerElement,
  UINT srcRowPitch,
  UINT srcDepthPitch,
  bool* pDidWorkAround )
{
     HRESULT hr = S_OK;
     bool needWorkaround = false;
     D3D11_DEVICE_CONTEXT_TYPE contextType = pDeviceContext->GetType();

     if( pDstBox && (D3D11_DEVICE_CONTEXT_DEFERRED == contextType) )
     {
          D3D11_FEATURE_DATA_THREADING threadingCaps = { FALSE, FALSE };

          hr = pDevice->CheckFeatureSupport( D3D11_FEATURE_THREADING, &threadingCaps, sizeof(threadingCaps) );
          if( SUCCEEDED(hr) )
          {
               if( !threadingCaps.DriverCommandLists )
               {
                    needWorkaround = true;
               }
          }
     }

     const void* pAdjustedSrcData = pSrcData;

     if( needWorkaround )
     {
          D3D11_BOX alignedBox = *pDstBox;
		
          // convert from pixels to blocks
          if( m_bBC )
          {
               alignedBox.left     /= 4;
               alignedBox.right    /= 4;
               alignedBox.top      /= 4;
               alignedBox.bottom   /= 4;
          }

          pAdjustedSrcData = ((const BYTE*)pSrcData) - (alignedBox.front * srcDepthPitch) - (alignedBox.top * srcRowPitch) - (alignedBox.left * srcBytesPerElement);
     }

     pDeviceContext->UpdateSubresource( pDstResource, dstSubresource, pDstBox, pAdjustedSrcData, srcRowPitch, srcDepthPitch );

     if( pDidWorkAround )
     {
          *pDidWorkAround = needWorkaround;
     }

     return hr;
}

```

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)

[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)

[Basic hologram sample](https://github.com/microsoft/Windows-classic-samples/tree/master/Samples/BasicHologram)