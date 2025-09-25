# IErrorInfo::GetSource

## Description

Returns the language-dependent programmatic ID (ProgID) for the class or application that raised the error.

## Parameters

### `pBstrSource` [out]

A ProgID, in the form *progname*.*objectname*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Use **IErrorInfo::GetSource** to determine the class or application that is the source of the error. The language for the returned ProgID depends on the locale ID (LCID) that was passed into the method at the time of invocation.

## See also

[IErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ierrorinfo)