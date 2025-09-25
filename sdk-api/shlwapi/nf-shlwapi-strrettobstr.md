# StrRetToBSTR function

## Description

Accepts a [STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret) structure returned by [IShellFolder::GetDisplayNameOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getdisplaynameof) that contains or points to a string, and returns that string as a [BSTR](https://learn.microsoft.com/previous-versions/windows/desktop/automat/bstr).

## Parameters

### `pstr` [in, out]

Type: **[STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret)***

A pointer to a [STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret) structure. When the function returns, this pointer is longer valid.

### `pidl` [in]

Type: **PCUITEMID_CHILD**

A pointer to an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) that uniquely identifies a file object or subfolder relative to the parent folder. This value can be **NULL**.

### `pbstr` [out]

Type: **[BSTR](https://learn.microsoft.com/previous-versions/windows/desktop/automat/bstr)***

A pointer to a variable of type [BSTR](https://learn.microsoft.com/previous-versions/windows/desktop/automat/bstr) that receives the converted string.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the *uType* member of the [STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret) structure pointed to by *pstr* is set to **STRRET_WSTR**, the *pOleStr* member of that structure is freed on return.

## See also

[IShellFolder::GetDisplayNameOf](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getdisplaynameof)

[StrRetToBuf](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strrettobufa)

[StrRetToStr](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strrettostra)