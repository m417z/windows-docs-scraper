# ImageList\_SetColorTable function

Sets the color table for an image list.

## Parameters

*himl* \[in\]

Type: **HIMAGELIST**

A handle to the image list.

*start* \[in\]

Type: **int**

A zero-based color table index that specifies the first color table entry to set.

*len* \[in\]

Type: **int**

The number of color table entries to set.

*prgb* \[in\]

Type: **[**RGBQUAD**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-rgbquad)\***

A pointer to an array of *len* [**RGBQUAD**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-rgbquad) structures containing new color information for the color table of the DIB.

## Return value

Type: **int**

If the function succeeds, it returns the number of color table entries set by the function. If the function fails, the return value is less than or equal to zero.

## Remarks

Only image lists created with the [**ILC\_COLOR4**](https://learn.microsoft.com/windows/desktop/api/Commctrl/nf-commctrl-imagelist_create) or [**ILC\_COLOR8**](https://learn.microsoft.com/windows/desktop/api/Commctrl/nf-commctrl-imagelist_create) flag have color tables. The color table of such an image list is typically set automatically by copying the color table of the first image added to the list (for example, through the [**ImageList\_Add**](https://learn.microsoft.com/windows/desktop/api/Commctrl/nf-commctrl-imagelist_add) function) if that image is a DIB. If the first image added to the image list is not a DIB, then the color table of the halftone palette is used for **ILC\_COLOR8** image lists and the VGA color table is used for **ILC\_COLOR4**.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Comctl32.dll (version 3.51 or later) |

## See also

[Color Table](https://msdn.microsoft.com/library/ms531197(v=VS.85).aspx)

