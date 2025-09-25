# DDCORECAPS structure

## Description

The DDCORECAPS structure specifies the core capabilities of the Microsoft DirectDraw driver and its device, which are exposed to an application through the DirectDraw object.

## Members

### `dwSize`

Specifies the size in bytes of this DDCORECAPS structure.

### `dwCaps`

Indicates a flag that specifies the driver's capabilities. The driver should set the appropriate DDCAPS_*Xxx* bit for every capability that it supports.

| Flag | Meaning |
| --- | --- |
| DDCAPS_3D | The display hardware has 3D acceleration. |
| DDCAPS_ALIGNBOUNDARYDEST | DirectDraw supports only those source rectangles with the x-axis aligned to the **dwAlignBoundaryDest** boundaries of the surface. |
| DDCAPS_ALIGNBOUNDARYSRC | DirectDraw supports only those source rectangles with the x-axis aligned to the **dwAlignBoundarySrc** boundaries of the surface. |
| DDCAPS_ALIGNSIZEDEST | DirectDraw supports only those source rectangles whose x-axis sizes, in bytes, are **dwAlignSizeDest** multiples. |
| DDCAPS_ALIGNSIZESRC | DirectDraw supports only those source rectangles whose x-axis sizes, in bytes, are **dwAlignSizeSrc** multiples. |
| DDCAPS_ALIGNSTRIDE | DirectDraw creates display memory surfaces that have a stride alignment equal to the **dwAlignStrideAlign** value. |
| DDCAPS_ALPHA | The display hardware supports an alpha channel during blit operations. |
| DDCAPS_BANKSWITCHED | The display hardware is bank-switched and is potentially very slow at random access to display memory. If this capability bit is set by the Microsoft Windows 2000 or later driver, DirectDraw is disabled. |
| DDCAPS_BLT | The display hardware is capable of blit operations. |
| DDCAPS_BLTCOLORFILL | The display hardware is capable of color filling with a blitter. |
| DDCAPS_BLTDEPTHFILL | The display hardware is capable of depth filling z-buffers with a blitter. |
| DDCAPS_BLTFOURCC | The display hardware is capable of color-space conversions during blit operations. |
| DDCAPS_BLTQUEUE | The display hardware is capable of asynchronous blit operations. |
| DDCAPS_BLTSTRETCH | The display hardware is capable of stretching during blit operations. |
| DDCAPS_CANBLTSYSMEM | The display hardware is capable of blitting to or from system memory. |
| DDCAPS_CANCLIP | The display hardware is capable of clipping with blitting. |
| DDCAPS_CANCLIPSTRETCHED | The display hardware is capable of clipping while stretch-blitting. |
| DDCAPS_COLORKEY | Some form of color key in either overlay or blit operations is supported. More specific color key capability information can be found in the **dwCKeyCaps** member. |
| DDCAPS_COLORKEYHWASSIST | The color key is hardware assisted. |
| DDCAPS_GDI | The display hardware is shared with GDI. If this capability bit is set by the Windows 2000 or later driver, DirectDraw is disabled. |
| DDCAPS_NOHARDWARE | No hardware support exists. |
| DDCAPS_OVERLAY | The display hardware supports overlays. |
| DDCAPS_OVERLAYCANTCLIP | The display hardware supports overlays but cannot clip them. |
| DDCAPS_OVERLAYFOURCC | The overlay hardware is capable of color-space conversions during overlay operations. |
| DDCAPS_OVERLAYSTRETCH | The overlay hardware is capable of stretching. |
| DDCAPS_PALETTE | DirectDraw is capable of creating and supporting DirectDrawPalette objects for more than just the primary surface. If this capability bit is set by the Windows 2000 or later driver, DirectDraw is disabled. |
| DDCAPS_PALETTEVSYNC | DirectDraw is capable of updating a palette synchronized with the vertical refresh. |
| DDCAPS_READSCANLINE | The display hardware is capable of returning the current scan line. |
| DDCAPS_STEREOVIEW | The display hardware has stereo vision capabilities. |
| DDCAPS_VBI | The display hardware is capable of generating a vertical-blank interrupt. |
| DDCAPS_ZBLTS | Supports the use of z-buffers with blit operations. |
| DDCAPS_ZOVERLAYS | Supports the use of the application's **UpdateOverlayZOrder** method as a z-value for overlays to control their layering. If this capability bit is set by the Windows 2000 or later driver, DirectDraw is disabled. |

