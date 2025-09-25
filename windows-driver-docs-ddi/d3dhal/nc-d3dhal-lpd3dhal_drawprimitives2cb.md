# LPD3DHAL_DRAWPRIMITIVES2CB callback function

## Description

The **D3dDrawPrimitives2** function renders primitives and returns the updated render state.

## Parameters

### `unnamedParam1`

*pdp* [in]

Points to a [D3DHAL_DRAWPRIMITIVES2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_drawprimitives2data) structure that contains the information required for the driver to render one or more primitives.

## Return value

**D3dDrawPrimitives2** returns one of the following callback codes:

## Remarks

**D3dDrawPrimitives2** must be implemented in Microsoft Direct3D drivers.

The driver must do the following:

* Ensure that the context handle specified by the **dwhContext** member of the D3DHAL_DRAWPRIMITIVES2DATA structure at *pdp* is valid.
* Check that a flip to the drawing surface associated with the context is not in progress. If the drawing surface is involved in a flip, the driver should set the **ddrval** member of D3DHAL_DRAWPRIMITIVES2DATA to DDERR_WASSTILLDRAWING and return DDHAL_DRIVER_HANDLED.
* Determine the location of the first [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure by adding the number of bytes in the **dwCommandOffset** member of D3DHAL_DRAWPRIMITIVES2DATA to the command buffer to which the **lpDDCommands** member of D3DHAL_DRAWPRIMITIVES2DATA points.
* Determine the location of the first vertex in the vertex buffer. This should only be done if there is data in the vertex buffer; that is, when a D3DDP2OP_*Xxx* command token is received (except when the token is D3DDP2OP_LINELIST_IMM or D3DDP2OP_TRIANGLEFAN_IMM). These two opcodes indicate that the vertex data is passed immediately in the command stream, rather than in a vertex buffer. So, assuming there is data in the vertex buffer, if the vertex buffer is in user memory, the first vertex is **dwVertexOffset** bytes into the buffer that **lpVertices** points to. Otherwise, the driver should apply **dwVertexOffset** to the memory associated with the [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_surface_local) structure to which **lpDDVertex** points. **dwVertexOffset**, **lpVertices**, and **lpDDVertex** are members of D3DHAL_DRAWPRIMITIVES2DATA.
* Check the **dwVertexType** member of D3DHAL_DRAWPRIMITIVES2DATA to ensure that the driver supports the requested [FVF](https://learn.microsoft.com/windows-hardware/drivers/display/fvf--flexible-vertex-format-). The driver should fail the call if any of the following conditions exist:
  + Vertex coordinates are not specified; that is, if D3DFVF_XYZRHW is not set.
  + Normals are specified; that is, if D3DFVF_NORMAL is set.
  + Any of the reserved D3DFVF_RESERVED *x* bits are set.
* Process all of the commands in the command buffer sequentially. For each D3DHAL_DP2COMMAND structure, the driver should do the following:
  + If the command is D3DDP2OP_RENDERSTATE, process the **wStateCount** [D3DHAL_DP2RENDERSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2renderstate) structures that follow in the command buffer, updating the driver state for each render state structure. When the D3DHALDP2_EXECUTEBUFFER flag is set, the driver should also reflect the state change in the array that **lpdwRStates** points to. **wStateCount**  and **lpdwRStates** are members of D3DHAL_DRAWPRIMITIVES2DATA.
  + If the command is D3DDP2OP_TEXTURESTAGESTATE, process the **wStateCount** [D3DHAL_DP2TEXTURESTAGESTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2texturestagestate) structures that follow in the command buffer, updating the driver's texture state associated with the specified texture stage for each texture state structure.
  + If the command is D3DDP2OP_VIEWPORTINFO, process the [D3DHAL_DP2VIEWPORTINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2viewportinfo) structure that follows in the command buffer, updating the viewport information stored in the driver's internal rendering context.
  + If the command is D3DDP2OP_WINFO, process the [D3DHAL_DP2WINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2winfo) structure that follows in the command buffer, updating the w-buffering information stored in the driver's internal rendering context.
  + Otherwise, process the D3DHAL_DP2*Xxx* primitive structures that follow the D3DDP2OP_*Xxx* primitive rendering command in the command buffer.
  + If the command is unknown, call the runtime's **D3dParseUnknownCommand** callback. The runtime provides this callback to the driver's [DdGetDriverInfo](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_getdriverinfo) callback with the GUID_D3DParseUnknownCommandCallback GUID.

The driver does not need to probe for readability of the memory where the command and vertex buffers are stored. However, the driver must stay within the bounds specified by the **dwCommandLength** and **dwVertexLength** members of D3DHAL_DRAWPRIMITIVES2DATA.

If the driver must fail **D3dDrawPrimitives2**, it should fill in the **dwErrorOffset** member of D3DHAL_DRAWPRIMITIVES2DATA with the offset into the command buffer where the first unhandled D3DHAL_DP2COMMAND can be found.

**Note** The following comments are valid only for applications that are written using Microsoft DirectX 7.0 interfaces and that communicate with drivers through DirectX 8.0 and DirectX 8.1 runtimes.

The following comments are not valid for applications that are written using DirectX 8.0 and later interfaces because such applications no longer use the concept of a current vertex buffer (that is, vertex data is no longer passed in via the **lpDDVertex** member of D3DHAL_DRAWPRIMITIVES2DATA). Therefore, with these applications, the driver's **D3dDrawPrimitives2** function should never cause rendering from a vertex buffer to stall even if the buffer is implicit or explicit and there is an outstanding lock on it.

If the driver is used with a DirectX 8.1 or later runtime, the driver's **D3dDrawPrimitives2** function should never cause rendering from the current vertex buffer (passed in via **lpDDVertex**) to stall if the buffer is implicit. If the buffer is explicit and there is an outstanding lock on it, the driver should stall at the end of its **D3dDrawPrimitives2** function if it does not rename the buffer (does not set D3DHALDP2_SWAPVERTEXBUFFER). If the driver renames the buffer, then the driver does not stall. DirectX 8.1 and later runtimes call the driver's **D3dDrawPrimitives2** function to render from a locked explicit vertex buffer only when necessary so performance is rarely affected. An implicit vertex buffer is created by the driver's [CreateD3DBuffer](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_createsurface) callback with only the DDSCAPS_EXECUTEBUFFER flag set. An explicit vertex buffer is created by the driver's *CreateD3DBuffer* callback with the DDSCAPS_EXECUTEBUFFER and DDSCAPS2_VERTEXBUFFER flags set. The explicit vertex buffer becomes locked by the driver's [LockD3DBuffer](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568216(v=vs.85)) callback.

If the driver is used with a DirectX 8.0 runtime, the driver should sometimes stall when rendering from an implicit current vertex buffer to prevent synchronization issues and resulting corruption. In addition, the DirectX 8.0 runtime calls the driver's **D3dDrawPrimitives2** function to render from a locked explicit current vertex buffer more often then really necessary so performance is degraded. The following are stalling workarounds for a driver that is used with a DirectX 8.0 runtime:

* The driver should stall when it transitions between rendering user-memory primitives (identified by D3DHALDP2_USERMEMVERTICES) and rendering from an implicit current vertex buffer only if it does not rename the buffer (does not set D3DHALDP2_SWAPVERTEXBUFFER).

  The following example shows when **D3dDrawPrimitives2** should stall on an implicit current vertex buffer:

  ```cpp
  DrawPrimitives2(p*, D3DHALDP2_USERMEMVERTICES); // Do not stall
  DrawPrimitives2(Implicit VB, 0); // Stall
  ```

  The following example shows when **D3dDrawPrimitives2** should not stall on an implicit current vertex buffer:

  ```cpp
  DrawPrimitives2(p*, D3DHALDP2_USERMEMVERTICES); // Do not stall
  DrawPrimitives2(Explicit VB, 0); // Do not stall if not locked
  DrawPrimitives2(Explicit VB, D3DHALDP2_SWAPVERTEXBUFFER); // Do not stall whether locked
  DrawPrimitives2(Implicit VB, 0); // Do not stall whether locked
  DrawPrimitives2(Implicit VB, 0); // Do not stall whether locked
  DrawPrimitives2(p*, D3DHALDP2_USERMEMVERTICES); // Do not stall
  DrawPrimitives2(Implicit VB, D3DHALDP2_SWAPVERTEXBUFFER); // Do not stall because D3DHALDP2_SWAPVERTEXBUFFER is set
  ```

  If the runtime sets the D3DHALDP2_REQCOMMANDBUFSIZE flag, then the driver is not required to stall. By coincidence, the DirectX 8.0 runtime also sets D3DHALDP2_REQCOMMANDBUFSIZE when it most commonly renders from a locked explicit current vertex buffer. The driver can therefore improve performance by not stalling when it detects D3DHALDP2_REQCOMMANDBUFSIZE while rendering from a locked explicit current vertex buffer.

  The following example shows when **D3dDrawPrimitives2** should stall on an explicit current vertex buffer:

  ```cpp
  DrawPrimitives2(Explicit VB, 0); // Stall when locked (happens rarely)
  ```

  The following example shows when **D3dDrawPrimitives2** should not stall on an explicit current vertex buffer:

  ```cpp
  DrawPrimitives2(Explicit VB, D3DHALDP2_REQCOMMANDBUFSIZE); // Do not stall whether locked
  DrawPrimitives2(Explicit VB, D3DHALDP2_SWAPVERTEXBUFFER); // Do not stall whether locked
  DrawPrimitives2(Explicit VB, D3DHALDP2_SWAPVERTEXBUFFER | D3DHALDP2_REQCOMMANDBUFSIZE); // Do not stall
  ```

  ## See also

  [D3DHAL_DP2INDEXEDLINELIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2indexedlinelist)

  [D3DHAL_DP2INDEXEDLINESTRIP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2indexedlinestrip)

  [D3DHAL_DP2INDEXEDTRIANGLEFAN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2indexedtrianglefan)

  [D3DHAL_DP2INDEXEDTRIANGLELIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2indexedtrianglelist)

  [D3DHAL_DP2INDEXEDTRIANGLESTRIP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2indexedtrianglestrip)

  [D3DHAL_DP2LINELIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2linelist)

  [D3DHAL_DP2LINESTRIP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2linestrip)

  [D3DHAL_DP2POINTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2points)

  [D3DHAL_DP2TRIANGLEFAN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2trianglefan)

  [D3DHAL_DP2TRIANGLELIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2trianglelist)

  [D3DHAL_DP2TRIANGLESTRIP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2trianglestrip)

  [FVF](https://learn.microsoft.com/windows-hardware/drivers/display/fvf--flexible-vertex-format-)