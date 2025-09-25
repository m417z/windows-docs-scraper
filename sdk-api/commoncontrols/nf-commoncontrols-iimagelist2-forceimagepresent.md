# IImageList2::ForceImagePresent

## Description

Forces an image present, as specified.

## Parameters

### `iImage` [in]

Type: **int**

An index of image to force present.

### `dwFlags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Force image flags. One of the following is valid.

| Value | Meaning |
| --- | --- |
| **ILFIP_ALWAYS**<br><br>0x00000000 | Always get the image (can be slow). |
| **ILFIP_FROMSTANDBY**<br><br>0x00000001 | Only get if on standby. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.