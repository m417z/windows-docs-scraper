# ITextStoryRanges::Item

## Description

Retrieves an [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange) object for the
*Index*th story in this story collection.

## Parameters

### `Index`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of story range that is retrieved. The default value is 1, which indicates the first story in the collection. *Count*, given by [ITextStoryRanges::GetCount](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextstoryranges-getcount), indicates the last story in the collection. If *Index* is less than zero, the stories are counted from last to first, with -1 being the index of the last story in the collection, and
*Index* = - *Count* indicating the first story in the collection.

### `ppRange`

Type: **[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)****

The [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange) object.

## Return value

Type: **HRESULT**

The method returns an
**HRESULT** value. If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | ppRange is null or Index is out of range. |
| **E_FAIL** | Failure for some other reason. |

## See also

**Conceptual**

[GetCount](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextstoryranges-getcount)

[ITextStoryRanges](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextstoryranges)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)