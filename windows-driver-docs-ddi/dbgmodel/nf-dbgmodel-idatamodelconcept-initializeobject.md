# IDataModelConcept::InitializeObject

## Description

A data model can be registered as the canonical visualizer or as an extension for a given native type through the data model manager's RegisterModelForTypeSignature or RegisterExtensionForTypeSignature methods. When a model is registered via either of these methods, the data model is automatically attached as a parent model to any native object whose type matches the signature passed in the registration. At the point where that attachment is automatically made, the InitializeObject method is called on the data model. It is passed the instance object, the type signature which caused the attachment, and an enumerator which produces the type instances (in linear order) which matched any wildcards in the type signature. The data model implementation may use this method call to initialize any caches it requires.

## Parameters

### `modelObject`

The instance object which is being initialized.

### `matchingTypeSignature`

The type signature against which the native type of modelObject matched that caused the attachment of the data model.

### `wildcardMatches`

If the matching type signature includes wildcards, this argument will contain an enumerator which will enumerate how each wildcard matched. Typically, each [IDebugHostSymbol](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostsymbol) enumerated here is an [IDebugHostType](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype). That is, not, however a requirement. Non-type template arguments (amongst other things) can match wildcards and may produce symbols such as [IDebugHostConstant](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostconstant).

## Return value

This method returns HRESULT that indicates success or failure. Failing this method will prevent object construction of the instance.

## Remarks

Note that a given data model implementation cannot assume that the InitializeObject call will be made for every object to which the data model is attached. As the data model is a completely dynamic system, it is entirely possible for a caller to directly acquire a model (via, for example, the GetParentModel method on [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)) and attach it manually. In such a circumstance, the InitializeObject call will not have been made and the implementation must be prepared to do such. The calling of this method is an optimization to allow expensive implementations to prefill and preinitialize requisite caches.

**Implementation Example**

Note that a client will never call this interface.

```cpp
//
// InitializeObject is an implementation of the interface method on some
// class representing a data model.  Consider that the class has a GetObject() method
// which returns the IModelObject for the data model
//
// Let's also imagine that this registered for the type signature "std::vector<*>"
//
IFACEMETHOD(InitializeObject)(_In_ IModelObject *pContextObject, _In_ IDebugHostTypeSignature *pTypeSignature, _In_ IDebugHostSymbolEnumerator *pWildcardMatches)
{
    HRESULT hr = S_OK;

    // The minimal implementation is "return S_OK;"
    // Typically, this is used to fill cache information.  Imagine we have a
    // cache in the context data.
    ComPtr<IUnknown> spCtxData;
    hr = pContextObject->GetContextForDataModel(GetObject(), &spCtxData));
    if (SUCCEEDED(hr))
    {
        CacheData *pCacheData = static_cast<CacheData *>(spCtxData.Get());

        // Find the instance type.  This is the template argument(s) which
        // matched the * in 'std::vector<*>'
        ComPtr<IDebugHostSymbol> spFirstMatch;
        hr = pWildcardMatches->GetNext(&spFirstMatch));
        if (SUCCEEDED(hr))
        {
            SymnbolKind sk;
            ComPtr<IDebugHostType> spFirstType;
            if (SUCCEEDED(hr = spFirstMatch->GetSymbolKind(&sk)) && sk == SymbolType &&
                SUCCEEDED(hr = spFirstMatch.As(&spFirstType))))
            {
                pCacheData->SetInstanceType(spFirstType.Get()));
            }
        }
    }

    return hr;
}
```

## See also

[IDataModelConcept interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelconcept)