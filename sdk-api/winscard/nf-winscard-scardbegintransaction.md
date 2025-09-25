# SCardBeginTransaction function

## Description

The **SCardBeginTransaction** function starts a [transaction](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly).

 The function waits for the completion of all other transactions before it begins. After the transaction starts, all other applications are blocked from accessing the [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) while the transaction is in progress.

## Parameters

### `hCard` [in]

A reference value obtained from a previous call to
[SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta).

## Return value

If the function succeeds, it returns **SCARD_S_SUCCESS**.

If the function fails, it returns an error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values).

If another process or thread has reset the card, SCARD_W_RESET_CARD is returned as expected.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This function returns **SCARD_S_SUCCESS** even if another process or thread has reset the card. To determine whether the card has been reset, call the [SCardStatus](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardstatusa) function immediately after calling this function.

## Remarks

If a transaction is held on the card for more than five seconds with no operations happening on that card, then the card is reset. Calling any of the [Smart Card and Reader Access Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-and-reader-access-functions) or [Direct Card Access Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/direct-card-access-functions) on the card that is transacted results in the timer being reset to continue allowing the transaction to be used.

The **SCardBeginTransaction** function is a [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) and [reader](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) access function. For more information about other access functions, see
[Smart Card and Reader Access Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-and-reader-access-functions).

#### Examples

The following example demonstrates how to begin a smart card transaction. The example assumes that `lReturn` is an existing variable of type **LONG** and that `hCard` is a valid handle received from a previous call to [SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta).

```cpp

lReturn = SCardBeginTransaction( hCard );
if ( SCARD_S_SUCCESS != lReturn )
 printf("Failed SCardBeginTransaction\n");

```

## See also

[SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta)

[SCardEndTransaction](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardendtransaction)