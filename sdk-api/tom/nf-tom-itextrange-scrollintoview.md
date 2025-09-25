# ITextRange::ScrollIntoView

## Description

Scrolls the specified range into view.

## Parameters

### `Value`

Type: **long**

Flag specifying the end to scroll into view. It can be one of the following.

| Value | Meaning |
| --- | --- |
| **[tomEnd](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | Scrolls the end character position to appear on the bottom line. |
| **[tomStart](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** | Scrolls the start character position to appear on the top line. (Default value). |
| **[tomNoUpScroll](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** |  |
| **[tomNoVpScroll](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants)** |  |

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns S_FALSE.

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)