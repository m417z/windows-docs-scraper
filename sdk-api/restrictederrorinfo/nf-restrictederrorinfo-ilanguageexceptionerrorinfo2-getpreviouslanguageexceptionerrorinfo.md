# ILanguageExceptionErrorInfo2::GetPreviousLanguageExceptionErrorInfo

## Description

Retrieves the previous language exception error information object.

## Parameters

### `previousLanguageExceptionErrorInfo` [out]

Pointer to an [ILanguageExceptionErrorInfo2](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-ilanguageexceptionerrorinfo2) object that contains the previous error information object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Generally speaking, [GetPropagationContextHead](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nf-restrictederrorinfo-ilanguageexceptionerrorinfo2-getpropagationcontexthead) is utilized to retrieve the linked list of [IRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-irestrictederrorinfo) objects that contains additional error information on the exception in question. You can then use **GetPreviousLanguageExceptionErrorInfo** to move through that linked list, and examine each error separately.

The operating system also uses this method to retrieve the stored exceptions associated with the error.

## See also

[ILanguageExceptionErrorInfo2](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-ilanguageexceptionerrorinfo2)