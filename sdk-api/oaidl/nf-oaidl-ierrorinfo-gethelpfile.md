# IErrorInfo::GetHelpFile

## Description

Returns the path of the Help file that describes the error.

## Parameters

### `pBstrHelpFile` [out]

The fully qualified path of the Help file.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method returns the fully qualified path of the Help file that describes the current error. [IErrorInfo::GetHelpContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-ierrorinfo-gethelpcontext) should be used to find the Help context ID for the error in the Help file.

## See also

[IErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ierrorinfo)