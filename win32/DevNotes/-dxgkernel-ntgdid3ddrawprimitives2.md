# NtGdiD3DDrawPrimitives2 function

\[This function is subject to change with each operating system revision. Instead, use the Microsoft DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.\]

Renders primitives and returns the updated render state.

## Parameters

*hCmdBuf* \[in\]

Handle to the [**DD\_SURFACE\_LOCAL**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_surface_local) structure that identifies the DirectDraw surface containing the command data.

*hVBuf* \[in\]

Handle to the [**DD\_SURFACE\_LOCAL**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_surface_local) structure that identifies the DirectDraw surface containing the vertex data.

*pded* \[in, out\]

Pointer to a [**D3DNTHAL\_DRAWPRIMITIVES2DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/) structure that contains the information required for the driver to render one or more primitives.

*pfpVidMemCmd* \[in, out\]

New pointer to video memory if the driver swapped the command buffer.

*pdwSizeCmd* \[in, out\]

Specifies the minimum number of bytes that the driver must increase the swap command buffer by.

*pfpVidMemVtx* \[in, out\]

New pointer to video memory if the driver swapped the vertex buffer.

*pdwSizeVtx* \[in, out\]

Specifies the minimum number of bytes that the driver must allocate for the swap vertex buffer.

## Return value

**NtGdiD3DDrawPrimitives2** returns one of the following callback codes.

| Return code | Description |
|----------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **DDHAL\_DRIVER\_HANDLED** | The driver has performed the operation and returned a valid return code for that operation. If this code is DD\_OK, DirectDraw or Direct3D proceeds with the function. Otherwise, DirectDraw or Direct3D returns the error code provided by the driver and aborts the function.<br> |
| **DDHAL\_DRIVER\_NOTHANDLED** | The driver has no comment on the requested operation. If the driver is required to have implemented a particular callback, DirectDraw or Direct3D reports an error condition. Otherwise, DirectDraw or Direct3D handles the operation as if the driver callback had not been defined by executing the DirectDraw or Direct3D device-independent implementation.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Ntgdi.h |

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-low-level-client-support)

