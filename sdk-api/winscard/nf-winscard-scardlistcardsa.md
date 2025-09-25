# SCardListCardsA function

## Description

The **SCardListCards** function searches the [smart card database](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) and provides a list of named cards previously introduced to the system by the user.

The caller specifies an [ATR string](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly), a set of interface identifiers (GUIDs), or both. If both an ATR string and an identifier array are supplied, the cards returned will match the ATR string supplied and support the interfaces specified.

## Parameters

### `hContext` [in]

Handle that identifies the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) for the query. The resource manager context can be set by a previous call to [SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext).

If this parameter is set to **NULL**, the search for cards is not limited to any context.

### `pbAtr` [in, optional]

Address of an ATR string to compare to known cards, or **NULL** if no ATR matching is to be performed.

### `rgquidInterfaces` [in]

Array of identifiers (GUIDs), or **NULL** if no interface matching is to be performed. When an array is supplied, a card name will be returned only if all the specified identifiers are supported by the card.

### `cguidInterfaceCount` [in]

Number of entries in the *rgguidInterfaces* array. If *rgguidInterfaces* is **NULL**, then this value is ignored.

### `mszCards` [out]

Multi-string that lists the [smart cards](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) found. If this value is **NULL**, **SCardListCards** ignores the buffer length supplied in *pcchCards*, returning the length of the buffer that would have been returned if this parameter had not been **NULL** to *pcchCards* and a success code.

### `pcchCards` [in, out]

Length of the *mszCards* buffer in characters. Receives the actual length of the multi-string structure, including all trailing **null** characters. If the buffer length is specified as SCARD_AUTOALLOCATE, then *mszCards* is converted to a pointer to a byte pointer, and receives the address of a block of memory containing the multi-string structure. This block of memory must be deallocated with
[SCardFreeMemory](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardfreememory).

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

This function is not redirected, but calling the function when inside a Remote Desktop session will not result in an error. It only means that the result will be from the remote computer instead of the local computer.

To return all smart cards introduced to the subsystem, set *pbAtr* and *rgguidInterfaces* to **NULL**.

The **SCardListCards** function is a database query function. For more information on other database query functions, see
[Smart Card Database Query Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-database-query-functions).

Calling this function should be done outside of a transaction. If an application begins a transaction with the [SCardBeginTransaction](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardbegintransaction) function and then calls this function, it resets the *hCard* parameter (of type **SCARDHANDLE**) of the **SCardBeginTransaction** function.

**Windows Server 2008 R2 and Windows 7:** Calling this function within a transaction could result in your computer becoming unresponsive.

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** Not applicable.

#### Examples

The following example shows listing of the smart cards.

```cpp
LPTSTR pmszCards = NULL;
LPTSTR pCard;
LONG lReturn;
DWORD cch = SCARD_AUTOALLOCATE;

// Retrieve the list of cards.
lReturn = SCardListCards(NULL,
                         NULL,
                         NULL,
                         NULL,
                         (LPTSTR)&pmszCards,
                         &cch );
if ( SCARD_S_SUCCESS != lReturn )
{
    printf("Failed SCardListCards\n");
    exit(1); // Or other appropriate error action
}
// Do something with the multi string of cards.
// Output the values.
// A double-null terminates the list of values.
pCard = pmszCards;
while ( '\0' != *pCard )
{
    // Display the value.
    printf("%S\n", pCard );
    // Advance to the next value.
    pCard = pCard + wcslen(pCard) + 1;
}

// Remember to free pmszCards (by calling SCardFreeMemory).
// ...

```

> [!NOTE]
> The winscard.h header defines SCardListCards as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext)

[SCardFreeMemory](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardfreememory)

[SCardGetProviderId](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardgetproviderida)

[SCardListInterfaces](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlistinterfacesa)

[SCardListReaderGroups](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlistreadergroupsa)

[SCardListReaders](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlistreadersa)