# IImageList2::GetOriginalSize

## Description

Gets the original size of a specified image.

## Parameters

### `iImage` [in]

Type: **int**

The index of desired image.

### `dwFlags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags for getting original size. One of the following is valid.

| Value | Meaning |
| --- | --- |
| **ILGOS_ALWAYS**<br><br>0x00000000 | Always get the original size (can be slow). |
| **ILGOS_FROMSTANDBY**<br><br>0x00000001 | Only get if present or on standby. |

### `pcx` [out]

Type: **int***

A pointer to the x-axis count.

### `pcy` [out]

Type: **int***

A pointer to the y-axis count.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.