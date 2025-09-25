# ILanguageExceptionTransform::GetTransformedRestrictedErrorInfo

## Description

Retrieves the transformed restricted error info.

## Parameters

### `restrictedErrorInfo` [out]

A pointer to an [IRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-irestrictederrorinfo) object that contains the restricted error info.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**GetTransformedRestrictedErrorInfo** is generally implemented by a language projection in order to expose to the system any and all context from an exception. Specifically, to expose the information from an exception that was thrown from the context of a catch handler that catches a different exception. The thrown exception is considered to be a “transformation” of the caught exception, which is also considered an inner exception by some projections. This allows a developer to obtain insight into why the original exception, before the transform, occurred.

When implemented, the system uses the [IRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-irestrictederrorinfo) retrieved from a call to **GetTransformedRestrictedErrorInfo** to create another linked list of **IRestrictedErrorInfo** objects. These objects are exposed in as stowed exceptions in the crash dumps in sequence with the stowed exceptions for the propagations captured in [CapturePropagationContext](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nf-restrictederrorinfo-ilanguageexceptionerrorinfo2-capturepropagationcontext). As with the other exceptions, you can traverse and access these objects in the transformation list using [GetPreviousLanguageExceptionErrorInfo](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nf-restrictederrorinfo-ilanguageexceptionerrorinfo2-getpreviouslanguageexceptionerrorinfo).

#### Examples

```cpp
[
    uuid(7974CD8B-A9EF-4CC4-9A7D-5793CCE30734),
    pointer_default(unique),
    object
]
interface IFooExceptionInfo : IUnknown
{
    ...
    HRESULT SetTranformedException(IFooException* exception);
}

class FooExceptionInfo : public Microsoft::WRL::RuntimeClass<
    Microsoft::WRL::RuntimeClassFlags<
    Microsoft::WRL::RuntimeClassType::ClassicCom>,
    IFooExceptionInfo,
    ILanguageExceptionTransform>
{
    ...
    ...
private:
    HRESULT _hr;
    Microsoft::WRL::Wrappers::HString _message;
    ComPtr<IFooException> _transformedException;
public:
    HRESULT SetTranformedException(IFooException* exception)
    {
        _transformedException = exception;
        return S_OK;
    }

    HRESULT GetTransformedRestrictedErrorInfo(IRestrictedErrorInfo** restrictedErrorInfo)
    {
        return _transformedException->GetRestrictedErrorForException(
                   restrictedErrorInfo);
    }
}
[
    uuid(52394734-6600-4835-8E17-60BDEDB14B81),
    pointer_default(unique),
    object
]
interface IFooException : IUnknown
{
    ...
    HRESULT GetRestrictedErrorForException(IRestrictedErrorInfo** restrictedErrorInfo);
    HRESULT GetExceptionInfo(IFooExceptionInfo** exceptionInfo);
}

class FooException : public Microsoft::WRL::RuntimeClass<
    Microsoft::WRL::RuntimeClassFlags<
    Microsoft::WRL::RuntimeClassType::ClassicCom>,
    IFooException
    ...>
{
    ...
    ...
private:
    ComPtr<IFooExceptionInfo> _exceptionInfo;
    ComPtr<IRestrictedErrorInfo> _restrictedErrorInfo;
public:
    HRESULT GetRestrictedErrorForException(IRestrictedErrorInfo** restrictedErrorInfo)
    {
        return _restrictedErrorInfo.CopyTo(restrictedErrorInfo);
    }

    HRESULT GetExceptionInfo(IFooExceptionInfo** exceptionInfo)
    {
        return _exceptionInfo.CopyTo(exceptionInfo);
    }
}
void OriginateErrorInfoForThrowWithCaughtException(IFooException* exception, IFooException* caughtException)
{
    ComPtr<IFooExceptionInfo> exceptionInfo;     if(SUCCEEDED(exception->GetExceptionInfo(&exceptionInfo)))
    {
        exceptionInfo->SetTranformedException(caughtException);
        exception->OriginateErrorInfoForThrow();
    }
}
```

## See also

[ILanguageExceptionTransform](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-ilanguageexceptiontransform)