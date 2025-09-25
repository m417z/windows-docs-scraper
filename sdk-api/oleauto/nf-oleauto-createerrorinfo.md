# CreateErrorInfo function

## Description

Creates an instance of a generic error object.

## Parameters

### `pperrinfo` [out]

A system-implemented generic error object.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Could not create the error object. |

## Remarks

This function returns a pointer to a generic error object, which you can use with **QueryInterface** on [ICreateErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreateerrorinfo) to set its contents. You can then pass the resulting object to [SetErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-seterrorinfo). The generic error object implements both **ICreateErrorInfo** and [IErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ierrorinfo).

## See also

[Error-Handling API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/automat/error-handling-api-functions)