# SHSTOCKICONINFO structure

## Description

Receives information used to retrieve a stock Shell icon. This structure is used in a call [SHGetStockIconInfo](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shgetstockiconinfo).

## Members

### `cbSize`

Type: **DWORD**

The size of this structure, in bytes.

### `hIcon`

Type: **HICON**

When [SHGetStockIconInfo](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shgetstockiconinfo) is called with the SHGSI_ICON flag, this member receives a handle to the icon.

### `iSysImageIndex`

Type: **int**

When [SHGetStockIconInfo](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shgetstockiconinfo) is called with the SHGSI_SYSICONINDEX flag, this member receives the index of the image in the system icon cache.

### `iIcon`

Type: **int**

When [SHGetStockIconInfo](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shgetstockiconinfo) is called with the SHGSI_ICONLOCATION flag, this member receives the index of the icon in the resource whose path is received in **szPath**.

### `szPath`

Type: **WCHAR[MAX_PATH]**

When [SHGetStockIconInfo](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shgetstockiconinfo) is called with the SHGSI_ICONLOCATION flag, this member receives the path of the resource that contains the icon. The index of the icon within the resource is received in **iIcon**.

## See also

[SHGetStockIconInfo](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shgetstockiconinfo)