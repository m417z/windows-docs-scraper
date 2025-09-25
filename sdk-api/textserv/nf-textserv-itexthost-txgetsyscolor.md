# ITextHost::TxGetSysColor

## Description

Retrieves the text host's color for a specified display element.

## Parameters

### `nIndex` [in]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The display element whose color is to be retrieved. For a list of possible values for this parameter, see the [GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor) function.

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The value that identifies the red, green, and blue (RGB) color value of the specified element.

## Remarks

Note that the color returned may be
*different* than the color that would be returned from a call to [GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor). This is the case if the host overrides the default system behavior.

**Note** Hosts should be careful about overriding normal system behavior because it can result in inconsistent UI (particularly with respect to Accessibility options).

## See also

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

[Windowless Rich Edit Controls Overview](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)