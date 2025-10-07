# NtGdiDdQueryDirectDrawObject function

\[This function is subject to change with each operating system revision. Instead, use the DirectDraw and Microsoft Direct3DAPIs; these APIs insulate applications from such operating system changes, and hide many other difficulties involved in interacting directly with display drivers.\]

Queries a previously created kernel-mode representation of a Microsoft DirectDraw object for its capabilities.

## Parameters

*hDirectDrawLocal* \[in\]

Handle to the previously-created kernel-mode DirectDraw device.

*pHalInfo* \[out\]

Pointer to a [**DD\_HALINFO**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_halinfo) structure that will be filled with the device's capabilities. See DDK documentation for details.

*pCallBackFlags*

Pointer to a caller-provided buffer that stores driver-reported callback flags. The buffer should be of size 3\*sizeof(DWORD) and stores callback flags in the following order: pCallBackFlags\[0\] for flags in [**DD\_CALLBACKS**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_callbacks), pCallBackFlags\[1\] for flags in [**DD\_SURFACECALLBACKS**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_surfacecallbacks), and pCallBackFlags\[2\] for flags in [**DD\_PALETTECALLBACKS**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_palettecallbacks). See DDK documentation for details.

*puD3dCallbacks* \[out\]

Pointer to a table of Direct3D callback pointers. The table is filled with pointers to functions within Gdi32.dll that imitate a Direct3D display driver. This callback table is identical to the D3DHAL\_D3DCALLBACKS structure discussed in the DDK documentation.

*puD3dDriverData* \[out\]

Pointer to [**D3DHAL\_GLOBALDRIVERDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_globaldriverdata) data, as described in the DDK documentation.

*puD3dBufferCallbacks* \[out\]

Pointer to a table of callback pointers. The table is filled with pointers to functions within Gdi32.dll that imitate a Direct3D display driver. This callback table is identical to the DDHAL\_DDEXEBUFCALLBACKS structure, which maps to the [**DD\_D3DBUFCALLBACKS**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_d3dbufcallbacks) structure discussed in the DDK documentation, except that members XxxD3DBuffer in **DD\_D3DBUFCALLBACKS** are replaced with XxxExecuteBuffer in DDHAL\_DDEXEBUFCALLBACKS.

*puD3dTextureFormats* \[out\]

Pointer to an array of [**DDSURFACEDESC**](https://learn.microsoft.com/windows/win32/api/ddraw/ns-ddraw-ddsurfacedesc) structures that define the set of permissible texture formats.

*puNumHeaps* \[out\]

Pointer to the **dwNumHeaps** member of [**DD\_HALINFO**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_halinfo).**vmiData**. The **dwNumHeaps** member specifies the number of memory heaps in *puvmList*. See DDK documentation for details.

*puvmList* \[out\]

Pointer to a list of video memory heap descriptors. Can be **NULL**. This parameter is not used because video memory management is handled entirely within kernel mode.

*puNumFourCC* \[out\]

Pointer to the **puNumFourCCCodes** member of [**DD\_HALINFO**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_halinfo).**ddCaps**. The **puNumFourCCCodes** member specifies the number of [Four-Character Codes (FOURCC)](https://learn.microsoft.com/windows/win32/directshow/fourcc-codes) codes that the driver supports. See DDK documentation for details.

*puFourCC* \[out\]

Pointer to a list of supported [Four-Character Codes (FOURCC)](https://learn.microsoft.com/windows/win32/directshow/fourcc-codes) surface formats. Can be **NULL**.

## Return value

If successful, this function returns **TRUE**; otherwise it returns **FALSE**.

## Remarks

A call to this function is designed to be made in a two-step process. In the first step, *puFourCC*, *puvmList* and *puD3dTextureFormats* should be **NULL**, and [**DdQueryDirectDrawObject**](https://learn.microsoft.com/windows/desktop/api/Ddrawgdi/nf-ddrawgdi-ddquerydirectdrawobject) will fill in [**DD\_HALINFO**](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_halinfo).**ddCaps**.**dwNumFourCCCodes**, **DD\_HALINFO**.**vmiData**.**dwNumHeaps**, and [**D3DHAL\_GLOBALDRIVERDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_globaldriverdata).**dwNumTextureFormats** with the number of entries that are to be returned. In the second call, the caller should allocate arrays of the indicated size and pass those pointers instead of **NULL** values in the *puFourCC*, *puvmList* and *puD3dTextureFormats* parameters. The arrays will then be populated with appropriate data.

Applications are advised to use the DirectDraw and [Direct3D](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference) APIs to create and manage graphics device objects. These constructs abstract the device creation process in a simplified and operating-system-independent way.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Ntgdi.h |

## See also

[Graphics Low Level Client Support](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-low-level-client-support)

[**DdQueryDirectDrawObject**](https://learn.microsoft.com/windows/desktop/api/Ddrawgdi/nf-ddrawgdi-ddquerydirectdrawobject)

[**NtGdiDdCreateDirectDrawObject**](https://learn.microsoft.com/windows/win32/devnotes/-dxgkernel-ntgdiddcreatedirectdrawobject)

