# IDebugHostSymbols::GetMostDerivedObject

## Description

The GetMostDerivedObject will use the type system of the debugger to determine the runtime type of an object from its static type. This method will only use symbolic information and heuristics available at the type system layer in order to perform this analysis. Such information may include C++ RTTI (run time type information) or analysis of the shape of the virtual function tables of the object. It does not include things such as the preferred runtime type concept on an [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject).

If the analysis cannot find a runtime type or cannot find a runtime type different from the static type passed into the method, the input location and type may be passed out. The method will not fail for these reasons.

## Parameters

### `pContext`

The context in which the given location is valid. If this value is not specified, the context will be assumed to be identical to the context given by objectType.

### `location`

The location of the statically typed object within the address space given by either the pContext argument or the objectType argument.

### `objectType`

The static type of the object at the given location.

### `derivedLocation`

The location of the runtime typed object within the address space given by either the pContext argument or the objectType argument. This may or may not be the same as the location given by the location argument.

### `derivedType`

The runtime type of the object will be returned here. This may or may not be the same as the type passed in the objectType argument.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHost> spHost;           /* get the host */
ComPtr<IDebugHostType> spStaticType; /* get the static (compile time) type of
                                     some object (see IModelObject::GetTargetInfo) */
Location staticLocation;             /* get the static location of some object
                                        (see IModelObject::GetTargetInfo) */

ComPtr<IDebugHostSymbols> spSym;
if (SUCCEEDED(spHost.As(&spSym)))
{
    ComPtr<IDebugHostType> spRuntimeType;
    Location runtimeLocation;
    if (SUCCEEDED(spSym->GetMostDerivedObject(USE_CURRENT_HOST_CONTEXT,
                                              spStaticType.Get(),
                                              staticLocation,
                                              &spRuntimeType,
                                              &runtimeLocation)))
    {
        // spRuntimeType contains the runtime type of the object as
        // determined from type system means (e.g.: RTTI or v-table analysis)
        // runtimeLocation contains the location of the runtime type of the object
    }
}
```

## See also

[IDebugHostSymbols interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostsymbols)