# SCardDisconnect function

## Description

The **SCardDisconnect** function terminates a connection previously opened between the calling application and a [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) in the target [reader](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly).

## Parameters

### `hCard` [in]

Reference value obtained from a previous call to
[SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta).

### `dwDisposition` [in]

Action to take on the card in the connected reader on close.

| Value | Meaning |
| --- | --- |
| **SCARD_LEAVE_CARD** | Do not do anything special. |
| **SCARD_RESET_CARD** | Reset the card. |
| **SCARD_UNPOWER_CARD** | Power down the card. |
| **SCARD_EJECT_CARD** | Eject the card. |

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

If an application (which previously called
[SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta)) exits without calling **SCardDisconnect**, the card is automatically reset.

The **SCardDisconnect** function is a [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) and [reader](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) access function. For more information on other access functions, see
[Smart Card and Reader Access Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-and-reader-access-functions).

#### Examples

The following example terminates the specified smart card connection. The example assumes that lReturn is a variable of type **LONG**, and that hCardHandle is a valid handle received from a previous call to [SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta).

```cpp

lReturn = SCardDisconnect(hCardHandle,
                          SCARD_LEAVE_CARD);
if ( SCARD_S_SUCCESS != lReturn )
{
    printf("Failed SCardDisconnect\n");
    exit(1);  // Or other appropriate action.
}

```

## See also

[SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta)

[SCardReconnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardreconnect)