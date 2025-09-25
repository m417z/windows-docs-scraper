# ITfSystemLangBarItemSink::OnMenuSelect

## Description

Called when the user selects an item in the system menu added by the system language bar menu extension.

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

[ITfMenu::AddMenuItem](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itfmenu-addmenuitem)

[ITfSystemLangBarItemSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itfsystemlangbaritemsink)