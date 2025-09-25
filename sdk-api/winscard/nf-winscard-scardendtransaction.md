# SCardEndTransaction function

## Description

The **SCardEndTransaction** function completes a previously declared [transaction](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly), allowing other applications to resume interactions with the card.

## Parameters

### `hCard` [in]

Reference value obtained from a previous call to
[SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta). This value would also have been used in an earlier call to
[SCardBeginTransaction](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardbegintransaction).

### `dwDisposition` [in]

Action to take on the card in the connected reader on close.

| Value | Meaning |
| --- | --- |
| **SCARD_EJECT_CARD** | Eject the card. |
| **SCARD_LEAVE_CARD** | Do not do anything special. |
| **SCARD_RESET_CARD** | Reset the card. |
| **SCARD_UNPOWER_CARD** | Power down the card. |

## Return value

If the function succeeds, the function returns **SCARD_S_SUCCESS**.

If the function fails, it returns an error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). Possible error codes follow.

| Return code/value | Description |
| --- | --- |
| **SCARD_W_RESET_CARD**<br><br>0x80100068L | The transaction was released. Any future communication with the card requires a call to the [SCardReconnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardreconnect) function.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** The transaction was not released. The application must immediately call the [SCardDisconnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scarddisconnect), [SCardReconnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardreconnect), or [SCardReleaseContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardreleasecontext) function to avoid an existing transaction blocking other threads and processes from communicating with the smart card. |

## Remarks

The **SCardEndTransaction** function is a [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) and [reader](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) access function. For more information on other access functions, see
[Smart Card and Reader Access Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-and-reader-access-functions).

#### Examples

The following example ends a smart card transaction. The example assumes that lReturn is a valid variable of type **LONG**, that hCard is a valid handle received from a previous call to the [SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta) function, and that hCard was passed to a previous call to the [SCardBeginTransaction](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardbegintransaction) function.

```cpp

lReturn = SCardEndTransaction(hCard,
                              SCARD_LEAVE_CARD);
if ( SCARD_S_SUCCESS != lReturn )
    printf("Failed SCardEndTransaction\n");

```

## See also

[SCardBeginTransaction](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardbegintransaction)

[SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta)