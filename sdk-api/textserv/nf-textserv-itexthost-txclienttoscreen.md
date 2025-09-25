# ITextHost::TxClientToScreen

## Description

Converts text host coordinates to screen coordinates.

## Parameters

### `lppt` [in]

Type: **LPPOINT**

The client coordinates to convert.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Return **TRUE** if the method succeeds.

Return **FALSE** if the method fails.

## Remarks

This call is valid at any time, although it is allowed to fail. In general, if the text services object needs to translate from client coordinates (for example, for the TOM [GetPoint](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-getpoint) method) the text services object is visible.

However, if no conversion is possible, then the method fails.

## See also

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

[Windowless Rich Edit Controls Overview](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)