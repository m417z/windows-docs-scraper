# ITextPara::IsEqual

## Description

Determines if the current range has the same properties as a specified range.

## Parameters

### `pPara`

Type: **[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)***

The [ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara) range that is compared to the current range.

### `pValue`

Type: **long***

The comparison result. The value can be null.

## Return value

Type: **HRESULT**

If the objects are equal, **ITextPara::IsEqual** succeeds and returns **S_OK**. If the objects are not equal, the method fails and returns S_FALSE. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

## See also

**Conceptual**

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)