# IModelObject::GetRawValue

## Description

The GetRawValue method finds a native construct within the given object. Such a construct may be a field, a base class, a field in a base class, a member function, etc.

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

This method returns HRESULT that indicates success or failure.

## Remarks

The searchFlags argument is a set of bit flags specified by the RawSearchFlags enumeration. This enumeration presently defines the following values:

**RawSearchNone** - No special semantics to the search. Do the default search action for the target language being debugged.

**RawSearchNoBases** - Indicates that the search should not recurse to base children (e.g.: base classes). Only names/types which are in the object itself should be returned.

**Code Sample**

```cpp
ComPtr<IModelObject> spMessage; /* get a tagMSG */

// Get the 'message' field of the tagMSG structure:
ComPtr<IModelObject> spMsgId;
if (SUCCEEDED(spMessage->GetRawValue(SymbolField, L"message", RawSearchNone, &spMsgId)))
{
    // spMsgId contains the boxed form of the 'message' field of the tagMSG object.
}
```

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)