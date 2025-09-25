# SetWinMetaFileBits function

## Description

The **SetWinMetaFileBits** function converts a metafile from the older Windows format to the new enhanced format and stores the new metafile in memory.

## Parameters

### `nSize` [in]

The size, in bytes, of the buffer that contains the Windows-format metafile.

### `lpMeta16Data` [in]

A pointer to a buffer that contains the Windows-format metafile data. (It is assumed that the data was obtained by using the [GetMetaFileBitsEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getmetafilebitsex) or [GetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getwinmetafilebits) function.)

### `hdcRef` [in]

A handle to a reference device context.

### `lpMFP` [in]

A pointer to a [METAFILEPICT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-metafilepict) structure that contains the suggested size of the metafile picture and the mapping mode that was used when the picture was created.

## Return value

If the function succeeds, the return value is a handle to a memory-based enhanced metafile.

If the function fails, the return value is **NULL**.

## Remarks

Windows uses the reference device context's resolution data and the data in the [METAFILEPICT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-metafilepict) structure to scale a picture. If the *hdcRef* parameter is **NULL**, the system uses resolution data for the current output device. If the *lpmfp* parameter is **NULL**, the system uses the MM_ANISOTROPIC mapping mode to scale the picture so that it fits the entire device surface. The **hMF** member of the **METAFILEPICT** structure is not used.

When the application no longer needs the enhanced metafile handle, it should delete it by calling the [DeleteEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteenhmetafile) function.

The handle returned by this function can be used with other enhanced-metafile functions.

If the reference device context is not identical to the device in which the metafile was originally created, some GDI functions that use device units may not draw the picture correctly.

## See also

[DeleteEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteenhmetafile)

[GetMetaFileBitsEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getmetafilebitsex)

[GetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getwinmetafilebits)

[METAFILEPICT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-metafilepict)

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[PlayEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-playenhmetafile)