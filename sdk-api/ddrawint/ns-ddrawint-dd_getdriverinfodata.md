# DD_GETDRIVERINFODATA structure

## Description

The DD_GETDRIVERINFODATA structure is used to pass data to and from the *DdGetDriverInfo* callback routine.

## Members

### `dhpdev`

Handle to the driver's [PDEV](https://learn.microsoft.com/windows-hardware/drivers/display/pdev-negotiation). Microsoft Windows 2000 and later only.

### `dwSize`

Specifies the size in bytes of this DD_GETDRIVERINFODATA structure.

### `dwFlags`

Currently unused and is set to zero.

### `guidInfo`

Specifies the GUID of the Microsoft DirectX support for which the driver is being queried. In a Windows 2000 and later Microsoft DirectDraw driver, this member can be one of the following values (in alphabetic order):

| GUID | Description |
| --- | --- |
| GUID_ColorControlCallbacks | Queries whether the driver supports [DdControlColor](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_colorcb_colorcontrol). If the driver does support it, the driver should initialize and return a [DD_COLORCONTROLCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_colorcontrolcallbacks) structure in the buffer to which **lpvData** points. |
| GUID_D3DCallbacks | Queries whether the driver supports any of the functionality specified through the [D3DHAL_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dhal/ns-d3dhal-_d3dhal_callbacks) structure. If the driver does not provide any of this support, it should initialize and return a D3DHAL_CALLBACKS structure in the buffer to which **lpvData** points. |
| GUID_D3DCallbacks2 | Obsolete. |
| GUID_D3DCallbacks3 | Queries whether the driver supports any of the functionality specified through the [D3DHAL_CALLBACKS3](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dhal/ns-d3dhal-_d3dhal_callbacks3) structure. If the driver does provide any of this support, it should initialize and return a D3DHAL_CALLBACKS3 structure in the buffer to which **lpvData** points. |
| GUID_D3DCaps | Obsolete. |
| GUID_D3DExtendedCaps | Queries whether the driver supports any of the Microsoft Direct3D functionality specified through the [D3DHAL_D3DEXTENDEDCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dhal/ns-d3dhal-_d3dhal_d3dextendedcaps) structure. If the driver does provide any of this support, it should initialize and return a D3DHAL_D3DEXTENDEDCAPS structure in the buffer to which **lpvData** points. |
| GUID_D3DParseUnknownCommandCallback | Provides the Direct3D portion of the driver with the Direct3D runtime's *D3dParseUnknownCommandCallback*. The driver's [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback calls *D3dParseUnknownCommandCallback* to parse commands from the command buffer that the driver doesn't understand.DirectDraw passes a pointer to this function in the buffer to which **lpvData** points. If the driver supports this aspect of Direct3D, it should store the pointer. |
| GUID_GetHeapAlignment | Queries whether the driver supports surface alignment requirements on a per-heap basis. If the driver does provide this support, it should initialize and return a [DD_GETHEAPALIGNMENTDATA](https://learn.microsoft.com/windows/desktop/api/dmemmgr/ns-dmemmgr-dd_getheapalignmentdata) structure in the buffer to which **lpvData** points. |
| GUID_KernelCallbacks | Queries whether the driver supports any of the functionality specified through the [DD_KERNELCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_kernelcallbacks) structure. If the driver does provide any of this support, it should initialize and return a DD_KERNELCALLBACKS structure in the buffer to which **lpvData** points. |
| GUID_KernelCaps | Queries whether the driver supports any of the kernel-mode capabilities specified through the [DDKERNELCAPS](https://learn.microsoft.com/windows/desktop/api/ddkernel/ns-ddkernel-ddkernelcaps) structure. If the driver does provide any of this support, it should initialize and return a DDKERNELCAPS structure in the buffer to which **lpvData** points. |
| GUID_MiscellaneousCallbacks | Queries whether the driver supports [DdGetAvailDriverMemory](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getavaildrivermemory). If the driver does support it, the driver should initialize and return a [DD_MISCELLANEOUSCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_miscellaneouscallbacks) structure in the buffer to which **lpvData** points. |
| GUID_Miscellaneous2Callbacks | Queries whether the driver supports the additional miscellaneous functionality specified in the [DD_MISCELLANEOUS2CALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_miscellaneous2callbacks) structure. If the driver does support any of this support, the driver should initialize and return a DD_MISCELLANEOUS2CALLBACKS structure in the buffer to which **lpvData** points. |
| GUID_MotionCompCallbacks | Queries whether the driver supports the motion compensation functionality specified through the [DD_MOTIONCOMPCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_motioncompcallbacks) structure. If the driver does provide any of this support, is should initialize and return a DD_MOTIONCOMPCALLBACKS structure in the buffer to which **lpvData** points. |
| GUID_NonLocalVidMemCaps | Queries whether the driver supports any of the nonlocal display memory capabilities specified through the [DD_NONLOCALVIDMEMCAPS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_nonlocalvidmemcaps) structure. If the driver does provide any of this support, it should initialize and return a DD_NONLOCALVIDMEMCAPS structure in the buffer to which **lpvData** points. |
| GUID_NTCallbacks | Queries whether the driver supports any of the functionality specified through the [DD_NTCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_ntcallbacks) structure. If the driver does provide any of this support, it should initialize and return a DD_NTCALLBACKS structure in the buffer to which **lpvData** points. |
| GUID_NTPrivateDriverCaps | Queries whether the driver supports the Windows 98/Me-style surface creation techniques specified through the [DD_NTPRIVATEDRIVERCAPS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_ntprivatedrivercaps) structure. If the driver does provide any of this support, it should initialize and return a DD_NTPRIVATEDRIVERCAPS structure in the buffer to which **lpvData** points. |
| GUID_UpdateNonLocalHeap | Queries whether the driver supports retrieval of the base addresses of each nonlocal heap in turn. If the driver does provide this support, it should initialize and return a [DD_UPDATENONLOCALHEAPDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_updatenonlocalheapdata) structure in the buffer to which **lpvData** points. |
| GUID_VideoPortCallbacks | Queries whether the driver supports the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/). If the driver does support VPE, it should initialize and return a [DD_VIDEOPORTCALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_videoportcallbacks) structure in the buffer to which **lpvData** points. |
| GUID_VideoPortCaps | Queries whether the driver supports any of the VPE object capabilities specified through the [DDVIDEOPORTCAPS](https://learn.microsoft.com/windows/desktop/api/dvp/ns-dvp-ddvideoportcaps) structure. If the driver does provide any of this support, it should initialize and return a DDVIDEOPORTCAPS structure in the buffer to which **lpvData** points. |
| GUID_ZPixelFormats | Queries the pixel formats supported by the depth buffer. If the driver supports Direct3D, it should allocate and initialize the appropriate members of a DDPIXELFORMAT structure for every z-buffer format that it supports and return these in the buffer to which **lpvData** points. |

### `dwExpectedSize`

Specifies the number of bytes of data that DirectDraw expects the driver to pass back in the buffer to which **lpvData** points.

### `lpvData`

Points to a DirectDraw-allocated buffer into which the driver copies the requested data. This buffer is typically **dwExpectedSize** bytes in size. The driver must not write more than **dwExpectedSize** bytes of data in it. The driver specifies the number of bytes that it writes to this buffer in the **dwActualSize** member.

### `dwActualSize`

Specifies the location in which the driver returns the number of bytes of data it writes in **lpvData**.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

## Remarks

The data structure passed to the driver for a [DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo) call has minor differences between Windows 98/Me and Windows 2000 and later. On Windows 2000 and later the data structure is called DD_GETDRIVERINFODATA and on Windows 98/Me the data structure is called DDHAL_GETDRIVERINFODATA. Both data structures include a field for driver specific context information. On Windows 2000 and later, DD_GETDRIVERINFODATA includes a field **dhpdev** that stores the DHPDEV of the driver being called. Only on Windows 98/Me, DDHAL_GETDRIVERINFODATA includes a field **dwContext** that is copied for the driver reserved **dwReserved3** field of the DirectDraw global object.

## See also

[DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo)