# ICertPolicy::GetDescription

## Description

The **GetDescription** method returns a human-readable description of the policy module and its function.

## Parameters

### `pstrDescription` [out]

A pointer to a **BSTR** that describes the policy module.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

Returns a string that describes the policy module and its function.

## Remarks

When you write custom policy modules, implement this method.

#### Examples

```cpp
#include <windows.h>
#include <Certpol.h>

STDMETHODIMP CCertPolicy::GetDescription(
    /* [out, retval] */ BSTR __RPC_FAR *pstrDescription)
{
    if (NULL == pstrDescription)
    {
        // Bad pointer address
        return ( E_POINTER );
    }
    if (NULL != *pstrDescription)
    {
        SysFreeString(*pstrDescription);
        *pstrDescription=NULL;
    }
    // wszMyModuleDesc defined elsewhere, for example:
    // #define wszMyModuleDesc L"My Policy Module"
    *pstrDescription = SysAllocString(wszMyModuleDesc);
    if (NULL == *pstrDescription)
    {
        // Not enough memory
        return ( E_OUTOFMEMORY );
    }
    // Success
    return( S_OK );
}
```

## See also

[ICertPolicy](https://learn.microsoft.com/windows/desktop/api/certpol/nn-certpol-icertpolicy)

[ICertPolicy2](https://learn.microsoft.com/windows/desktop/api/certpol/nn-certpol-icertpolicy2)