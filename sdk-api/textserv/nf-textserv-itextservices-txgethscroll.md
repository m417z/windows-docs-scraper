# ITextServices::TxGetHScroll

## Description

Returns horizontal scroll bar information.

## Parameters

### `plMin`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The minimum scroll position.

### `plMax`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The maximum scroll position.

### `plPos`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The current scroll position.

### `plPage`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The view width, in pixels.

### `pfEnabled`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Indicates whether horizontal scrolling is enabled. If **TRUE**, horizontal scrolling is enabled.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The method always returns **S_OK**.

## See also

[ITextServices](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itextservices)

[Windowless Rich Edit Controls Overview](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)