### `dwCaps2`

Specify more of the driver's capabilities. The driver should set the appropriate DDCAPS2_*Xxx* bit for every capability that it supports.

| Flag | Meaning |
| --- | --- |
| DDCAPS2_AUTOFLIPOVERLAY | The overlay can be automatically flipped to the next surface in the flip chain each time a hardware video port V-sync occurs, allowing the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object and the overlay to double buffer the video without CPU overhead. This option is only valid when the surface is receiving data from hardware video port. If the hardware video port data is noninterlaced or noninterleaved, it flips on every V-sync. If the data is being interleaved in memory, it flips on every other V-sync. |
| DDCAPS2_CANAUTOGENMIPMAP | **DirectX 9.0 and later versions only.**<br><br>The driver and its device support automatically regenerating the sublevels of mipmap textures. |
| DDCAPS2_CANBOBHARDWARE | The overlay hardware can display each field of an interlaced video stream individually. |
| DDCAPS2_CANBOBINTERLEAVED | The overlay hardware can display each field of an interlaced video stream individually while it is interleaved in memory without causing any artifacts that might normally occur without special hardware support. This option is only valid when the surface is receiving data from a VPE object and is only valid when the video is zoomed at least 200 percent in the vertical direction. |
| DDCAPS2_CANBOBNONINTERLEAVED | The overlay hardware can display each field of an interlaced video stream individually while it is not interleaved in memory without causing any artifacts that might normally occur without special hardware support. This option is only valid when the surface is receiving data from a VPE object and is only valid when the video is zoomed at least 200 percent in the vertical direction. |
| DDCAPS2_CANCALIBRATEGAMMA | A calibrator is available to adjust the gamma ramp according to the physical display properties so that the result is identical on all calibrated systems. |
| DDCAPS2_CANDROPZ16BIT | Sixteen-bit RGBZ values can be converted into 16-bit RGB values. (The system does not support eight-bit conversions.) |
| DDCAPS2_CANFLIPODDEVEN | The driver supports bob using software without using a VPE object. |
| DDCAPS2_CANMANAGERESOURCE | The driver supports managing resources. |
| DDCAPS2_CANMANAGETEXTURE | The driver supports managing textures. |
| DDCAPS2_CANRENDERWINDOWED | The driver can render in windowed mode. |
| DDCAPS2_CERTIFIED | The display hardware is certified. |
| DDCAPS2_COLORCONTROLOVERLAY | The overlay surface contains color controls (brightness, sharpness, and so on). |
| DDCAPS2_COLORCONTROLPRIMARY | The primary surface contains color controls (gamma, and so on). |
| DDCAPS2_COPYFOURCC | The driver supports blitting any [FOURCC](https://learn.microsoft.com/windows-hardware/drivers/) surface to another surface of the same FOURCC. |
| DDCAPS2_FLIPINTERVAL | The driver responds to the DDFLIP_INTERVAL2, DDFLIP_INTERVAL3, and DDFLIP_INTERVAL4 flags. |
| DDCAPS2_FLIPNOVSYNC | The driver responds to DDFLIP_FLIPNOVSYNC. |
| DDCAPS2_NO2DDURING3DSCENE | The driver cannot interleave 2D operations such as [DdBlt](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_blt) or [DdLock](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_lock) on any surfaces that Microsoft Direct3D is using between calls to the **IDirect3DDevice::BeginScene** and **IDirect3DDevice::EndScene** methods. |
| DDCAPS2_NONLOCALVIDMEM | The driver supports nonlocal display memory. |
| DDCAPS2_NONLOCALVIDMEMCAPS | Blit capabilities for nonlocal display memory surfaces differ from local display memory surfaces. If this flag is present, the DDCAPS2_NONLOCALVIDMEM flag is also present. |
| DDCAPS2_NOPAGELOCKREQUIRED | The driver should be called for blits involving system memory surfaces even if the system memory surfaces are not pagelocked. |
| DDCAPS2_PRIMARYGAMMA | The driver supports loadable gamma ramps for the primary surface. |
| DDCAPS2_VIDEOPORT | The display hardware contains a hardware video port. |
| DDCAPS2_WIDESURFACES | The display driver can create surfaces wider than the primary surface. Drivers that set this bit should expect to receive **CreateSurface** requests from applications for surfaces wider than the primary surface. |

### `dwCKeyCaps`

Specify the color key capabilities of surfaces. The driver should set the appropriate DDCKEYCAPS_*Xxx* bit for every capability that it supports.

| Flag | Meaning |
| --- | --- |
| DDCKEYCAPS_DESTBLT | Supports transparent blitting with a color key that identifies the replaceable bits of the destination surface for RGB colors. |
| DDCKEYCAPS_DESTBLTCLRSPACE | Supports transparent blitting with a color space that identifies the replaceable bits of the destination surface for RGB colors. |
| DDCKEYCAPS_DESTBLTCLRSPACEYUV | Supports transparent blitting with a color space that identifies the replaceable bits of the destination surface for YUV colors. |
| DDCKEYCAPS_DESTBLTYUV | Supports transparent blitting with a color key that identifies the replaceable bits of the destination surface for YUV colors. |
| DDCKEYCAPS_DESTOVERLAY | Supports overlaying with color keying of the replaceable bits of the destination surface being overlaid for RGB colors. |
| DDCKEYCAPS_DESTOVERLAYCLRSPACE | Supports a color space as the color key for the destination of RGB colors. |
| DDCKEYCAPS_DESTOVERLAYCLRSPACEYUV | Supports a color space as the color key for the destination of YUV colors. |
| DDCKEYCAPS_DESTOVERLAYONEACTIVE | Supports only one active destination color key value for visible overlay surfaces. |
| DDCKEYCAPS_DESTOVERLAYYUV | Supports overlaying using color keying of the replaceable bits of the destination surface being overlaid for YUV colors. |
| DDCKEYCAPS_NOCOSTOVERLAY | Indicates that there are no bandwidth tradeoffs for using the color key with an overlay. |
| DDCKEYCAPS_SRCBLT | Supports transparent blitting using the color key for the source with this surface for RGB colors. |
| DDCKEYCAPS_SRCBLTCLRSPACE | Supports transparent blitting using a color space for the source with this surface for RGB colors. |
| DDCKEYCAPS_SRCBLTCLRSPACEYUV | Supports transparent blitting using a color space for the source with this surface for YUV colors. |
| DDCKEYCAPS_SRCBLTYUV | Supports transparent blitting using the color key for the source with this surface for YUV colors. |
| DDCKEYCAPS_SRCOVERLAY | Supports overlaying using the color key for the source with this overlay surface for RGB colors. |
| DDCKEYCAPS_SRCOVERLAYCLRSPACE | Supports overlaying using a color space as the source color key for the overlay surface for RGB colors. |
| DDCKEYCAPS_SRCOVERLAYCLRSPACEYUV | Supports overlaying using a color space as the source color key for the overlay surface for YUV colors. |
| DDCKEYCAPS_SRCOVERLAYONEACTIVE | Supports only one active source color key value for visible overlay surfaces. |
| DDCKEYCAPS_SRCOVERLAYYUV | Supports overlaying using the color key for the source with this overlay surface for YUV colors. |

### `dwFXCaps`

Specify the driver's stretching and effects capabilities. The driver should set the appropriate DDFXCAPS_*Xxx* bit for every capability that it supports.

| Flag | Meaning |
| --- | --- |
| DDFXCAPS_BLTARITHSTRETCHY | Uses arithmetic operations, rather than pixel-doubling techniques, to stretch and shrink surfaces during a blit operation. Occurs along the y-axis (vertically). |
| DDFXCAPS_BLTARITHSTRETCHYN | Uses arithmetic operations, rather than pixel-doubling techniques, to stretch and shrink surfaces during a blit operation. Occurs along the y-axis (vertically), and works only for integer stretching (x1, x2, and so on). |
| DDFXCAPS_BLTMIRRORLEFTRIGHT | Supports mirroring left to right in a blit operation. |
| DDFXCAPS_BLTMIRRORUPDOWN | Supports mirroring top to bottom in a blit operation. |
| DDFXCAPS_BLTROTATION | Supports arbitrary rotation in a blit operation. If this capability bit is set by the Windows 2000 or later driver, DirectDraw is disabled. |
| DDFXCAPS_BLTROTATION90 | Supports 90-degree rotations in a blit operation. If this capability bit is set by the Windows 2000 or later driver, DirectDraw is disabled. |
| DDFXCAPS_BLTSHRINKX | Supports arbitrary shrinking of a surface along the x-axis (horizontally). This flag is valid only for blit operations. |
| DDFXCAPS_BLTSHRINKXN | Supports integer shrinking (x1, x2, and so on) of a surface along the x-axis (horizontally). This flag is valid only for blit operations. |
| DDFXCAPS_BLTSHRINKY | Supports arbitrary shrinking of a surface along the y-axis (vertically). This flag is valid only for blit operations. |
| DDFXCAPS_BLTSHRINKYN | Supports integer shrinking (x1, x2, and so on) of a surface along the y-axis (vertically). This flag is valid only for blit operations. |
| DDFXCAPS_BLTSTRETCHX | Supports arbitrary stretching of a surface along the x-axis (horizontally). This flag is valid only for blit operations. |
| DDFXCAPS_BLTSTRETCHXN | Supports integer stretching (x1, x2, and so on) of a surface along the x-axis (horizontally). This flag is valid only for blit operations. |
| DDFXCAPS_BLTSTRETCHY | Supports arbitrary stretching of a surface along the y-axis (vertically). This flag is valid only for blit operations. |
| DDFXCAPS_BLTSTRETCHYN | Supports integer stretching (x1, x2, and so on) of a surface along the y-axis (vertically). This flag is valid only for blit operations. |
| DDFXCAPS_OVERLAYARITHSTRETCHY | Uses arithmetic operations, rather than pixel-doubling techniques, to stretch and shrink surfaces during an overlay operation. Occurs along the y-axis (vertically). |
| DDFXCAPS_OVERLAYARITHSTRETCHYN | Uses arithmetic operations, rather than pixel-doubling techniques, to stretch and shrink surfaces during an overlay operation. Occurs along the y-axis (vertically), and works only for integer stretching (x1, x2, and so on). |
| DDFXCAPS_OVERLAYMIRRORLEFTRIGHT | Supports mirroring of overlays around the vertical axis. |
| DDFXCAPS_OVERLAYMIRRORUPDOWN | Supports mirroring of overlays across the horizontal axis. |
| DDFXCAPS_OVERLAYSHRINKX | Supports arbitrary shrinking of a surface along the x-axis (horizontally). This flag is valid only for DDSCAPS_OVERLAY surfaces. This flag indicates only the capabilities of a surface; it does not indicate that shrinking is available. |
| DDFXCAPS_OVERLAYSHRINKXN | Supports integer shrinking (x1, x2, and so on) of a surface along the x-axis (horizontally). This flag is valid only for DDSCAPS_OVERLAY surfaces. This flag indicates only the capabilities of a surface; it does not indicate that shrinking is available. |
| DDFXCAPS_OVERLAYSHRINKY | Supports arbitrary shrinking of a surface along the y-axis (vertically). This flag is valid only for DDSCAPS_OVERLAY surfaces. This flag indicates only the capabilities of a surface; it does not indicate that shrinking is available. |
| DDFXCAPS_OVERLAYSHRINKYN | Supports integer shrinking (x1, x2, and so on) of a surface along the y-axis (vertically). This flag is valid only for DDSCAPS_OVERLAY surfaces. This flag indicates only the capabilities of a surface; it does not indicate that shrinking is available. |
| DDFXCAPS_OVERLAYSTRETCHX | Supports arbitrary stretching of a surface along the x-axis (horizontally). This flag is valid only for DDSCAPS_OVERLAY surfaces. This flag indicates only the capabilities of a surface; it does not indicate that stretching is available. |
| DDFXCAPS_OVERLAYSTRETCHXN | Supports integer stretching (x1, x2, and so on) of a surface along the x-axis (horizontally). This flag is valid only for DDSCAPS_OVERLAY surfaces. This flag indicates only the capabilities of a surface; it does not indicate that stretching is available. |
| DDFXCAPS_OVERLAYSTRETCHY | Supports arbitrary stretching of a surface along the y-axis (vertically). This flag is valid only for DDSCAPS_OVERLAY surfaces. This flag indicates only the capabilities of a surface; it does not indicate that stretching is available. |
| DDFXCAPS_OVERLAYSTRETCHYN | Supports integer stretching (x1, x2, and so on) of a surface along the y-axis (vertically). This flag is valid only for DDSCAPS_OVERLAY surfaces. This flag indicates only the capabilities of a surface; it does not indicate that stretching is available. |

### `dwFXAlphaCaps`

This member and its flags are obsolete and should not be used by the driver.

### `dwPalCaps`

Specify the driver's palette capabilities. The driver should set the appropriate DDPCAPS_*Xxx* bit for every capability that it supports. The DDPCAPS_*Xxx* flags are defined in *ddraw.h*. The DirectDraw runtime currently ignores these capabilities.

### `dwSVCaps`

Specify the driver's stereo vision capabilities. The driver should set the appropriate DDSVCAPS_*Xxx* bit for every capability that it supports.

| Flag | Meaning |
| --- | --- |
| DDSVCAPS_ENIGMA | The stereo view is accomplished using Enigma encoding. |
| DDSVCAPS_FLICKER | The stereo view is accomplished using high-frequency flickering. |
| DDSVCAPS_REDBLUE | The stereo view is accomplished when the viewer looks at the image through red and blue filters placed over the left and right eyes. All images must adapt their color spaces for this process. |
| DDSVCAPS_SPLIT | The stereo view is accomplished with split-screen technology. |

### `dwAlphaBltConstBitDepths`

Reserved for system use. The driver should ignore this member.

### `dwAlphaBltPixelBitDepths`

Reserved for system use. The driver should ignore this member.

### `dwAlphaBltSurfaceBitDepths`

Reserved for system use. The driver should ignore this member.

### `dwAlphaOverlayConstBitDepths`

Reserved for system use. The driver should ignore this member.

### `dwAlphaOverlayPixelBitDepths`

Reserved for system use. The driver should ignore this member.

### `dwAlphaOverlaySurfaceBitDepths`

Reserved for system use. The driver should ignore this member.

### `dwZBufferBitDepths`

Indicates a flag that specifies the Z buffer depths supported by the driver. This can be one or more of the following values:

| Flag | Meaning |
| --- | --- |
| DDBD_8 | The driver supports an 8bpp depth buffer. |
| DDBD_16 | The driver supports a 16bpp depth buffer. |
| DDBD_24 | The driver supports a 24bpp depth buffer. |
| DDBD_32 | The driver supports a 32bpp depth buffer. |

### `dwVidMemTotal`

Specifies the total amount of display memory, in bytes.

### `dwVidMemFree`

Specifies the number of bytes of free display memory. The driver sets this member once during initialization to the same value it returns in the **dwVidMemTotal** member. DirectDraw updates it every time the application does a memory allocation.

### `dwMaxVisibleOverlays`

Specifies the maximum number of visible overlays.

### `dwCurrVisibleOverlays`

Specifies the current number of visible overlays.

### `dwNumFourCCCodes`

Specifies the number of [FOURCC](https://learn.microsoft.com/windows-hardware/drivers/) codes that the driver supports.

### `dwAlignBoundarySrc`

Specifies the source rectangle alignment. This member can be optionally set by the driver. If the driver sets this member, then the overlay source rectangle's top left coordinate value must be a multiple of **dwAlignBoundarySrc**.

### `dwAlignSizeSrc`

Specifies the size of the source rectangle, in bytes. This member can be optionally set by the driver. If the driver sets this member, then the overlay source rectangle's width must be a multiple of **dwAlignSizeSrc**.

### `dwAlignBoundaryDest`

Specifies the destination rectangle alignment. This member can be optionally set by the driver. If the driver sets this member, then the overlay destination rectangle's top left coordinate value must be a multiple of **dwAlignBoundaryDest**.

### `dwAlignSizeDest`

Specifies the destination rectangle byte size. This member can be optionally set by the driver. If the driver sets this member, then the overlay destination rectangle's width must be a multiple of **dwAlignSizeDest**.

### `dwAlignStrideAlign`

Reserved for system use and should be ignored by the driver.

### `dwRops`

Specifies an array of DD_ROP_SPACE DWORDs that together can hold flags to indicate the ROPs that the driver supports. The driver should set the bitfield for every corresponding ROP that it supports. See the Microsoft Windows SDK documentation for information about ROPs.

### `ddsCaps`

Specifies a [DDSCAPS](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550286(v=vs.85)) structure that describes the types of surfaces the driver supports.

### `dwMinOverlayStretch`

Specifies the minimum overlay stretch factor multiplied by 1000. For example, a factor of 1.3 should be stored as 1300. The display driver must set the minimum factor to the actual minimum to which the graphics hardware can shrink the overlay. If the graphics hardware has no minimum limitation, set to 1.

### `dwMaxOverlayStretch`

Specifies the maximum overlay stretch factor multiplied by 1000. For example, a factor of 1.3 should be stored as 1300. The display driver must set the maximum factor to the actual maximum to which the graphics hardware can stretch the overlay. If the graphics hardware has no maximum limitation, set to 32000.

### `dwMinLiveVideoStretch`

Specifies the minimum live video stretch factor multiplied by 1000. For example, a factor of 1.3 should be stored as 1300.

### `dwMaxLiveVideoStretch`

Specifies the maximum live video stretch factor multiplied by 1000. For example, a factor of 1.3 should be stored as 1300.

### `dwMinHwCodecStretch`

Specifies the minimum hardware codec stretch factor multiplied by 1000. For example, a factor of 1.3 should be stored as 1300.

### `dwMaxHwCodecStretch`

Specifies the maximum hardware codec stretch factor multiplied by 1000. For example, a factor of 1.3 should be stored as 1300.

### `dwReserved1`

Reserved for system use. The driver should ignore this member.

### `dwReserved2`

Reserved for system use. The driver should ignore this member.

### `dwReserved3`

Reserved for system use. The driver should ignore this member.

### `dwSVBCaps`

Indicates a set of flags that specify the driver-specific capabilities for system-memory-to-display-memory blits. The driver should bitwise OR the appropriate DDCAPS_*Xxx* flags (see the **dwCaps** member) to indicate the types of blit operations it supports when blitting from system memory to display memory.

### `dwSVBCKeyCaps`

Indicates a set of flags that specify driver color-key capabilities for system-memory-to-display-memory blits. The driver should bitwise OR the appropriate DDCKEYCAPS_*Xxx* flags (see the **dwCKeyCaps** member) to indicate the types of color key operations it supports when blitting from system memory to display memory.

### `dwSVBFXCaps`

Indicates a set of flags that specify driver FX capabilities for system-memory-to-display-memory blits. The driver should bitwise OR the appropriate DDFXCAPS_*Xxx* flags (see the **dwFXCaps** member) to indicate the types of effects it supports when blitting from system memory to display memory.

### `dwSVBRops`

Specifies an array of DD_ROP_SPACE DWORDs that together can hold flags to indicate the ROPs that the driver supports when performing system-memory-to-display-memory blits. The driver should set the bitfield for every corresponding ROP that it supports. See the Microsoft Windows SDK documentation for information about ROPs.

### `dwVSBCaps`

Indicates a set of flags that specify driver-specific capabilities for display-memory-to-system-memory blits. The driver should bitwise OR the appropriate DDCAPS_*Xxx* flags (see the **dwCaps** member) to indicate the types of blit operations it supports when blitting from display memory to system memory.

### `dwVSBCKeyCaps`

Indicates a set of flags that specify driver color-key capabilities for display-memory-to-system-memory blits. The driver should bitwise OR the appropriate DDCKEYCAPS_*Xxx* flags (see the **dwCKeyCaps** member) to indicate the types of color key operations it supports when blitting from display memory to system memory.

### `dwVSBFXCaps`

Indicates a set of flags that specify driver FX capabilities for display-memory-to-system-memory blits. The driver should bitwise OR the appropriate DDFXCAPS_*Xxx* flags (see the **dwFXCaps** member) to indicate the types of effects it supports when blitting from display memory to system memory.

### `dwVSBRops`

Specifies an array of DD_ROP_SPACE DWORDs that together can hold flags to indicate the ROPs that the driver supports when performing display-memory-to-system-memory blits. The driver should set the bitfield for every corresponding ROP that it supports. See the Windows SDK documentation for information about ROPs.

### `dwSSBCaps`

Indicates a set of flags that specify driver-specific capabilities for system-memory-to-system-memory blits. The driver should bitwise OR the appropriate DDCAPS_*Xxx* flags (see the **dwCaps** member) to indicate the types of blit operations it supports when blitting from system memory to system memory.

### `dwSSBCKeyCaps`

Indicates a set of flags that specify driver color-key capabilities for system-memory-to-system-memory blits. The driver should bitwise OR the appropriate DDCKEYCAPS_*Xxx* flags (see the **dwCKeyCaps** member) to indicate the types of color key operations it supports when blitting from system memory to system memory.

### `dwSSBFXCaps`

Indicates a set of flags that specify driver FX capabilities for system-memory-to-system-memory blits. The driver should bitwise OR the appropriate DDFXCAPS_*Xxx* flags (see the **dwFXCaps** member) to indicate the types of effects it supports when blitting from system memory to system memory.

### `dwSSBRops`

Specifies an array of DD_ROP_SPACE DWORDs that together can hold flags to indicate the ROPs that the driver supports when performing system-memory-to-system-memory blits. The driver should set the bitfield for every corresponding ROP that it supports. See the Windows SDK documentation for information about ROPs.

### `dwMaxVideoPorts`

Specifies the maximum number of usable VPE objects.

### `dwCurrVideoPorts`

Specifies the current number of VPE objects used. The driver does not need to fill in this member because it is set by DirectDraw.

### `dwSVBCaps2`

Specifies additional driver-specific capabilities for system-memory-to-display-memory blits. Valid flags are identical to the blit-related flags used with the **dwCaps2** member.

## Remarks

This section contains the DirectDraw driver structure whose name has the form DDCORECAPS, which is the form used on Windows 98/Me. This structure is identical to that whose name has the form DDNTCORECAPS which is the form used on Windows 2000 and later versions. The include file *dx95type.h* contains a type define from DDNTCORECAPS to DDCORECAPS.

This structure mirrors the first entries of the DDCAPS structure, but is of a fixed size and does not grow as DDCAPS does.

The driver initializes DDCORECAPS when it is initializing the other members of the [DD_HALINFO](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_halinfo) structure in its [DrvGetDirectDrawInfo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvgetdirectdrawinfo) structure. The DirectDraw runtime might update some members.

DirectDraw requests additional driver capabilities by calling the [DdGetDriverInfo](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverinfo) function that is also returned in the DD_HALINFO structure.