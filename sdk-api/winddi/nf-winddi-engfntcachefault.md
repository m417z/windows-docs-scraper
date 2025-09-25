# EngFntCacheFault function

## Description

The **EngFntCacheFault** function reports an error to the font engine if the font driver encountered an error reading from or writing to a font data cache.

## Parameters

### `ulFastCheckSum` [in]

Specifies the checksum for the font.

### `iFaultMode` [in]

Specifies the type of error that occurred. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| ENG_FNT_CACHE_READ_FAULT | An error occurred during retrieval. |
| ENG_FNT_CACHE_WRITE_FAULT | An error occurred during storage. |

## Return value

None

## Remarks

If an error occurs while the font driver was reading from or writing to the font data cache, it should report the error to the font engine by a call to this function.

The font engine calls the font driver's [DrvLoadFontFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvloadfontfile) entry point when a font file is first loaded. It is in this call that the font driver receives a value for *ulFastCheckSum*, which it subsequently uses when it calls this function.

## See also

[DrvLoadFontFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvloadfontfile)

[EngFntCacheAlloc](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfntcachealloc)

[EngFntCacheLookUp](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engfntcachelookup)