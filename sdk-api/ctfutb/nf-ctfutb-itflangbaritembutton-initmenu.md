# ITfLangBarItemButton::InitMenu

## Description

This method is not used if the button item does not have the TF_LBI_STYLE_BTN_MENU style.

## Parameters

### `pMenu` [in]

Pointer to an [ITfMenu](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itfmenu) interface that the language bar button uses to add items to the menu that the language bar displays for the button.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ITfLangBarItemButton](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritembutton)

[ITfMenu](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itfmenu)