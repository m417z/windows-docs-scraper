# ITfLangBarItemBalloon::GetPreferredSize

## Description

Obtains the preferred size,in pixels, of the balloon.

## Parameters

### `pszDefault` [in]

Pointer to a [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure that contains the default size, in pixels, of the balloon.

### `psz` [out]

Pointer to a **SIZE** structure that receives the preferred balloon size, in pixels. The **cy** member of this structure is ignored.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This method is required. The balloon must supply the preferred size in response to this method.

To obtain the font used to draw the balloon, call [GetStockObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getstockobject) with DEFAULT_GUI_FONT. This font can be used to calculate the preferred balloon size at runtime.

If the balloon text will not fit into the preferred size obtained from this method, the language bar truncates the text and adds an ellipses to the text.

## See also

[GetStockObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getstockobject)

[ITfLangBarItemBalloon](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritemballoon)

[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)