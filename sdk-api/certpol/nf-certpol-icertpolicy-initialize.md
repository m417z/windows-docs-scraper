# ICertPolicy::Initialize

## Description

The **Initialize** method is called by the server engine to allow the policy module to perform initialization tasks.

## Parameters

### `strConfig` [in]

Represents the name of the certification authority, as entered during Certificate Services setup. For information about the configuration string name, see
[ICertConfig2](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig2).

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

When you write custom policy modules, implement this method.

#### Examples

```cpp
#include <windows.h>
#include <Certpol.h>

STDMETHODIMP CCertPolicy::Initialize(
    /* [in] */ BSTR const strConfig)
{
    // strConfig can be used by the Policy module.
    // Here, it is stored in a BSTR member variable.
    // m_strConfig is an application-defined variable.
    // Call SysFreeString to free m_strConfig when done.
    m_strConfig = SysAllocString( strConfig );
    // Check to determine whether there was enough memory.
    if (NULL == m_strConfig)
        return ( E_OUTOFMEMORY );  // Not enough memory

    return( S_OK );
}
```

## See also

[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig)

[ICertPolicy](https://learn.microsoft.com/windows/desktop/api/certpol/nn-certpol-icertpolicy)

[ICertPolicy2](https://learn.microsoft.com/windows/desktop/api/certpol/nn-certpol-icertpolicy2)