## Description

The DDSCAPS structure defines the capabilities of a Microsoft DirectDraw surface object.

## Members

### `dwCaps`

Indicates a set of flags that specify the capabilities of the surface. This member is a bitwise OR of any of the following flags:

| Flag | Meaning |
| --- | --- |
| DDSCAPS_3DDEVICE | This surface can be used for 3D rendering. Applications can use this flag to ensure that a device that can only render to a certain heap has offscreen surfaces allocated from the correct heap. If this flag is set for a heap, the surface is not allocated from that heap. |
| DDSCAPS_ALLOCONLOAD | Memory for the surface is not allocated until the surface is loaded by the application using the **IDirect3DTexture::Load** method. |
| DDSCAPS_ALPHA | This surface contains alpha information only. |
| DDSCAPS_BACKBUFFER | This surface is the back buffer of a surface flipping structure. Typically, this capability is set by the application's **CreateSurface** method when the DDSCAPS_FLIP flag is used. Only the surface that immediately precedes the DDSCAPS_FRONTBUFFER surface has this capability set. The other surfaces are identified as back buffers by the presence of the DDSCAPS_FLIP flag, their attachment order, and the absence of the DDSCAPS_FRONTBUFFER and DDSCAPS_BACKBUFFER capabilities. If this capability is sent to the application's **CreateSurface** method, a stand-alone back buffer is being created. After this method is called, this surface could be attached to a front buffer, another back buffer, or both to form a flipping surface structure. For more information, see the **AddAttachedSurface** method in the DirectX SDK. DirectDraw supports an arbitrary number of surfaces in a flipping structure. |
| DDSCAPS_COMPLEX | A complex surface is being described. A complex surface results in the creation of more than one surface. The additional surfaces are attached to the root surface. The complex structure can be destroyed only by destroying the root. |
| DDSCAPS_EXECUTEBUFFER | The surface is an execute buffer, which is a linear chunk of system or video memory that holds a Microsoft Direct3D display list. A driver reports this capability bit to indicate that it can create execute buffers in video memory. If the Direct3D runtime detects this bit, it can request execute buffers from the driver. Applications cannot detect this capability bit. |
| DDSCAPS_FLIP | This surface is a part of a surface flipping structure. When this capability is passed to the application's **CreateSurface** method, a front buffer and one or more back buffers are created. DirectDraw sets the DDSCAPS_FRONTBUFFER bit on the front-buffer surface and the DDSCAPS_BACKBUFFER bit on the surface adjacent to the front-buffer surface. The **dwBackBufferCount** member of the [**DDSURFACEDESC**](https://learn.microsoft.com/windows/win32/api/ddraw/ns-ddraw-ddsurfacedesc) structure must be set to at least 1 in order for the method call to succeed. The DDSCAPS_COMPLEX capability must always be set when creating multiple surfaces by using the **CreateSurface** method. |
| DDSCAPS_FRONTBUFFER | This surface is the front buffer of a surface flipping structure. This flag is typically set by the application's **CreateSurface** method when the DDSCAPS_FLIP capability is set. If this capability is sent to the **CreateSurface** method, a stand-alone front buffer is created. This surface does not have the DDSCAPS_FLIP capability. It can be attached to other back buffers to form a flipping structure by using the application's **AddAttachedSurface** method. |
| DDSCAPS_HWCODEC | This surface should be able to have a stream decompressed to it by the hardware. |
| DDSCAPS_LIVEVIDEO | This surface should be able to receive live video. |
| DDSCAPS_LOCALVIDMEM | This surface exists in true, local display memory rather than nonlocal display memory. If this flag is specified, then DDSCAPS_VIDEOMEMORY must be specified as well. This flag cannot be used with the DDSCAPS_NONLOCALVIDMEM flag. |
| DDSCAPS_MIPMAP | This surface is one level of a mipmap. This surface is attached to other DDSCAPS_MIPMAP surfaces to form the mipmap. This can be done explicitly by creating a number of surfaces and attaching them by using the application's **AddAttachedSurface** method, or implicitly by the application's **CreateSurface** method. If this capability is set, DDSCAPS_TEXTURE must also be set. |
| DDSCAPS_MODEX | This surface is a 320x200 or 320x240 Mode X surface. If this capability bit is set by the Microsoft Windows 2000 or later driver, DirectDraw is disabled. |
| DDSCAPS_NONLOCALVIDMEM | This surface exists in nonlocal display memory rather than true, local display memory. If this flag is specified, then DDSCAPS_VIDEOMEMORY flag must be specified as well. This cannot be used with the DDSCAPS_LOCALVIDMEM flag. |
| DDSCAPS_OFFSCREENPLAIN | This surface is any offscreen surface that is not an overlay, texture, z-buffer, front-buffer, back-buffer, or alpha surface. It is used to identify plain surfaces. |
| DDSCAPS_OVERLAY | This surface is an overlay. The visibility of this overlay depends on whether it is currently being overlaid onto the primary surface. DDSCAPS_VISIBLE can be used to determine whether it is being overlaid at the moment. |
| DDSCAPS_OPTIMIZED | This flag is not currently implemented. |
| DDSCAPS_OWNDC | This surface will have a device context (DC) association for a long period. If this capability bit is set by the Windows 2000 or later driver, DirectDraw will be disabled. |
| DDSCAPS_PALETTE | This device driver allows unique DirectDrawPalette objects to be created and attached to this surface. |
| DDSCAPS_PRIMARYSURFACE | This surface is the primary surface. It represents what is visible to the user at the moment. |
| DDSCAPS_PRIMARYSURFACELEFT | This surface is the primary surface for the left eye. It represents what is visible to the user's left eye at the moment. When this surface is created, the surface with the DDSCAPS_PRIMARYSURFACE capability represents what is seen by the user's right eye. |
| DDSCAPS_STANDARDVGAMODE | This surface is a standard VGA mode surface, and not a ModeX surface. This flag cannot be used in combination with the DDSCAPS_MODEX flag. |
| DDSCAPS_SYSTEMMEMORY | This surface memory was allocated from system memory. If this capability bit is set by the Windows 2000 or later driver, DirectDraw is disabled. |
| DDSCAPS_TEXTURE | This surface can be used as a 3D texture. It does not indicate whether the surface is being used for that purpose. |
| DDSCAPS_VIDEOMEMORY | This surface exists in display memory. |
| DDSCAPS_VIDEOPORT | This surface can receive data from a [*video port extensions (VPE)*](https://msdn.microsoft.com/library/ff556344(v=vs.85)) object. |
| DDSCAPS_VISIBLE | Changes made to this surface are immediately visible. It is always set for the primary surface, as well as for overlays while they are being overlaid and texture maps while they are being textured. |
| DDSCAPS_WRITEONLY | Only write access is permitted to the surface. Read access from the surface may generate a general protection fault (GPF), but the read results from this surface are not meaningful. If this capability bit is set by the Windows 2000 or later driver, DirectDraw is disabled. |
| DDSCAPS_ZBUFFER | This surface is the z-buffer. It contains bit-depth information that is used to determine which pixels are visible and which are obscured. The z-buffer contains information that cannot be displayed. |

## Remarks

This structure is used by the driver to report the types of surfaces the driver supports. It is also filled in by an application to specify the type of surface to be created.

## See also