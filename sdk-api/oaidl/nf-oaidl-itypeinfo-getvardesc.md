# ITypeInfo::GetVarDesc

## Description

Retrieves a VARDESC structure that describes the specified variable.

## Parameters

### `index` [in]

The index of the variable whose description is to be returned. The index should be in the range of 0 to 1 less than the number of variables in this type.

### `ppVarDesc` [out]

A VARDESC that describes the specified variable.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

To free the VARDESC structure, use [ReleaseVarDesc](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-itypeinfo-releasevardesc).

#### Examples

In the following example, the CHECKRESULT function is undefined. Replace this function with your error handling code.

```cpp
CHECKRESULT(ptypeinfo->GetVarDesc(i, &pvardesc));
idMember = pvardesc->memid;
CHECKRESULT(ptypeinfo->GetDocumentation(idMember, &bstrName, NULL, NULL,
      NULL));
ptypeinfo->ReleaseVarDesc(pvardesc);

```

## See also

[ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo)