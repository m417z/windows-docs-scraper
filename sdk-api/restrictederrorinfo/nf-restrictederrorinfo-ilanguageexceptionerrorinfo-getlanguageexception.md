# ILanguageExceptionErrorInfo::GetLanguageException

## Description

Gets the stored [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) object from the error object.

## Parameters

### `languageException` [out]

The stored [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) object from the error object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Language projections query for the appropriate interface to identify this object as generated from an exception to get the original object.

## See also

[ILanguageExceptionErrorInfo](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-ilanguageexceptionerrorinfo)