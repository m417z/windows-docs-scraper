# ITfLangBarItemBitmapButton::GetPreferredSize

## Description

Obtains the preferred size, in pixels, of the bitmap.

## Parameters

### `pszDefault` [in]

Pointer to a [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure that contains the default size, in pixels, of the bitmap.

### `psz` [out]

Pointer to a SIZE structure that receives the preferred size, in pixels, of the bitmap. The **cy** member of this structure is ignored.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The results of this method are not currently used. The bitmap for a bitmap button item should not be larger than the size of a small icon. Obtain these dimensions by calling [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics) with SM_CXSMICON for the width and SM_CYSMICON for the height.

## See also

[GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics)

[ITfLangBarItemBitmapButton](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritembitmapbutton)

[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)