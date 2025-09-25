# ITextHost::TxGetClientRect

## Description

Retrieves the client coordinates of the text host's client area.

## Parameters

### `prc`

Type: **LPRECT**

The client coordinates of the text host's client area.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Return S_OK if the method succeeds.

Return the following COM error code if the method fails. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_FAIL** | Unspecified error. |

## Remarks

The client rectangle is the rectangle that the text services object is responsible for painting and managing. The host relies on the text services object for painting that area. And, the text services object must not paint or invalidate areas outside of that rectangle.

The host forwards mouse messages to the text services object when the cursor is over the client rectangle.

The client rectangle is expressed in client coordinates of the containing window.

**Important** The **ITextHost::TxGetClientRect** method will fail if called at an inactive time.

## See also

**Conceptual**

[ITextHost](https://learn.microsoft.com/windows/desktop/api/textserv/nl-textserv-itexthost)

**Other Resources**

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[Windowless Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)