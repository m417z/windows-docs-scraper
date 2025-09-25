# D3D_PRIMITIVE_TOPOLOGY enumeration

## Description

Values that indicate how the pipeline interprets vertex data that is bound to the [input-assembler stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage). These [primitive topology values](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-primitive-topologies) determine how the vertex data is rendered on screen.

> [!NOTE]
> For programming with Direct3D 10, this API has a type alias that begins `D3D10_` instead of `D3D_`. These Direct3D 10 type aliases are defined in `d3d10.h`, `d3d10misc.h`, and `d3d10shader.h`.

## Constants

### `D3D_PRIMITIVE_TOPOLOGY_UNDEFINED:0`

The IA stage has not been initialized with a primitive topology. The IA stage will not function properly unless a primitive topology is defined.

### `D3D_PRIMITIVE_TOPOLOGY_POINTLIST:1`

Interpret the vertex data as a list of points.

### `D3D_PRIMITIVE_TOPOLOGY_LINELIST:2`

Interpret the vertex data as a list of lines.

### `D3D_PRIMITIVE_TOPOLOGY_LINESTRIP:3`

Interpret the vertex data as a line strip.

### `D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST:4`

Interpret the vertex data as a list of triangles.

### `D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP:5`

Interpret the vertex data as a triangle strip.

### `D3D_PRIMITIVE_TOPOLOGY_LINELIST_ADJ:10`

Interpret the vertex data as a list of lines with adjacency data.

### `D3D_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ:11`

Interpret the vertex data as a line strip with adjacency data.

### `D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ:12`

Interpret the vertex data as a list of triangles with adjacency data.

### `D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ:13`

Interpret the vertex data as a triangle strip with adjacency data.

### `D3D_PRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST:33`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_2_CONTROL_POINT_PATCHLIST:34`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST:35`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST:36`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_5_CONTROL_POINT_PATCHLIST:37`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_6_CONTROL_POINT_PATCHLIST:38`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_7_CONTROL_POINT_PATCHLIST:39`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_8_CONTROL_POINT_PATCHLIST:40`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_9_CONTROL_POINT_PATCHLIST:41`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_10_CONTROL_POINT_PATCHLIST:42`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_11_CONTROL_POINT_PATCHLIST:43`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_12_CONTROL_POINT_PATCHLIST:44`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_13_CONTROL_POINT_PATCHLIST:45`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_14_CONTROL_POINT_PATCHLIST:46`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_15_CONTROL_POINT_PATCHLIST:47`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_16_CONTROL_POINT_PATCHLIST:48`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_17_CONTROL_POINT_PATCHLIST:49`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_18_CONTROL_POINT_PATCHLIST:50`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_19_CONTROL_POINT_PATCHLIST:51`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_20_CONTROL_POINT_PATCHLIST:52`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_21_CONTROL_POINT_PATCHLIST:53`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_22_CONTROL_POINT_PATCHLIST:54`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_23_CONTROL_POINT_PATCHLIST:55`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_24_CONTROL_POINT_PATCHLIST:56`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_25_CONTROL_POINT_PATCHLIST:57`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_26_CONTROL_POINT_PATCHLIST:58`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_27_CONTROL_POINT_PATCHLIST:59`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_28_CONTROL_POINT_PATCHLIST:60`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_29_CONTROL_POINT_PATCHLIST:61`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_30_CONTROL_POINT_PATCHLIST:62`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_31_CONTROL_POINT_PATCHLIST:63`

Interpret the vertex data as a patch list.

### `D3D_PRIMITIVE_TOPOLOGY_32_CONTROL_POINT_PATCHLIST:64`

Interpret the vertex data as a patch list.

### `D3D10_PRIMITIVE_TOPOLOGY_UNDEFINED`

The IA stage has not been initialized with a primitive topology. The IA stage will not function properly unless a primitive topology is defined.

### `D3D10_PRIMITIVE_TOPOLOGY_POINTLIST`

Interpret the vertex data as a list of points.

### `D3D10_PRIMITIVE_TOPOLOGY_LINELIST`

Interpret the vertex data as a list of lines.

### `D3D10_PRIMITIVE_TOPOLOGY_LINESTRIP`

Interpret the vertex data as a line strip.

### `D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST`

Interpret the vertex data as a list of triangles.

### `D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP`

Interpret the vertex data as a triangle strip.

### `D3D10_PRIMITIVE_TOPOLOGY_LINELIST_ADJ`

Interpret the vertex data as a list of lines with adjacency data.

### `D3D10_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ`

Interpret the vertex data as a line strip with adjacency data.

### `D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ`

Interpret the vertex data as a list of triangles with adjacency data.

### `D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ`

Interpret the vertex data as a triangle strip with adjacency data.

### `D3D11_PRIMITIVE_TOPOLOGY_UNDEFINED`

The IA stage has not been initialized with a primitive topology. The IA stage will not function properly unless a primitive topology is defined.

### `D3D11_PRIMITIVE_TOPOLOGY_POINTLIST`

Interpret the vertex data as a list of points.

### `D3D11_PRIMITIVE_TOPOLOGY_LINELIST`

Interpret the vertex data as a list of lines.

### `D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP`

Interpret the vertex data as a line strip.

### `D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST`

Interpret the vertex data as a list of triangles.

### `D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP`

Interpret the vertex data as a triangle strip.

### `D3D11_PRIMITIVE_TOPOLOGY_LINELIST_ADJ`

Interpret the vertex data as a list of lines with adjacency data.

### `D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ`

Interpret the vertex data as a line strip with adjacency data.

### `D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ`

Interpret the vertex data as a list of triangles with adjacency data.

### `D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ`

Interpret the vertex data as a triangle strip with adjacency data.

### `D3D11_PRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_2_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_5_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_6_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_7_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_8_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_9_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_10_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_11_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_12_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_13_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_14_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_15_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_16_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_17_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_18_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_19_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_20_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_21_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_22_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_23_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_24_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_25_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_26_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_27_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_28_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_29_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_30_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_31_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

### `D3D11_PRIMITIVE_TOPOLOGY_32_CONTROL_POINT_PATCHLIST`

Interpret the vertex data as a patch list.

## Remarks

Use the [ID3D11DeviceContext::IASetPrimitiveTopology](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-iasetprimitivetopology) method and a value from **D3D_PRIMITIVE_TOPOLOGY** to bind a primitive topology to the input-assembler stage. Use the [ID3D11DeviceContext::IAGetPrimitiveTopology](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-iagetprimitivetopology) method to retrieve the primitive topology for the input-assembler stage.

The following diagram shows the various primitive types for a geometry shader object.

![Illustration of the various primitive types for a geometry shader object](https://learn.microsoft.com/windows/win32/api/d3dcommon/images/D3D11_GSInputs1.png)

## See also

[Common Version Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-common-enumerations)