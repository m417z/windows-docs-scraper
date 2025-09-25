# ICertExit::Notify

## Description

The **Notify** method is called by the server engine to notify an exit module that an event has occurred.

## Parameters

### `ExitEvent` [in]

A mask that indicates the kind of exit event that has occurred. The mask can have one of the following flag-bits set.

| Value | Meaning |
| --- | --- |
| **EXITEVENT_CERTISSUED** | Certificate issued. |
| **EXITEVENT_CERTPENDING** | Certificate pending. |
| **EXITEVENT_CERTDENIED** | Certificate denied. |
| **EXITEVENT_CERTREVOKED** | Certificate revoked. |
| **EXITEVENT_CERTRETRIEVEPENDING** | Successful call to [ICertRequest::RetrievePending](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-retrievepending). |
| **EXITEVENT_CRLISSUED** | [Certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) issued. |
| **EXITEVENT_SHUTDOWN** | Certificate Services shutdown. |

### `Context` [in]

Specifies a context handle that can be used to get properties associated with the event from the
[ICertServerExit](https://learn.microsoft.com/windows/desktop/api/certif/nn-certif-icertserverexit) interface.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

If a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) is using multiple exit modules, Certificate Services will notify each exit module of the event (provided the exit module requested notification by means of
[Initialize](https://learn.microsoft.com/windows/desktop/api/certexit/nf-certexit-icertexit-initialize)). The order in which the exit modules are notified should not be assumed, nor should one exit module depend on the processing of another exit module. Each notified exit module must return from
**Notify** before the next exit module will be notified.

#### Examples

```cpp
#include <windows.h>
#include <stdio.h>
#include <Certexit.h>

STDMETHODIMP CCertExit::Notify(
    /* [in] */ LONG ExitEvent,
    /* [in] */ LONG Context)
{
    char *pszEvent;
    HRESULT hr = S_OK;

    switch (ExitEvent)
    {
    case EXITEVENT_CERTISSUED:
        //  Call application-specific function for issued certs.
        hr = MyEventCertIssued(Context);
        pszEvent = "certissued";
        break;

    case EXITEVENT_CERTPENDING:
        pszEvent = "certpending";
        break;

    case EXITEVENT_CERTDENIED:
        pszEvent = "certdenied";
        break;

    case EXITEVENT_CERTREVOKED:
        pszEvent = "certrevoked";
        break;

    case EXITEVENT_CERTRETRIEVEPENDING:
        pszEvent = "retrievepending";
        break;

    case EXITEVENT_CRLISSUED:
        pszEvent = "crlissued";
        break;

    case EXITEVENT_SHUTDOWN:
        //  Call application-specific function for shutdown.
        hr = MyEventShutdown();
        pszEvent = "shutdown";
        break;

    default:
        pszEvent = "Unexpected event";
        break;
    }

    if ( fDebug )
    {
        //  Display what took place.
        printf("Exit::Notify(%s=%x, context=%u) return=%x\n",
                      pszEvent,
                      ExitEvent,
                      Context,
                      hr);
    }

    return(hr);
}
```

## See also

[ICertExit](https://learn.microsoft.com/windows/desktop/api/certexit/nn-certexit-icertexit)

[ICertExit2](https://learn.microsoft.com/windows/desktop/api/certexit/nn-certexit-icertexit2)