# SCardCancel function

## Description

The **SCardCancel** function terminates all outstanding actions within a specific [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly).

The only requests that you can cancel are those that require waiting for external action by the [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) or user. Any such outstanding action requests will terminate with a status indication that the action was canceled. This is especially useful to force outstanding [SCardGetStatusChange](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardgetstatuschangea) calls to terminate.

## Parameters

### `hContext` [in]

Handle that identifies the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). The resource manager context is set by a previous call to
[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext).

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

The **SCardCancel** function is a smart card tracking function. For a description of other tracking functions, see
[Smart Card Tracking Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-tracking-functions).

#### Examples

The following example cancels all outstanding actions in the specified context. The example assumes that lReturn is an existing variable of type **LONG** and that hContext is a valid handle received from a previous call to [SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext).

```cpp

lReturn = SCardCancel( hContext );
if ( SCARD_S_SUCCESS != lReturn )
    printf("Failed SCardCancel\n");

```

## See also

[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext)

[SCardGetStatusChange](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardgetstatuschangea)

[SCardLocateCards](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlocatecardsa)