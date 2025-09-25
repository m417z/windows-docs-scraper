# EngFindImageProcAddress macro

## Description

The **EngFindImageProcAddress** function returns the address of a function within an executable module.

## Parameters

### `h`

Handle to the image in which the function can be found. This handle was obtained by calling [EngLoadImage](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadimage). This parameter can be **NULL** on Windows NT 4.0 SP3 and later versions, which includes Windows 2000 and later operating system versions.

### `procname` [in]

Pointer to the string that specifies the name of the function to be located.

## Remarks

A driver must previously have loaded the image into kernel-mode through a call to [EngLoadImage](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadimage).

The function identified by *lpProcName* must be exported by the loaded module. This is accomplished by using the EXPORTS key in the module's *.DEF* file.

A driver cannot call **EngFindImageProcAddress** with *hModule* set to **NULL** on any version of Windows NT 4.0 prior to SP3. Consequently, the driver must do version checking to ensure that the system is running that version or Windows 2000 or later. Specifically, if the *iEngineVersion* value passed to the driver's [DrvEnableDriver](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenabledriver) function is greater than or equal to DDI_DRIVER_VERSION_SP3, the driver can call **EngFindImageProcAddress** with a **NULL** value for *hModule*.

To obtain the address of a GDI service routine that is new to Windows 2000 and later operating system versions, the driver can call **EngFindImageProcAddress** with the function's string name and *hModule* set to **NULL**. The *lpProcName* parameter can be the text string equivalent of any of the following functions when *hModule* is **NULL**:

|  |  |
| --- | --- |
| **BRUSHOBJ_hGetColorTransform** | **EngAlphaBlend** |
| **EngClearEvent** | **EngControlSprites** |
| **EngCreateEvent** | **EngDeleteEvent** |
| **EngDeleteFile** | **EngDeleteSafeSemaphore** |
| **EngDeleteWnd** | **EngDitherColor** |
| **EngGetPrinterDriver** | **EngGradientFill** |
| **EngHangNotification** | **EngInitializeSafeSemaphore** |
| **EngLockDirectDrawSurface** | **EngLpkInstalled** |
| **EngMapEvent** | **EngMapFile** |
| **EngMapFontFileFD** | **EngModifySurface** |
| **EngMovePointer** | **EngPlgBlt** |
| **EngQueryDeviceAttribute** | **EngQueryPalette** |
| **EngQuerySystemAttribute** | **EngReadStateEvent** |
| **EngRestoreFloatingPointState** | **EngSaveFloatingPointState** |
| **EngSetEvent** | **EngSetPointerShape** |
| **EngSetPointerTag** | **EngStretchBltROP** |
| **EngTransparentBlt** | **EngUnlockDirectDrawSurface** |
| **EngUnmapEvent** | **EngUnmapFile** |
| **EngUnmapFontFileFD** | **EngWaitForSingleObject** |
| **FONTOBJ_pfdg** | **FONTOBJ_pjOpenTypeTablePointer** |
| **FONTOBJ_pQueryGlyphAttrs** | **FONTOBJ_pwszFontFilePaths** |
| **HeapVidMemAllocAligned** | **HT_Get8BPPMaskPalette** |
| **STROBJ_bEnumPositionsOnly** | **STROBJ_bGetAdvanceWidths** |
| **STROBJ_fxBreakExtra** | **STROBJ_fxCharacterExtra** |
| **VidMemFree** | **XLATEOBJ_hGetColorTransform** |

## See also

[DrvEnableDriver](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenabledriver)

[EngLoadImage](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engloadimage)