# ITextFont::IsEqual

## Description

Determines whether this text font object has the same properties as the specified text font object.

## Parameters

### `pFont`

Type: **[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)***

The text font object to compare against.

### `pValue`

Type: **long***

A variable that is **tomTrue** if the font objects have the same properties or **tomFalse** if they do not. This parameter can be **NULL**.

## Return value

Type: **HRESULT**

If the text font objects have the same properties, the method succeeds and returns **S_OK**. If the text font objects do not have the same properties, the method fails and returns **S_FALSE**. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

## Remarks

The text font objects are equal only if *pFont* belongs to the same Text Object Model (TOM) object as the current font object. The **ITextFont::IsEqual** method ignores entries for which either font object has an [tomUndefined](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants).

## See also

**Conceptual**

[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)