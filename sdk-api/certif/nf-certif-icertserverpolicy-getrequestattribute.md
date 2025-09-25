# ICertServerPolicy::GetRequestAttribute

## Description

The **GetRequestAttribute** method returns a named [attribute](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) from a request.

## Parameters

### `strAttributeName` [in]

The name of the attribute to retrieve.

### `pstrAttributeValue` [out]

A pointer to a **BSTR** value that will contain the attribute value.

## Return value

### C++

If the method succeeds, the method returns S_OK and **pstrAttributeValue* is set to the **BSTR** that contains the attribute value.

To use this method, create a variable of type **BSTR**, set the variable equal to **NULL**, and pass the address of this variable as *pstrAttributeValue*.

When you have finished using the **BSTR**, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a string that represents the attribute value.

## Remarks

You must call
[ICertServerPolicy::SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-setcontext) prior to using this method.

The following request attributes are unique to KEYGEN style requests.

| Property name | Type | Description |
| --- | --- | --- |
| Challenge | **String** | Challenge string that accompanies the request. |
| ExpectedChallenge | **String** | If the challenge string is incorrect, then the server will set the value of this request attribute to the expected challenge so that failure can be diagnosed. |

#### Examples

```cpp
BSTR     bstrAttribValue = NULL;
HRESULT  hr;

// Get the request attribute.
// bstrAttribName is BSTR assigned by EnumerateAttributes.
// pCertServerPolicy has been used to call SetContext previously.
hr = pCertServerPolicy->GetRequestAttribute(bstrAttribName,
                                            &bstrAttribValue);

if (FAILED(hr))
{
    printf("Failed GetRequestAttribute [%x]\n", hr);
    goto error;
}
else
{

    // Successful call. Use the bstrAttribValue as needed.
    // ...
}

// Done processing. Free BSTR.
if (NULL != bstrAttribValue)
    SysFreeString(bstrAttribValue);
```

## See also

[ICertServerPolicy](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverpolicy)

[ICertServerPolicy::SetContext](https://learn.microsoft.com/windows/desktop/api/certif/nf-certif-icertserverpolicy-setcontext)