# IModelObject::GetRawReference

## Description

The GetRawReference method finds a native construct within the given object and returns a reference to it. Such a construct may be a field, a base class, a field in a base class, a member function, etc... It is important to distinguish the reference returned here (an object of the type ObjectTargetObjectReference) from a language reference (e.g.: a C++ & or && style reference).

## Parameters

### `kind`

Indicates the kind of native symbol to fetch (e.g.: a base class or a data member)

### `name`

The name of the native construct to fetch.

### `searchFlags`

An optional set of flags specifying the behavior of the search for the native construct.

### `object`

An [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) representing the fetched native construct will be returned here. Note that in some circumstances, extended error information may be returned in this argument even if the HRESULT indicates failure.

## Return value

This method returns HRESULT that indicates success or failure. The return values E_BOUNDS (or E_NOT_SET in some cases) indicates the field could not be found.

## Remarks

**Code Sample**

```cpp
ComPtr<IModelObject> spMessage; /* get a tagMSG */

ComPtr<IModelObject> spMsgIdRef;
if (SUCCEEDED(spMessage->GetRawReference(SymbolField, L"message", RawSearchNone, &spMsgIdRef)))
{
    // spMsgIdRef is an ObjectTargetObjectReference.  GetLocation/GetTypeInfo/GetTargetInfo
    // will return as they would for the value. spMsgIdRef can be passed to Dereference or to
    // the EE to assign a value, etc...
    ComPtr<IModelObject> spMsgId;
    if (SUCCEEDED(spMsgIdRef->Dereference(&spMsgId)))
    {
        // spMsgId contains the message number.  Unbox with GetIntrinsicValueAs.
    }
}
```

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)