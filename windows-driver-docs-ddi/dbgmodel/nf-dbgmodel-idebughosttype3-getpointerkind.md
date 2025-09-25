## Description

For types which are pointers, the GetPointerKind method returns the kind of pointer. This is defined by the PointerKind enumeration and is one of the following values:

|Enumerant | Meaning|
|----------|---------|
|PointerStandard | Indicates a standard C/C++ pointer -- a *|
|PointerReference | Indicates a C/C++ reference (whether const or not) -- a &|
|PointerRValueReference | Indicates a C/C++ rvalue reference (whether const or not) -- a &&|
|PointerCXHat | Indicates a C++/CX hat managed pointer (whether const or not) -- a ^|

## Parameters

### `pointerKind`

The kind of pointer will be returned here as a value from the PointerKind enumeration.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostType> spType; /* get a type for something that's a pointer
                                  or reference (see FindTypeByName) */

PointerKind pk;
if (SUCCEEDED(spType->GetPointerKind(&pk)))
{
    // pk indicates the kind of pointer:
    //      PointerStandard (it's a '*')
    //      PointerReference (it's a '&')
    //      etc...
}
```

## See also

[IDebugHostType3 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype3)