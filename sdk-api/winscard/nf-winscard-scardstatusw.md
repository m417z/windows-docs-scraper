# SCardStatusW function

## Description

The **SCardStatus** function provides the current status of a [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) in a [reader](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). You can call it any time after a successful call to [SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta) and before a successful call to [SCardDisconnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scarddisconnect). It does not affect the [state](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of the reader or [reader driver](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly).

## Parameters

### `hCard` [in]

Reference value returned from
[SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta).

### `mszReaderNames` [out]

List of display names (multiple string) by which the currently connected reader is known.

### `pcchReaderLen` [in, out, optional]

On input, supplies the length of the *szReaderName* buffer.

On output, receives the actual length (in characters) of the reader name list, including the trailing **NULL** character. If this buffer length is specified as SCARD_AUTOALLOCATE, then *szReaderName* is converted to a pointer to a byte pointer, and it receives the address of a block of memory that contains the multiple-string structure.

### `pdwState` [out, optional]

Current [state](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of the smart card in the reader. Upon success, it receives one of the following state indicators.

| Value | Meaning |
| --- | --- |
| **SCARD_ABSENT** | There is no card in the reader. |
| **SCARD_PRESENT** | There is a card in the reader, but it has not been moved into position for use. |
| **SCARD_SWALLOWED** | There is a card in the reader in position for use. The card is not powered. |
| **SCARD_POWERED** | Power is being provided to the card, but the reader driver is unaware of the mode of the card. |
| **SCARD_NEGOTIABLE** | The card has been reset and is awaiting PTS negotiation. |
| **SCARD_SPECIFIC** | The card has been reset and specific [communication protocols](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) have been established. |

### `pdwProtocol` [out, optional]

Current protocol, if any. The returned value is meaningful only if the returned value of *pdwState* is SCARD_SPECIFIC.

| Value | Meaning |
| --- | --- |
| **SCARD_PROTOCOL_RAW** | The Raw Transfer protocol is in use. |
| **SCARD_PROTOCOL_T0** | The ISO 7816/3 [T=0](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) protocol is in use. |
| **SCARD_PROTOCOL_T1** | The ISO 7816/3 [T=1](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) protocol is in use. |

### `pbAtr` [out]

Pointer to a 32-byte buffer that receives the [ATR string](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) from the currently inserted card, if available.

### `pcbAtrLen` [in, out, optional]

On input, supplies the length of the *pbAtr* buffer. On output, receives the number of bytes in the ATR string (32 bytes maximum). If this buffer length is specified as SCARD_AUTOALLOCATE, then *pbAtr* is converted to a pointer to a byte pointer, and it receives the address of a block of memory that contains the multiple-string structure.

## Return value

If the function successfully provides the current status of a [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) in a [reader](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly), the return value is SCARD_S_SUCCESS.

If the function fails, it returns an error code. For more information, see
[Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values).

## Remarks

The **SCardStatus** function is a [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) and [reader](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) access function. For information about other access functions, see
[Smart Card and Reader Access Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-and-reader-access-functions).

#### Examples

The following example shows how to determine the state of the smart card.

```cpp
WCHAR           szReader[200];
DWORD           cch = 200;
BYTE            bAttr[32];
DWORD           cByte = 32;
DWORD           dwState, dwProtocol;
LONG            lReturn;

// Determine the status.
// hCardHandle was set by an earlier call to SCardConnect.
lReturn = SCardStatus(hCardHandle,
                      szReader,
                      &cch,
                      &dwState,
                      &dwProtocol,
                      (LPBYTE)&bAttr,
                      &cByte);

if ( SCARD_S_SUCCESS != lReturn )
{
    printf("Failed SCardStatus\n");
    exit(1);     // or other appropriate action
}

// Examine retrieved status elements.
// Look at the reader name and card state.
printf("%S\n", szReader );
switch ( dwState )
{
    case SCARD_ABSENT:
        printf("Card absent.\n");
        break;
    case SCARD_PRESENT:
        printf("Card present.\n");
        break;
    case SCARD_SWALLOWED:
        printf("Card swallowed.\n");
        break;
    case SCARD_POWERED:
        printf("Card has power.\n");
        break;
    case SCARD_NEGOTIABLE:
        printf("Card reset and waiting PTS negotiation.\n");
        break;
    case SCARD_SPECIFIC:
        printf("Card has specific communication protocols set.\n");
        break;
    default:
        printf("Unknown or unexpected card state.\n");
        break;
}

```

> [!NOTE]
> The winscard.h header defines SCardStatus as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta)

[SCardDisconnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scarddisconnect)