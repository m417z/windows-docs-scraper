# ScriptFreeCache function

## Description

Frees a script cache.

## Parameters

### `psc` [in, out]

Pointer to the [SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache) structure.

## Return value

Returns 0 if successful. The function returns a nonzero HRESULT value if it does not succeed. The application cant test the return value with the **SUCCEEDED** and **FAILED** macros.

## Remarks

An application can free the script cache at any time, with certain limitations if the application is multi-threaded. Uniscribe maintains reference counts in its [font and shaper caches](https://learn.microsoft.com/windows/desktop/Intl/caching) and frees font data only when all sizes of the font are free. It frees shaper data only when all supported fonts are freed.

The application should free the script cache for a style when it discards that style.

**ScriptFreeCache** always sets its parameter to **NULL** to help avoid misreferencing.

Uniscribe functions are re-entrant. Cache creation is interlocked through a single process-wide semaphore. **ScriptFreeCache** should not be called at a time when another thread might be accessing the particular cache to free. For performance reasons, the cache is not locked during [ScriptShape](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptshape) or [ScriptPlace](https://learn.microsoft.com/windows/desktop/api/usp10/nf-usp10-scriptplace).

**Important** Starting with Windows 8: To maintain the ability to run on Windows 7, a module that uses Uniscribe must specify Usp10.lib before gdi32.lib in its library list.

## See also

[Caching](https://learn.microsoft.com/windows/desktop/Intl/caching)

[SCRIPT_CACHE](https://learn.microsoft.com/windows/desktop/Intl/script-cache)

[Uniscribe](https://learn.microsoft.com/windows/desktop/Intl/uniscribe)

[Uniscribe Functions](https://learn.microsoft.com/windows/desktop/Intl/uniscribe-functions)