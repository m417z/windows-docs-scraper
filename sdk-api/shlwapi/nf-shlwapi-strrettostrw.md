# StrRetToStrW function

## Description

Takes an [STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret) structure returned by [IShellFolder::GetDisplayNameOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getdisplaynameof) and returns a pointer to an allocated string containing the display name.

## Parameters

### `pstr` [in, out]

Type: **[STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret)***

A pointer to the [STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret) structure. When the function returns, this pointer will no longer be valid.

### `pidl` [in, optional]

Type: **PCUITEMID_CHILD**

A pointer to the item's [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure. This value can be **NULL**.

### `ppsz` [out]

Type: **LPTSTR***

A pointer to an allocated string containing the result. **StrRetToStr** allocates memory for this string with [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc). You should free the string with [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) when it is no longer needed.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[StrRetToBuf](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strrettobufa)

## Remarks

> [!NOTE]
> The shlwapi.h header defines StrRetToStr as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).