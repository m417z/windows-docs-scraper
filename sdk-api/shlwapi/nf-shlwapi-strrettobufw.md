# StrRetToBufW function

## Description

Converts an [STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret) structure returned by [IShellFolder::GetDisplayNameOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getdisplaynameof) to a string, and places the result in a buffer.

## Parameters

### `pstr` [in, out]

Type: **[STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret)***

A pointer to the [STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret) structure. When the function returns, this pointer will no longer be valid.

### `pidl` [in]

Type: **PCUITEMID_CHILD**

A pointer to the item's [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure.

### `pszBuf` [out]

Type: **LPTSTR**

A buffer to hold the display name. It will be returned as a null-terminated string. If *cchBuf* is too small, the name will be truncated to fit.

### `cchBuf` [in]

Type: **UINT**

The size of *pszBuf*, in characters. If *cchBuf* is too small, the string will be truncated to fit.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the **uType** member of the structure pointed to by *pstr* is set to **STRRET_WSTR**, the **pOleStr** member of that structure will be freed on return.

> [!NOTE]
> The shlwapi.h header defines StrRetToBuf as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[StrRetToStr](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strrettostra)

[StrRetToStrN](https://learn.microsoft.com/windows/desktop/shell/consts-enums-flags)