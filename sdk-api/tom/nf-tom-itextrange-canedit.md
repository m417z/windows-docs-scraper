# ITextRange::CanEdit

## Description

Determines whether the specified range can be edited.

## Parameters

### `pValue` [retval]

Type: **long***

A [tomBool](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model) value indicating whether the range can be edited. It is **tomTrue** only if the specified range can be edited. The pointer can be null.

## Return value

Type: **HRESULT**

If the range can be edited, the method succeeds and returns **S_OK**. If the range cannot be edited, the method fails and returns **S_FALSE**. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

## Remarks

The range cannot be edited if any part of it is protected or if the document is read-only.

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)