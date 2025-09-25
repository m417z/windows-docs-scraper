# ITextFont::CanChange

## Description

Determines whether the font can be changed.

## Parameters

### `pValue` [retval]

Type: **long***

A variable that is **tomTrue** if the font can be changed or **tomFalse** if it cannot be changed. This parameter can be **NULL**.

## Return value

Type: **HRESULT**

If the font can change, the method returns **S_OK**. If the method fails, it returns the following COM error code. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **S_FALSE** | The font cannot change. |

## Remarks

The **pbCanChange* returns **tomTrue** only if the font can be changed. That is, no part of an associated range is protected and an associated document is not read-only. If this [ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont) object is a duplicate, no protection rules apply.

## See also

**Conceptual**

[ITextFont](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextfont)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)