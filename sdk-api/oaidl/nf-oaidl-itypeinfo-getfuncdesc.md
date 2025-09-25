# ITypeInfo::GetFuncDesc

## Description

Retrieves the [FUNCDESC](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-funcdesc) structure that contains information about a specified function.

## Parameters

### `index` [in]

The index of the function whose description is to be returned. The *index* should be in the range of 0 to 1 less than the number of functions in this type.

### `ppFuncDesc` [out]

A FUNCDESC structure that describes the specified function.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

The function **ITypeInfo::GetFuncDesc** provides access to a FUNCDESC structure that describes the function with the specified *index*. The FUNCDESC structure should be freed with [ITypeInfo::ReleaseFuncDesc](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-itypeinfo-releasefuncdesc). The number of functions in the type is one of the attributes contained in the TYPEATTR structure.

#### Examples

In the following example, the CHECKRESULT function is undefined. Replace this function with your error handling code.

```cpp
CHECKRESULT(ptypeinfo->GetFuncDesc(i, &pfuncdesc));
idMember = pfuncdesc->memid;
CHECKRESULT(ptypeinfo->GetDocumentation(idMember, &bstrName, NULL, NULL, NULL));
ptypeinfo->ReleaseFuncDesc(pfuncdesc);

```

## See also

[ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo)