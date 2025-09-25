# ICertPolicy::ShutDown

## Description

The **ShutDown** method is called by the server engine before the server is terminated.

When **ShutDown** is called, the policy module should clean up and stop. It is guaranteed that no requests will arrive after **ShutDown** is called.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

When you write custom policy modules, implement this method.

#### Examples

```cpp
#include <windows.h>
#include <stdio.h>
#include <Certpol.h>

STDMETHODIMP CCertPolicy::ShutDown()
{
    // Clean up resources used by this process.

    // Display message that this method has been called.
    if ( fDebug )
    {
        printf("Policy module Shutdown was called\n");
    }
    return( S_OK );
}
```

## See also

[ICertPolicy](https://learn.microsoft.com/windows/desktop/api/certpol/nn-certpol-icertpolicy)

[ICertPolicy2](https://learn.microsoft.com/windows/desktop/api/certpol/nn-certpol-icertpolicy2)