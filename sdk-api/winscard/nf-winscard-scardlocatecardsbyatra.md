# SCardLocateCardsByATRA function

## Description

The **SCardLocateCardsByATR** function searches the readers listed in the *rgReaderStates* parameter for a card with a name that matches one of the card names contained in one of the [SCARD_ATRMASK](https://learn.microsoft.com/windows/desktop/api/winscard/ns-winscard-scard_atrmask) structures specified by the *rgAtrMasks* parameter.

## Parameters

### `hContext` [in]

Handle that identifies the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). The resource manager context is set by a previous call to [SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext).

### `rgAtrMasks` [in]

Array of
[SCARD_ATRMASK](https://learn.microsoft.com/windows/desktop/api/winscard/ns-winscard-scard_atrmask) structures that contain the names of the cards for which to search.

### `cAtrs` [in]

Number of elements in the *rgAtrMasks* array.

### `rgReaderStates` [in, out]

Array of [SCARD_READERSTATE](https://learn.microsoft.com/windows/desktop/api/winscard/ns-winscard-scard_readerstatea) structures that specify the readers to search, and receive the result.

### `cReaders` [in]

Number of elements in the *rgReaderStates* array.

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | Error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

This service is especially useful when used in conjunction with
[SCardGetStatusChange](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardgetstatuschangea). If no matching cards are found by means of [SCardLocateCards](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlocatecardsa), the calling application may use **SCardGetStatusChange** to wait for card availability changes.

The **SCardLocateCardsByATR** function is a [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) tracking function. For information about other tracking functions, see
[Smart Card Tracking Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-tracking-functions).

> [!NOTE]
> The winscard.h header defines SCardLocateCardsByATR as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).