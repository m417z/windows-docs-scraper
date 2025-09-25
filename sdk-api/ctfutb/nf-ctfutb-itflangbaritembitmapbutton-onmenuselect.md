# ITfLangBarItemBitmapButton::OnMenuSelect

## Description

This method is not used if the button item does not have the TF_LBI_STYLE_BTN_MENU style.

## Parameters

### `wID` [in]

Specifies the identifier of the menu item selected. This is the value passed for *uId* in [ITfMenu::AddMenuItem](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itfmenu-addmenuitem).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ITfLangBarItemBitmapButton](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritembitmapbutton)

[ITfMenu::AddMenuItem](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itfmenu-addmenuitem)