# SCardLocateCardsA function

## Description

The **SCardLocateCards** function searches the readers listed in the *rgReaderStates* parameter for a card with an [ATR string](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) that matches one of the card names specified in *mszCards*, returning immediately with the result.

## Parameters

### `hContext` [in]

A handle that identifies the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). The resource manager context is set by a previous call to [SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext).

### `mszCards` [in]

A multiple string that contains the names of the cards to search for.

### `rgReaderStates` [in, out]

An array of [SCARD_READERSTATE](https://learn.microsoft.com/windows/desktop/api/winscard/ns-winscard-scard_readerstatea) structures that, on input, specify the readers to search and that, on output, receives the result.

### `cReaders` [in]

The number of elements in the *rgReaderStates* array.

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

This service is especially useful when used in conjunction with
[SCardGetStatusChange](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardgetstatuschangea). If no matching cards are found by means of **SCardLocateCards**, the calling application may use **SCardGetStatusChange** to wait for card availability changes.

The **SCardLocateCards** function is a [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) tracking function. For more information on other tracking functions, see
[Smart Card Tracking Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-tracking-functions).

Calling this function should be done outside of a transaction. If an application begins a transaction with the [SCardBeginTransaction](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardbegintransaction) function and then calls this function, it resets the *hCard* parameter (of type **SCARDHANDLE**) of the **SCardBeginTransaction** function.

**Windows Server 2008 R2 and Windows 7:** Calling this function within a transaction could result in your computer becoming unresponsive.

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** Not applicable.

#### Examples

The following example shows locating smart cards.

```cpp
// Copyright (C) Microsoft. All rights reserved.
#include <stdio.h>
#include <winscard.h>
#include <tchar.h>
#pragma comment(lib, "winscard.lib")

HRESULT __cdecl main()
{
HRESULT           hr = S_OK;
LPTSTR            szReaders, szRdr;
DWORD             cchReaders = SCARD_AUTOALLOCATE;
DWORD             dwI, dwRdrCount;
SCARD_READERSTATE rgscState[MAXIMUM_SMARTCARD_READERS];
TCHAR             szCard[MAX_PATH];
SCARDCONTEXT      hSC;
LONG              lReturn;

// Establish the card to watch for.
// Multiple cards can be looked for, but
// this sample looks for only one card.
_tcscat_s ( szCard, MAX_PATH * sizeof(TCHAR), TEXT("GemSAFE"));
szCard[lstrlen(szCard) + 1] = 0;  // Double trailing zero.

// Establish a context.
lReturn = SCardEstablishContext(SCARD_SCOPE_USER,
                                NULL,
                                NULL,
                                &hSC );
if ( SCARD_S_SUCCESS != lReturn )
{
    printf("Failed SCardEstablishContext\n");
    exit(1);
}

// Determine which readers are available.
lReturn = SCardListReaders(hSC,
                           NULL,
                           (LPTSTR)&szReaders,
                           &cchReaders );
if ( SCARD_S_SUCCESS != lReturn )
{
    printf("Failed SCardListReaders\n");
    exit(1);
}
// Place the readers into the state array.
szRdr = szReaders;
for ( dwI = 0; dwI < MAXIMUM_SMARTCARD_READERS; dwI++ )
{
    if ( 0 == *szRdr )
        break;
    rgscState[dwI].szReader = szRdr;
    rgscState[dwI].dwCurrentState = SCARD_STATE_UNAWARE;
    szRdr += lstrlen(szRdr) + 1;
}
dwRdrCount = dwI;

// If any readers are available, proceed.
if ( 0 != dwRdrCount )
{
  for (;;)
  {
    // Look for the card.
    lReturn = SCardLocateCards(hSC,
                               szCard,
                               rgscState,
                               dwRdrCount );
    if ( SCARD_S_SUCCESS != lReturn )
    {
        printf("Failed SCardLocateCards\n");
        exit(1);
    }

    // Look through the array of readers.
    for ( dwI=0; dwI < dwRdrCount; dwI++)
    {
        if ( 0 != ( SCARD_STATE_ATRMATCH &
                    rgscState[dwI].dwEventState))
        {
           _tprintf( TEXT("Card '%s' found in reader '%s'.\n"),
                     szCard,
                     rgscState[dwI].szReader );
            SCardFreeMemory( hSC,
                             szReaders );
            return 0;  // Context will be release automatically.
        }
        // Update the state.
        rgscState[dwI].dwCurrentState = rgscState[dwI].dwEventState;
    }

  // Card not found yet; wait until there is a change.
  lReturn = SCardGetStatusChange(hSC,
                                 INFINITE, // infinite wait
                                 rgscState,
                                 dwRdrCount );
  if ( SCARD_S_SUCCESS != lReturn )
  {
    printf("Failed SCardGetStatusChange\n");
    exit(1);
  }
 }  // for (;;)
}
else
    printf("No readers available\n");

// Release the context.
lReturn = SCardReleaseContext(hSC);
if ( SCARD_S_SUCCESS != lReturn )
{
    printf("Failed SCardReleaseContext\n");
    exit(1);
}

SCardFreeMemory( hSC,
                 szReaders );

return hr;
}

```

> [!NOTE]
> The winscard.h header defines SCardLocateCards as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SCARD_READERSTATE](https://learn.microsoft.com/windows/desktop/api/winscard/ns-winscard-scard_readerstatea)

[SCardCancel](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardcancel)

[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext)

[SCardGetStatusChange](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardgetstatuschangea)