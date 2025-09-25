# ICreateErrorInfo::SetHelpContext

## Description

Sets the Help context identifier (ID) for the error.

## Parameters

### `dwHelpContext` [in]

The Help context ID for the error.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

This method sets the Help context ID for the error. To establish the Help file to which it applies, use [ICreateErrorInfo::SetHelpFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-icreateerrorinfo-sethelpfile).

## See also

[ICreateErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreateerrorinfo)