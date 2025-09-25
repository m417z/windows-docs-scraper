# ITextRange::GetChar

## Description

Gets the character at the start position of the range.

## Parameters

### `pChar`

Type: **long***

The start character position of the range.

## Return value

Type: **HRESULT**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If *pChar* is null, the method fails and it returns E_INVALIDARG.

## Remarks

The following Microsoft Visual Basic example sets *ch* equal to the character at the start of the range.

`ch = r.Char`

Similarly, [ITextRange::SetChar](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-setchar) overwrites the character at the start of the range with the specified character. The characters retrieved and set by these methods are **LONG** variables, which hide the way that they are stored in the backing store (as bytes, words, variable-length, and so forth), and they do not require using a **BSTR**.

The Char property, which can do most things that a characters collection can, has two big advantages:

* It can reference any character in the parent story instead of being limited to the parent range.
* It is significantly faster, since **LONG**s are involved instead of range objects.

Accordingly, the Text Object Model (TOM) does not support a characters collection.

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[SetChar](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-setchar)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)