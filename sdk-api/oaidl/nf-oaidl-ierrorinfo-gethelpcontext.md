# IErrorInfo::GetHelpContext

## Description

Returns the Help context identifier (ID) for the error.

## Parameters

### `pdwHelpContext` [out]

The Help context ID for the error.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method returns the Help context ID for the error. To find the Help file to which it applies, use [IErrorInfo::GetHelpFile](https://learn.microsoft.com/windows/desktop/api/oaidl/nf-oaidl-ierrorinfo-gethelpfile).

## See also

[IErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ierrorinfo)