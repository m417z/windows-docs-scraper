# ITextHost::TxGetExtent

## Description

Requests the native size of the control in HIMETRIC.

## Parameters

### `lpExtent`

Type: **LPSIZEL**

The size of the control in HIMETRIC, that is, where the unit is .01 millimeter.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Return S_OK if the method succeeds.

Return the following COM error code if the method fails. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | Not implemented. |

## Remarks

This method is used by the text services object to implement zooming. The text services object derives the zoom factor from the ratio between the himetric and device pixel extent of the client rectangle. Each HIMETRIC unit corresponds to 0.01 millimeter.

[vertical zoom factor] = [pixel height of the client rect] * 2540 / [HIMETRIC vertical extent] * [pixel per vertical inch (from device context)]

If the vertical and horizontal zoom factors are not the same, the text services object can ignore the horizontal zoom factor and assume it is the same as the vertical one.

## See also

**Conceptual**

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

**Other Resources**

[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)