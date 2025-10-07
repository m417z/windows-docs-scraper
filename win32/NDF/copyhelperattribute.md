# CopyHelperAttribute function

The **CopyHelperAttribute** function creates a copy of a [**HELPER\_ATTRIBUTE**](https://learn.microsoft.com/windows/win32/api/ndattrib/ns-ndattrib-helper_attribute) structure.

## Parameters

*Dest* \[out\]

Type: **[**HELPER\_ATTRIBUTE**](https://learn.microsoft.com/windows/win32/api/ndattrib/ns-ndattrib-helper_attribute)\***

The structure to be updated.

*Source* \[in\]

Type: **const [**HELPER\_ATTRIBUTE**](https://learn.microsoft.com/windows/win32/api/ndattrib/ns-ndattrib-helper_attribute)\***

The existing structure to be copied.

## Return value

Type: **HRESULT**

Possible return values include, but are not limited to, the following.

| Return code | Description |
|-----------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------|
| **S\_OK** | The operation succeeded.<br> |
| **E\_INVALIDARG** | One or more parameters has not been provided correctly.<br> |
| **E\_OUTOFMEMORY** | There is not enough memory available to complete this operation.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | Ndattributils.h |

## See also

[**HELPER\_ATTRIBUTE**](https://learn.microsoft.com/windows/win32/api/ndattrib/ns-ndattrib-helper_attribute)

