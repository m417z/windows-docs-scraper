# DdQueryDirectDrawObject function

## Description

[This function is subject to change with each operating system revision. Instead, use the Microsoft DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.]

Wrapper for the [NtGdiDdQueryDirectDrawObject](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-ntgdiddquerydirectdrawobject) function and queries a previously created kernel-mode representation for capabilities.

**GdiEntry2** is defined as an alias for this function.

## Parameters

### `pDirectDrawGlobal`

Pointer to a user-mode DirectDraw object for which a kernel-side object was previously created with [DdCreateDirectDrawObject](https://learn.microsoft.com/windows/desktop/api/ddrawgdi/nf-ddrawgdi-ddcreatedirectdrawobject).

### `pHalInfo`

Pointer to a **DDHALINFO** structure that will be filled with the device's capabilities. See DDK documentation for details.

### `pDDCallbacks`

Pointer to a table of callback pointers. The table is filled with pointers to functions within Gdi32.dll that imitate a DirectDraw display driver. This callback table is identical to the DDHAL_DDCALLBACKS structure, which maps to the [DD_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_callbacks) structure discussed in the DDK documentation.

### `pDDSurfaceCallbacks`

Pointer to a table of surface callback pointers. The table is filled with pointers to functions within Gdi32.dll that imitate a DirectDraw display driver. This callback table is identical to the DDHAL_DDSURFACECALLBACKS structure, which maps to the [DD_SURFACECALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surfacecallbacks) structure discussed in the DDK documentation.

### `pDDPaletteCallbacks`

Pointer to a table of palette callback pointers. The table is filled with pointers to functions within Gdi32.dll that imitate a DirectDraw display driver. This callback table is identical to the DDHAL_DDPALETTECALLBACKS structure, which maps to the [DD_PALETTECALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_palettecallbacks) structure discussed in the DDK documentation.

### `pD3dCallbacks`

Pointer to a table of Direct3D callback pointers. The table is filled with pointers to functions within Gdi32.dll that imitate a Direct3D display driver. This callback table is identical to the [D3DHAL_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dhal/ns-d3dhal-_d3dhal_callbacks) structure discussed in the DDK documentation.

### `pD3dDriverData`

Pointer to [D3DHAL_GLOBALDRIVERDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dhal/ns-d3dhal-_d3dhal_globaldriverdata) data, as described in the DDK documentation.

### `pD3dBufferCallbacks`

Pointer to a table of callback pointers. The table is filled with pointers to functions within Gdi32.dll that imitate a Direct3D display driver. This callback table is identical to the DDHAL_DDEXEBUFCALLBACKS structure, which maps to the [DD_D3DBUFCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_d3dbufcallbacks) structure discussed in the DDK documentation, except that members XxxD3DBuffer in **DD_D3DBUFCALLBACKS** are replaced with XxxExecuteBuffer in DDHAL_DDEXEBUFCALLBACKS.

### `pD3dTextureFormats`

Pointer to an array of **DDSURFACEDESC** structures that define the set of permissible texture formats.

### `pdwFourCC`

Pointer to a list of supported [Four-Character Codes (FOURCC)](https://learn.microsoft.com/windows/desktop/DirectShow/fourcc-codes) surface formats. Can be **NULL**.

### `pvmList`

Pointer to a list of video memory heap descriptors. Can be **NULL**. This parameter is not used because video memory management is handled entirely within kernel mode.

## Return value

If successful, this function returns **TRUE**; otherwise it returns **FALSE**.

## Remarks

A call to this function is designed to be made in a two-step process. In the first step, *pdwFourCC*, *pvmList* and *pD3dTextureFormats* should be **NULL**, and **DdQueryDirectDrawObject** will fill in **DDHALINFO**.**ddCaps**.**dwNumFourCCCodes**, **DDHALINFO**.**vmiData**.**dwNumHeaps**, and [D3DHAL_GLOBALDRIVERDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dhal/ns-d3dhal-_d3dhal_globaldriverdata).**dwNumTextureFormats** with the number of entries that are to be returned. In the second call, the caller should allocate arrays of the indicated size and pass those pointers instead of **NULL** values in the *pdwFourCC*, *pvmList* and *pD3dTextureFormats* parameters. The arrays will then be populated with appropriate data.

Applications are advised to use the
DirectDraw and
[Direct3D](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference) APIs to create and manage graphics device objects. These constructs abstract the device creation process in a simplified and operating-system-independent way.

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/desktop/DevNotes/-dxgkernel-low-level-client-support)