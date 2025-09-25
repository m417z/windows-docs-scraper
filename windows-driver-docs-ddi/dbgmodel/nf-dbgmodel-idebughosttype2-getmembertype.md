# IDebugHostType2::GetMemberType

## Description

For types which are pointer-to-member (as indicated by a type kind of TypeMemberPointer), the GetMemberType method returns the class the pointer is a pointer-to-member of.

## Parameters

### `memberType`

The class that the pointer is a pointer-to-member of will be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostModule> spModule; /* find some module */

ComPtr<IDebugHostType2> spType;
if (SUCCEEDED(spModule->FindTypeByName(L"int (MyClass::*)(int)", &spType)))
{
    // spType is a pointer-to-(MyClass)-member function taking int and returning int.
    ComPtr<IDebugHostType> spMemberType;
    if (SUCCEEDED(spType->GetMemberType(&spMemberType)))
    {
        // spMemberType is a type symbol for MyClass
    }
}
```

## See also

[IDebugHostType2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype2)