# ITextHost::TxReleaseDC

## Description

Releases the device context obtained by the [ITextHost::TxGetDC](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-itexthost-txgetdc) method.

## Parameters

### `hdc` [in]

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the device context to release.

## Return value

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns 1 if *hdc* was released; otherwise 0.

For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

## Remarks

This method is only valid when the control is in-place active; calls while the control is inactive may fail.

## See also

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

[Windowless Rich Edit Controls Overview](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)