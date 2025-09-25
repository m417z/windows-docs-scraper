# ILCreateFromPathA function

## Description

Returns the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure associated with a specified file path.

## Parameters

### `pszPath` [in]

Type: **PCTSTR**

A pointer to a null-terminated Unicode string that contains the path. This string should be no more than MAX_PATH characters in length, including the terminating null character.

## Return value

Type: **PIDLIST_ABSOLUTE**

Returns a pointer to an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure that corresponds to the path.

## Remarks

Call [ILFree](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ilfree) to release the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) when you are finished with it.

> [!NOTE]
> The shlobj_core.h header defines ILCreateFromPath as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).