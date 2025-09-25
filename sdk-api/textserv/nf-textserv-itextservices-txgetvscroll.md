# ITextServices::TxGetVScroll

## Description

Returns vertical scroll bar state information.

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

The height of view in pixels.

### `pfEnabled`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Indicates whether the vertical scroll bar is enabled. If **TRUE**, the vertical scroll bar is enabled; otherwise it is disabled.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, the return value is **S_OK**.

If the method fails, the return value is one of the following **HRESULT** codes. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_FAIL** | Unspecified error. |
| **E_INVALIDARG** | One or more arguments are not valid. |

## See also

[ITextServices](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itextservices)

[Windowless Rich Edit Controls Overview](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)