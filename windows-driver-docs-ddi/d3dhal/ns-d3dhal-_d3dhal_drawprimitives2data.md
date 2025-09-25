# _D3DHAL_DRAWPRIMITIVES2DATA structure

## Description

The D3DHAL_DRAWPRIMITIVES2DATA structure contains the information required by the [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) function to render primitives.

## Members

### `dwhContext`

Specifies the context handle of the Direct3D device.

### `dwFlags`

Specifies flags that provide additional instructions to the driver or provide information from the driver. This member can be a bitwise OR of the following values:

|Value|Meaning|
|--- |--- |
|D3DHALDP2_EXECUTEBUFFER|The command and vertex buffers were created in system memory. The driver should update the state array that lpdwRStates points to. This flag is set by Direct3D only.|
|D3DHALDP2_REQCOMMANDBUFSIZE|The driver must be able to increase the current command buffer by at least the size specified in dwReqCommandBufSize. Drivers that do not support multibuffering of command buffers can ignore this flag. This flag is set by Direct3D only.|
|D3DHALDP2_REQVERTEXBUFSIZE|The driver must be able to allocate a vertex buffer of at least the size specified in dwReqCommandBufSize. Drivers that do not support multibuffering of vertex buffers can ignore this flag. This flag is set by Direct3D only.|
|D3DHALDP2_SWAPCOMMANDBUFFER|The driver can swap the buffer that lpDDCommands points to with a new command buffer and return immediately, asynchronously processing the original buffer while Direct3D fills the new command buffer. Drivers that do not support multibuffering of command buffers can ignore this flag. This flag is set by Direct3D only.|
|D3DHALDP2_SWAPVERTEXBUFFER|The driver can swap the buffer that lpDDVertex or lpVertices points to with a new vertex buffer and return immediately, asynchronously processing the original buffer while Direct3D fills the new vertex buffer. Drivers that do not support multibuffering of vertex buffers can ignore this flag. This flag is set by Direct3D only.|
|D3DHALDP2_USERMEMVERTICES|The lpVertices member is valid so the driver should obtain the vertex data from the user-allocated memory that lpVertices points to. This flag is set by Direct3D only.|
|D3DHALDP2_VIDMEMCOMMANDBUF|The command buffer allocated by the driver as a swap buffer is not in system memory. This flag can be set by drivers that support multibuffering of command buffers.|
|D3DHALDP2_VIDMEMVERTEXBUF|The vertex buffer allocated by the driver as a swap buffer is not in system memory. This flag can be set by drivers that support multibuffering of vertex buffers.|

### `dwVertexType`

Identifies the [FVF](https://learn.microsoft.com/windows-hardware/drivers/display/fvf--flexible-vertex-format-) of the data in the vertex buffer; that is, **dwVertexType** specifies which per-vertex data fields are present in the vertex buffer that **lpDDVertex** or **lpVertices** points to. This member can be a bitwise OR of the values in the following table. Only one of the *D3DFVF_TEXx* flags is set.

|Value|Meaning|
|--- |--- |
|D3DFVF_DIFFUSE|Each vertex has a diffuse color.|
|D3DFVF_SPECULAR|Each vertex has a specular color.|
|D3DFVF_TEX0|No texture coordinates are provided with the vertex data.|
|D3DFVF_TEX1|Each vertex has one set of texture coordinates.|
|D3DFVF_TEX2|Each vertex has two sets of texture coordinates.|
|D3DFVF_TEX3|Each vertex has three sets of texture coordinates.|
|D3DFVF_TEX4|Each vertex has four sets of texture coordinates.|
|D3DFVF_TEX5|Each vertex has five sets of texture coordinates.|
|D3DFVF_TEX6|Each vertex has six sets of texture coordinates.|
|D3DFVF_TEX7|Each vertex has seven sets of texture coordinates.|
|D3DFVF_TEX8|Each vertex has eight sets of texture coordinates.|
|D3DFVF_XYZRHW|Each vertex has x, y, z, and w coordinates. This flag is always set.|

### `lpDDCommands`

### `dwCommandOffset`

### `dwCommandLength`

Specifies the number of bytes of valid command data in the surface that **lpDDCommands** points to starting at **dwCommandOffset**.

### `lpDDVertex`

Points to the [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_surface_local) structure that identifies the DirectDraw surface containing the vertex data when the D3DHALDP2_USERMEMVERTICES flag is not set in **dwFlags**. Forms a union with **lpVertices**.

### `lpVertices`

Points to a user-mode memory block containing vertex data when the D3DHALDP2_USERMEMVERTICES flag is set in **dwFlags**.

### `dwVertexOffset`

Specifies the number of bytes into the surface pointed to by **lpDDVertex** or **lpVertices** where the vertex data starts.

### `dwVertexLength`

Specifies the number of vertices for which valid data exists in the surface pointed to by **lpDDVertex** or **lpVertices**. This valid data starts at **dwVertexOffset**.

### `dwReqVertexBufSize`

Specifies the minimum number of bytes that the driver must allocate for the swap vertex buffer. This member is valid only when the D3DHALDP2_REQVERTEXBUFSIZE flag is set. Drivers that do not support multibuffering of vertex buffers should ignore this member.

### `dwReqCommandBufSize`

Specifies the minimum number of bytes that the driver must increase the swap command buffer by. This member is valid only when the D3DHALDP2_REQCOMMANDBUFSIZE flag is set. Drivers that do not support multibuffering of command buffers should ignore this member.

### `lpdwRStates`

Points to a render state array that the driver should update when it parses render state commands from the command buffer. The driver should update this array only when the D3DHALDP2_EXECUTEBUFFER flag is set in **dwFlags**. The driver should use the [D3DRENDERSTATETYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d9types/ne-d3d9types-_d3drenderstatetype) enumerated types to update the appropriate element of the render state array.

### `dwVertexSize`

Specifies the size of each vertex, in bytes. This member forms a union with **ddrval**.

### `ddrval`

Specifies the location where the driver writes the return value of [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb). D3D_OK indicates success. Otherwise, the driver should return the appropriate D3DERR_*Xxx* error code. For more information, see [Return Codes for Direct3D Driver Callbacks](https://learn.microsoft.com/windows-hardware/drivers/display/return-codes-for-direct3d-driver-callbacks).

|Value|Meaning|
|--- |--- |
|D3D_OK|The operation completed successfully.|
|D3DERR_COMMAND_UNPARSED|The driver requires the Direct3D runtime to parse the execute buffer.|

### `dwErrorOffset`

Each D3DHAL_DP2RESPONSEQUERY is followed by the following data related to the query:

* BOOL for D3DQUERYTYPE_EVENT
* DWORD for D3DQUERYTYPE_OCCLUSION
* D3DDEVINFO_VCACHE structure for D3DQUERYTYPE_VCACHE

## Remarks

Note that the **dwVertexOffset** member specifies values in bytes; the **dwVertexLength** member specifies values in vertices.

To calculate the valid data, in bytes, that exists in the surface at **lpDDVertex** or **lpVertices**, multiply the value in **dwVertexLength** by the value in **dwVertexSize**.

## See also

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3DRENDERSTATETYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d9types/ne-d3d9types-_d3drenderstatetype)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)

[DD_SURFACE_GLOBAL](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_surface_global)

[DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_surface_local)