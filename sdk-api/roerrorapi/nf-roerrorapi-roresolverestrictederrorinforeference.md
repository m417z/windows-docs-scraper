# RoResolveRestrictedErrorInfoReference function

## Description

Returns the [IRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-irestrictederrorinfo) interface pointer based on the given reference.

## Parameters

### `reference` [in]

Type: **PCWSTR**

Identifies an error object which contains relevant information for the specific error.

### `ppRestrictedErrorInfo` [out]

Type: **[IRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-irestrictederrorinfo)****

The output parameter for the object associated with the given reference.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **CLASS_E_NOAGGREGATION** | object does not support aggregation. |
| **E_INVALIDARG** | The reference is invalid. |

## Remarks

The **RoResolveRestrictedErrorInfoReference** function is useful primarily for debugger development. A debugger receives the reference string and uses the reference to identify the associated [IRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-irestrictederrorinfo) object, which allows the debugger to retrieve the detailed error message by calling the [GetErrorDetails](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nf-restrictederrorinfo-irestrictederrorinfo-geterrordetails) method.

#### Examples

```cpp
HRESULT DebuggerIntegration(PCWST   referenceName)
{
    HRESULT hr = S_OK;
    IRestrictedErrorInfo *pRORestrictedErrorInfo = nullptr;

    // Resolve the IRestrictedErrorInfo
    hr = RoResolveRestrictedErrorInfoReference(referenceName,
                      reinterpret_cast<void**>(&pRORestrictedErrorInfo));
    if (FAILED(hr))
    {
        hr = E_FAIL;
    }

    HRESULT hrError = S_OK;
    BSTR bstrDescription = nullptr;
    BSTR bstrRestrictedDescription = nullptr;

    // Get the error details out of the interface
    if (SUCCEEDED(hr))
    {
        hr = spRestrictedErrorInfo->GetErrorDetails(&bstrDescription,
                                      &hrError, &bstrRestrictedDescription);
        if (FAILED(hr))
        {
            hr = E_FAIL;
        }
    }

   return hr;

}
```