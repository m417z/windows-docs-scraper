# IErrorInfo::GetDescription

## Description

  Returns a textual description of the error.

## Parameters

### `pBstrDescription` [out]

A brief description of the error.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The text is returned in the language specified by the locale identifier (LCID) that was passed to [IDispatch::Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke) for the method that encountered the error.

## See also

[IErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ierrorinfo)