# ITextStoryRanges::_NewEnum

## Description

Retrieves an
**IEnumVARIANT** enumerator interface for this collection of stories.

## Parameters

### `ppunkEnum`

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)****

The pointer to the enumerator interface.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | *ppunkEnum* is null. |
| **E_FAIL** | Failure for some other reason. |

## Remarks

This definition together with the implementation of
**IEnumVARIANT**, enables one to support the following Microsoft Visual Basic for Applications (VBA) code.

```
    Dim t As ITextDocument
    Dim c As ITextStoryRanges
    Dim r As ITextRange

    Set t = gObj
    Set c = t.StoryRanges

    For Each r In c
        Debug.Print r.Text
    Next
```

## See also

**Conceptual**

[ITextStoryRanges](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstoryranges)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)