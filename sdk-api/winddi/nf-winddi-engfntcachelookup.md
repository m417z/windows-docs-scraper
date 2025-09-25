# EngFntCacheLookUp function

## Description

The **EngFntCacheLookUp** function retrieves the address of cached font file data.

## Parameters

### `FastCheckSum` [in]

Specifies the checksum for the font.

### `pulSize` [out]

Pointer to a memory location that receives the size, in bytes, of the data.

## Return value

On success, this function returns a pointer to the cached data. Otherwise, it returns **NULL**.

## Remarks

The font engine calls the font driver's [DrvLoadFontFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvloadfontfile) entry point when a font file is first loaded. It is in this call that the font driver receives a value for *FastCheckSum*, which it subsequently uses when it calls this function.

## See also

[DrvLoadFontFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvloadfontfile)

[EngFntCacheAlloc](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfntcachealloc)

[EngFntCacheFault](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfntcachefault)