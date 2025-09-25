# ITfLangBarItemButton::GetIcon

## Description

Obtains the icon to be displayed for the language bar button.

## Parameters

### `phIcon` [out]

Pointer to an **HICON** value that receives the icon handle. Receives **NULL** if the button has no icon. The caller must free this icon when it is no longer required by calling **DestroyIcon**.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *phIcon* is invalid. |

## Remarks

The ideal size of the icon can be obtained by calling GetSystemMetrics(SM_CXSMICON) for the icon width and GetSystemMetrics(SM_CYSMICON) for the icon height.

If the button has the TF_LBI_STYLE_TEXTCOLORICON style, the icon obtained by this method should be a monochrome icon.