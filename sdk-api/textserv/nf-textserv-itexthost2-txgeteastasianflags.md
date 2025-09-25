# ITextHost2::TxGetEastAsianFlags

## Description

Gets whether Input Method Editor (IME) input is allowed and whether the edit styles include [ES_SELFIME](https://learn.microsoft.com/windows/desktop/Controls/rich-edit-control-styles).

## Parameters

### `pFlags`

Type: **LONG***

The East Asian flags.

| Value | Meaning |
| --- | --- |
| **[ES_NOIME](https://learn.microsoft.com/windows/desktop/Controls/rich-edit-control-styles)** | IME input is suppressed. |
| **[ES_SELFIME](https://learn.microsoft.com/windows/desktop/Controls/rich-edit-control-styles)** | The rich edit client handles IME input. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextHost2](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost2)