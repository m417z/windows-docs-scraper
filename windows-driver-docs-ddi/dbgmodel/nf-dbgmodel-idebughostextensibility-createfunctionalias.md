# IDebugHostExtensibility::CreateFunctionAlias

## Description

The CreateFunctionAlias method creates a "function alias", a "quick alias" for a method implemented in some extension. The meaning of this alias is host specific. It may extend the host's expression evaluator with the function or it may do something entirely different.

For Debugging Tools for Windows, a function alias:

- Is accessible in the expression evaluator through the @$ symbol. A function alias registered under someName is callable in the evaluator via @$someName(...).

- Can be invoked via the older bang syntax. The invocation "!someName arg1, arg2, ..." is semantically equivalent to running the (dx) expression evaluator with "@$someName(arg1, arg2, ...)" and displaying the result.

## Parameters

### `aliasName`

The (quick) name of the alias being created/registered.

### `functionObject`

A data model method (an [IModelMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelmethod) boxed into an [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)) which implements the functionality of the function alias.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

**Sample Code**

```cpp
class MySumFunction:
    public Microsoft::WRL::RuntimeClass<
        Microsoft::WRL::RuntimeClassFlags<
            Microsoft::WRL::RuntimeClassType::ClassicCom
            >,
        IModelMethod
        >
{
public:

    IFACEMETHOD(Call)(_In_ IModelObject * /*pContextObject*/,
                      _In_ ULONG64 argCount,
                      _In_reads_(argCount) IModelObject **ppArguments,
                      _COM_Errorptr_ **ppResult)
    {
        HRESULT hr = S_OK;
        *ppResult = nullptr;

        if (argCount == 0)
        {
            return E_INVALIDARG;
        }

        int sum = 0;
        for (ULONG64 i = 0; i < argCount; ++i)
        {
            VARIANT vtValue;
            if (FAILED(ppArguments[i]->GetIntrinsicValueAs(&vtValue)))
            {
                return E_INVALIDARG;
            }
            sum += vtValue.lVal;
        }

        VARIANT vtSum;
        vtSum.vt = VT_I4;
        vtSum.lVal = sum;

        ComPtr<IModelObject> spSum;
        hr = GetManager()->CreateIntrinsicObject(ObjectIntrinsic, &vtSum, &spSum);
        if (SUCCEEDED(hr))
        {
            *ppResult = spSum.Detach();
        }

        return hr;
    }
};

// Create a method object and register it as a function alias.
ComPtr<MySumFunction> spSumFunc = Microsoft::WRL::Make<MySumFunction>();
if (spSumFunc != nullptr)
{
    VARIANT vtMethod;
    vtMethod.vt = VT_UNKNOWN;
    vtMethod.punkVal = static_cast<IModelMethod *>(spSumFunc.Get());

    ComPtr<IModelObject> spMethodObject;
    if (SUCCEEDED(GetManager()->CreateIntrinsicObject(ObjectMethod,
                                                      &vtMethod,
                                                      &spMethodObject)))
    {
        ComPtr<IDebugHostExtensibility> spHostExtensibility;
        if (SUCCEEDED(GetHost()->QueryInterface(IID_PPV_ARGS(&spHostExtensibility)))
        {
            if (SUCCEEDED(spHostExtensibility->CreateFunctionAlias(
                L"sumit",
                spMethodObject.Get())))
            {
                // sumit is now an alias for our function.  The meaning here
                // is host specific.  For DbgEng, it means you can do things
                // like "dx @$sumit(5, 7, 8)" or "!sumit 5, 7, 8"
            }
        }
    }
}
```

## See also

[IDebugHostExtensibility interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostextensibility)