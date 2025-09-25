# ICertExit::Initialize

## Description

The **Initialize** method is called by the server engine when it initializes itself.

 The call to the exit module's **Initialize** method allows the exit module to perform initialization and inform the server engine which kinds of events it would like to be notified of.

## Parameters

### `strConfig` [in]

Represents the name of the certification authority, as entered during Certificate Services setup. For information about the configuration string name, see
[ICertConfig2](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig2).

### `pEventMask` [out, retval]

A pointer to the value that represents the events for which the exit module requests notification. This can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **EXITEVENT_CERTDENIED** | Certificate denied. |
| **EXITEVENT_CERTISSUED** | Certificate issued. |
| **EXITEVENT_CERTPENDING** | Certificate pending. |
| **EXITEVENT_CERTRETRIEVEPENDING** | Successful call to [RetrievePending](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-retrievepending). |
| **EXITEVENT_CERTREVOKED** | Certificate revoked. |
| **EXITEVENT_CRLISSUED** | [Certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) issued. |
| **EXITEVENT_SHUTDOWN** | Certificate Services shutdown. |

## Return value

### C++

If the method succeeds, the method returns S_OK and **pEventMask* is set to a combination of the flags in the table below (or EXITEVENT_INVALID if the exit module does not want to be notified of any events).

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

If the exit module does not want to be notified of any events, then the flag EXITEVENT_INVALID should be set.

### VB

The return value is a mask that contains flags that indicate the events for which the exit module requests notification. After the call, all events of those types will be signaled by the server engine to the exit module through a call to
[Notify](https://learn.microsoft.com/windows/desktop/api/certexit/nf-certexit-icertexit-notify). Any or all of the following flags may be set.

| Return code/value | Description |
| --- | --- |
| **EXITEVENT_CERTDENIED**<br><br>&H4 | Certificate denied. |
| **EXITEVENT_CERTISSUED**<br><br>&H1 | Certificate issued. |
| **EXITEVENT_CERTPENDING**<br><br>&H2 | Certificate pending. |
| **EXITEVENT_CERTRETRIEVEPENDING**<br><br>&H10 | Successful call to [RetrievePending](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-retrievepending). |
| **EXITEVENT_CERTREVOKED**<br><br>&H8 | Certificate revoked. |
| **EXITEVENT_CRLISSUED**<br><br>&H20 | [Certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) issued. |
| **EXITEVENT_INVALID**<br><br>0 | The event is currently not valid. |
| **EXITEVENT_SHUTDOWN**<br><br>&H40 | Certificate Services shutdown. |

## Remarks

When you write a custom exit module, implement this method.

#### Examples

```cpp
#include <windows.h>
#include <stdio.h>
#include <Certexit.h>

STDMETHODIMP CCertExit::Initialize(
    /* [in] */ BSTR const strConfig,
    /* [retval][out] */ LONG __RPC_FAR *pEventMask)
{
    // Verify valid pointer passed in.
    if (NULL == pEventMask)
        return ( E_POINTER );  // Bad pointer

    // strConfig can be used by the Exit module.
    // Here, it is stored in a BSTR member variable.
    // Remember to call SysFreeString to free m_strConfig when done.
    m_strConfig = SysAllocString( strConfig );
    // Check to determine whether there was enough memory.
    if (NULL == m_strConfig)
        return ( E_OUTOFMEMORY );  // Not enough memory

    // Inform server engine (CA) that we're interested in
    // the following events.
    *pEventMask = EXITEVENT_CERTISSUED |
                  EXITEVENT_CERTPENDING |
                  EXITEVENT_CERTDENIED |
                  EXITEVENT_CERTREVOKED |
                  EXITEVENT_CERTRETRIEVEPENDING |
                  EXITEVENT_CRLISSUED |
                  EXITEVENT_SHUTDOWN;

    if ( fDebug )
    {
        printf("Exit's Initialize member called\n");
        printf("\tstrConfig = %ws\n", strConfig );
    }

    return( S_OK );
}
```

## See also

[ICertExit](https://learn.microsoft.com/windows/desktop/api/certexit/nn-certexit-icertexit)

[ICertExit2](https://learn.microsoft.com/windows/desktop/api/certexit/nn-certexit-icertexit2)

[Notify](https://learn.microsoft.com/windows/desktop/api/certexit/nf-certexit-icertexit-notify)