# ICreateErrorInfo::SetHelpFile

## Description

Sets the path of the Help file that describes the error.

## Parameters

### `szHelpFile` [in]

The fully qualified path of the Help file that describes the error.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

This method sets the fully qualified path of the Help file that describes the current error. Use [ICreateErrorInfo::SetHelpContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-icreateerrorinfo-sethelpcontext) to set the Help context ID for the error in the Help file.

## See also

[ICreateErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreateerrorinfo)