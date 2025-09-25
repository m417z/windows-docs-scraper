# ILanguageExceptionErrorInfo2::CapturePropagationContext

## Description

Captures the context of an exception across a language boundary and across threads.

## Parameters

### `languageException` [in]

An error object that's apartment-agile, in-proc, and marshal-by-value across processes.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**CapturePropagationContext** is utilized by a language projection at re-throw of an error. This includes when an error is received at a language boundary. As such, utilizing **CapturePropagationContext** helps ensure that the back trace for an exception is captured for a current re-throw. This is to also help ensure that relevant debugging information is not lost when an exception crosses a language border.

Generally speaking, the method creates a linked list of [IRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-irestrictederrorinfo) objects that provide additional error information regarding how the exception propagated. This information is exposed as stowed exceptions referenced by the exception record during crash dump analysis. Using this linked list, you can observe the back trace for all language boundaries and threads that the exception propagated through, including where the error originated from.

#### Examples

The following example demonstrates the projection receiving an error at its language boundary from another projection or WRL. This is an existing scenario, but allows the system to capture additional context if the previous projection was unable to do so.

```cpp
HRESULT CreateFooExceptionFromLanguageBoundaryError(HRESULT errorReceived, IFooException** createdException)
{
    HRESULT hr = S_OK;
    ComPtr<IFooException> exception;
    // Get the current error
    ComPtr<IRestrictedErrorInfo> restrictedErrorInfo;
    *createdException = nullptr;
    if (SUCCEEDED(GetRestrictedErrorInfo(&restrictedErrorInfo)))
    {
        // Retrieve details regarding the error to determine if it is a stale error
        // or if it is the error we received at the boundary.
        BSTR description;
        HRESULT errorOriginated;
        BSTR restrictedDescription;
        BSTR capabilitySid;
        hr = restrictedErrorInfo->GetErrorDetails(
            &description,
            &errorOriginated,
            &restrictedDescription,
            &capabilitySid);
        if (SUCCEEDED(hr) && errorReceived == errorOriginated)
        {
            hr = CreateFooException(
                errorOriginated,
                restrictedDescription,
                restrictedErrorInfo.Get(),
                &exception);
            // Query for new interface to see if the new logic is there to
            // capture the current propagation context.
            ComPtr<ILanguageExceptionErrorInfo2> languageExceptionErrorInfo;
            if (SUCCEEDED(restrictedErrorInfo.As(&languageExceptionErrorInfo)))
            {
                languageExceptionErrorInfo->CapturePropagationContext(nullptr);
            }		
            *createdException = exception.Detach();
            SetRestrictedErrorInfo(restrictedErrorInfo.Get());
            SysFreeString(description);
            SysFreeString(restrictedDescription);
            SysFreeString(capabilitySid);
            return hr;
        }
        SysFreeString(description);
        SysFreeString(restrictedDescription);
        SysFreeString(capabilitySid);
    }

    // We are here if the error didn't match or we couldn't get error details.
    // So originate a new error.
    // OriginateErrorInfoForThrow will call RoOriginateLanguageException, which will
    // capture the context
    hr = CreateFooException(errorReceived, nullptr, nullptr, &exception);
    if(SUCCEEDED(hr))
    {
        exception->OriginateErrorInfoForThrow();
        *createdException = exception.Detach();
    }
    return hr;
}

```

## See also

[ILanguageExceptionErrorInfo2](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-ilanguageexceptionerrorinfo2)