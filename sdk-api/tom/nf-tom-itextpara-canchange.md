# ITextPara::CanChange

## Description

Determines whether the paragraph formatting can be changed.

## Parameters

### `pValue` [retval]

Type: **long***

A variable that is **tomTrue** if the paragraph formatting can be changed or **tomFalse** if it cannot be changed. This parameter can be null.

## Return value

Type: **HRESULT**

If paragraph formatting can change, **ITextPara::CanChange** succeeds and returns **S_OK**. If paragraph formatting cannot change, the method fails and returns S_FALSE. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

## Remarks

The **pbCanChange* parameter returns **tomTrue** only if the paragraph formatting can be changed (that is, if no part of an associated range is protected and an associated document is not read-only). If this [ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara) object is a duplicate, no protection rules apply.

## See also

**Conceptual**

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)