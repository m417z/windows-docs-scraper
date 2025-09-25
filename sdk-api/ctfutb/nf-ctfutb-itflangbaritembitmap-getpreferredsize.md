# ITfLangBarItemBitmap::GetPreferredSize

## Description

Obtains the preferred size, in pixels, of the bitmap.

## Parameters

### `pszDefault` [in]

Pointer to a [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure that contains the default size, in pixels, of the bitmap.

### `psz` [out]

Pointer to a **SIZE** structure that receives the preferred size, in pixels, of the bitmap. The **cy** member of this structure is ignored.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## See also

[ITfLangBarItemBitmap](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritembitmap)

[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)