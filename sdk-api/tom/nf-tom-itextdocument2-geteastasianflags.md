# ITextDocument2::GetEastAsianFlags

## Description

Gets the East Asian flags.

## Parameters

### `pFlags` [out, retval]

Type: **long***

The East Asian flags. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **tomRE10Mode** | TOM version 1.0 emulation mode. |
| **tomUseAtFont** | Use @ fonts for CJK vertical text. |
| **tomTextFlowMask** | A mask for the following four text orientations:<br><br>**tomTextFlowES**<br><br>Ordinary left-to-right horizontal text.<br><br>**tomTextFlowSW**<br><br>Ordinary East Asian vertical text.<br><br>**tomTextFlowWN**<br><br>An alternative orientation.<br><br>**tomTextFlowNE**<br><br>An alternative orientation. |
| **tomUsePassword** | Use password control. |
| **tomNoIME** | Turn off IME operation (see [ES_NOIME](https://learn.microsoft.com/windows/desktop/Controls/rich-edit-control-styles)). |
| **tomSelfIME** | The rich edit host handles IME operation (see [ES_SELFIME](https://learn.microsoft.com/windows/desktop/Controls/rich-edit-control-styles)) . |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)