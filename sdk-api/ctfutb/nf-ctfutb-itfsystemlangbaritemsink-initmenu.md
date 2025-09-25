# ITfSystemLangBarItemSink::InitMenu

## Description

Called to allow a system language bar item extension to add items to a system language bar menu.

## Parameters

### `pMenu` [in]

Pointer to an [ITfMenu](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itfmenu) interface that the system language bar item uses to add items to the system language bar menu.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ITfMenu](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itfmenu)

[ITfSystemLangBarItemSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itfsystemlangbaritemsink)