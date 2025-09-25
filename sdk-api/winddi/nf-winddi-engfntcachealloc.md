# EngFntCacheAlloc function

## Description

The **EngFntCacheAlloc** function allocates storage for a font that is to be stored in cached memory.

## Parameters

### `FastCheckSum` [in]

Specifies the checksum for the font.

### `ulSize` [in]

Specifies the number of bytes of storage to allocate.

## Return value

On success, this function returns the address of the cache of font data. Otherwise, it returns **NULL**.

## Remarks

When the font driver calls this function, the font engine allocates memory in which the font driver stores font data.

The font engine calls the font driver's [DrvLoadFontFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvloadfontfile) entry point when a font file is first loaded. It is in this call that the font driver receives a value for *FastCheckSum*, which it subsequently uses when it calls this function.

## See also

[DrvLoadFontFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvloadfontfile)

[EngFntCacheFault](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfntcachefault)

[EngFntCacheLookUp](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfntcachelookup)