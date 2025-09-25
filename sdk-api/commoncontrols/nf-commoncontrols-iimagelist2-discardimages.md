# IImageList2::DiscardImages

## Description

Discards images from list, as specified.

## Parameters

### `iFirstImage` [in]

Type: **int**

An index of first image to discard.

### `iLastImage` [in]

Type: **int**

An index of last image to discard.

### `dwFlags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Discard images flags. **ILDI_STANDBY** and **ILDI_PURGE** are mutually exclusive. **ILDI_RESETACCESS** can be combined with either. One or more of the following are valid.

| Value | Meaning |
| --- | --- |
| **ILDI_PURGE**<br><br>0x00000001 | Discard and purge. |
| **ILDI_STANDBY**<br><br>0x00000002 | Discard to standby list. |
| **ILDI_RESETACCESS**<br><br>0x00000004 | Reset the "has been accessed" flag. |
| **ILDI_QUERYACCESS**<br><br>0x00000008 | Ask whether access flag is set (but do not reset). |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.