# DrvLoadFontFile function

## Description

The **DrvLoadFontFile** function receives information from GDI relating to loading and mapping font files.

## Parameters

### `cFiles`

Caller-supplied value indicating the number of files associated with the font.

### `piFile`

Caller-supplied pointer to a *cFiles*-sized array of file handles. Each handle represents one of the files associated with the font. The file handles can be passed individually to [EngMapFontFileFD](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapfontfilefd).

### `ppvView`

Caller-supplied pointer to a *cFiles*-sized array containing the starting address of the memory space into which each font file has been mapped.

### `pcjView`

Caller-supplied pointer to a *cFiles*-sized array containing the size of the memory space into which each font file has been mapped.

### `pdv`

For Adobe Multiple Master fonts, this is a caller-supplied pointer to a DESIGNVECTOR structure (described in the Microsoft Windows SDK documentation) identifying the Multiple Master instance. Otherwise, this parameter is **NULL**.

### `ulLangID`

Caller-supplied language identifier, obtained from the registry.

### `ulFastCheckSum`

Specifies a GDI-supplied checksum for the font. If this parameter is nonzero, the GDI font cache engine can be used in order to access a font more quickly. If this parameter is zero, the GDI font engine cannot be used.

## Return value

If the operation succeeds, it should return a pointer to a driver-defined value that uniquely identifies the font. The driver subsequently receives this pointer as an input parameter to such functions as [DrvQueryFont](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvqueryfont), [DrvQueryFontFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvqueryfontfile), [DrvQueryFontTree](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvqueryfonttree). If an error is encountered, the function should return HFF_INVALID.

## Remarks

Font drivers are required to supply a **DrvLoadFontFile** function. The function's purpose is to allow a font driver to receive notification that a font's associated files are being loaded and mapped. The driver can store input arguments for later use.

Loading and mapping a font file entails calling [EngMapFontFileFD](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapfontfilefd). When an application calls **AddFontResource** or AddFontResourceEx (described in the Windows SDK documentation), GDI calls **EngMapFontFileFD** and then calls **DrvLoadFontFile**. The **DrvLoadFontFile** function's *ppvView* and *pcjView* parameters supply the location and size of each file's mapping, as returned by **EngMapFontFileFD**.

GDI unmaps the files when **DrvLoadFontFile** returns. If the driver needs to remap the files later, in response to subsequent calls from GDI, it can call [EngMapFontFileFD](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapfontfilefd) itself if it has saved the *cFiles* and *piFile* parameters.

When the GDI font engine calls the font driver's **DrvLoadFontFile** DDI, it passes a checksum for the font in the *ulFastCheckSum* parameter. If this parameter is nonzero and the font in question has been cached, **DrvLoadFontFile** can obtain a pointer to the font data with a call to [EngFntCacheLookUp](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfntcachelookup). After the font driver obtains the pointer to the font data, it can then load the font data. If the font has not been cached, the font driver can cache the font by first allocating memory for the font cache, using a call to [EngFntCacheAlloc](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfntcachealloc), and then writing the font data to that memory. If the font driver encounters an error reading or writing the font data, it can notify the GDI font engine by making a call to [EngFntCacheFault](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfntcachefault).

If the GDI font engine called **DrvLoadFontFile** and passed in a value of zero for the *ulFastCheckSum* parameter, this means that the GDI font engine is not in operation, and the font driver does not need to take any action.

## See also

[DrvUnloadFontFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvunloadfontfile)

[EngFntCacheAlloc](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfntcachealloc)

[EngFntCacheFault](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfntcachefault)

[EngFntCacheLookUp](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfntcachelookup)