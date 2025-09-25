# ILanguageExceptionErrorInfo2::GetPropagationContextHead

## Description

Retrieves the propagation context head.

## Parameters

### `propagatedLanguageExceptionErrorInfoHead` [out]

On success, returns an [ILanguageExceptionErrorInfo2](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-ilanguageexceptionerrorinfo2) object that represents the head of the propagation context.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You can use **GetPropagationContextHead** to retrieve the linked list of [IRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-irestrictederrorinfo) objects that contains additional error information on the exception in question. You can then use [GetPreviousLanguageExceptionErrorInfo](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nf-restrictederrorinfo-ilanguageexceptionerrorinfo2-getpreviouslanguageexceptionerrorinfo) to move through that linked list, and examine each error separately.

 The operating system also uses this method to retrieve the stored exceptions associated with the error.

## See also

[ILanguageExceptionErrorInfo2](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-ilanguageexceptionerrorinfo2)