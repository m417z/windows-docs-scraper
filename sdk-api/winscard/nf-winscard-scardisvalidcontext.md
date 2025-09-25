# SCardIsValidContext function

## Description

The **SCardIsValidContext** function determines whether a [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) context handle is valid.

## Parameters

### `hContext` [in]

Handle that identifies the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). The resource manager context can be set by a previous call to
[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext).

## Return value

This function returns one of the following values.

| Return code | Description |
| --- | --- |
| **SCARD_S_SUCCESS** | The *hContext* parameter is valid. |
| **ERROR_INVALID_HANDLE** | The *hContext* parameter is not valid. |
| **Other values** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

Call this function to determine whether a [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) context handle is still valid. After a smart card context handle has been set by
[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext), it may become not valid if the [resource manager](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) service has been shut down.

#### Examples

The following example shows determining whether a smart card context handle is valid.

```cpp
// Check the smart card context handle.
// hContext was set previously by SCardEstablishContext.

LONG    lReturn;
lReturn = SCardIsValidContext(hContext);
if ( SCARD_S_SUCCESS != lReturn )
{
    // Function failed; check return value.
    if ( ERROR_INVALID_HANDLE == lReturn )
        printf("Handle is invalid\n");
    else
    {
        // Some unexpected error occurred; report and bail out.
        printf("Failed SCardIsValidContext - %x\n", lReturn);
        exit(1);  // Or other appropriate error action.
    }
}
else
{
    // Handle is valid; proceed as needed.
    // ...
}

```

## See also

[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext)