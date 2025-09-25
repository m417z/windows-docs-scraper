# ITextServices::TxGetCurTargetX

## Description

Gets the target x position, that is, the current horizontal position of the caret.

## Parameters

#### - px

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The target x location in client coordinates.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the x position of the caret is returned, the return value is **S_OK**.

If the method fails, the return value is the following **HRESULT** code. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_FAIL** | There is no selection. |
| **E_INVALIDARG** | The input argument is invalid. |

## Remarks

Together with [ITextServices::OnTxSetCursor](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-ontxsetcursor), this method allows you to maintain the horizontal caret position when moving the caret up and down. This capability is useful when moving the caret through forms.

The target caret position is expressed as an x-coordinate on the display because other controls do not necessarily share the same attributes for column position.

## See also

**Conceptual**

[ITextServices](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itextservices)

[OnTxSetCursor](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itextservices-ontxsetcursor)

**Reference**

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)