# SCardIntroduceCardTypeW function

## Description

The **SCardIntroduceCardType** function introduces a [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) to the [smart card subsystem](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (for the active user) by adding it to the [smart card database](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Parameters

### `hContext` [in]

Handle that identifies the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). The resource manager context is set by a previous call to
[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext). This parameter cannot be **NULL**.

### `szCardName` [in]

Name by which the user can recognize the card.

### `pguidPrimaryProvider` [in, optional]

Pointer to the identifier (GUID) for the smart card's [primary service provider](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

### `rgguidInterfaces` [in, optional]

Array of identifiers (GUIDs) that identify the interfaces supported by the smart card.

### `dwInterfaceCount` [in]

Number of identifiers in the *rgguidInterfaces* array.

### `pbAtr` [in]

[ATR string](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) that can be used for matching purposes when querying the smart card database (for more information, see
[SCardListCards](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlistcardsa)). The length of this string is determined by normal ATR parsing.

### `pbAtrMask` [in]

Optional bitmask to use when comparing the ATRs of smart cards to the ATR supplied in *pbAtr*. If this value is non-**NULL**, it must point to a string of bytes the same length as the ATR string supplied in *pbAtr*. When a given ATR string *A* is compared to the ATR supplied in *pbAtr*, it matches if and only if *A & M* = *pbAtr*, where *M* is the supplied mask, and *&* represents bitwise AND.

### `cbAtrLen` [in]

Length of the ATR and optional ATR mask. If this value is zero, then the length of the ATR is determined by normal ATR parsing. This value cannot be zero if a *pbAtr* value is supplied.

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

This function is not redirected, but calling the function when inside a Remote Desktop session will not result in an error. It only means that the result will be from the remote computer instead of the local computer.

The **SCardIntroduceCardType** function is a database management function. For more information on other database management functions, see
[Smart Card Database Management Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-database-management-functions).

To remove a smart card, use
[SCardForgetCardType](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardforgetcardtypea).

#### Examples

The following example shows how to introduce a card type. The example assumes that hContext is a valid handle obtained from a previous call to the [SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext) function.

```cpp
GUID  MyGuid = { 0xABCDEF00,
                 0xABCD,
                 0xABCD,
                 0xAA, 0xBB, 0xCC, 0xDD,
                 0xAA, 0xBB, 0xCC, 0xDD };

static const BYTE MyATR[] =     { 0xaa, 0xbb, 0xcc, 0x00, 0xdd };
static const BYTE MyATRMask[] = { 0xff, 0xff, 0xff, 0x00, 0xff};

LONG            lReturn;

lReturn = SCardIntroduceCardType(hContext,
                                 L"MyCardName",
                                 &MyGuid,
                                 NULL,    // No interface array
                                 0,       // Interface count = 0
                                 MyATR,
                                 MyATRMask,
                                 sizeof(MyATR));
if ( SCARD_S_SUCCESS != lReturn )
    printf("Failed SCardIntroduceCardType\n");

```

> [!NOTE]
> The winscard.h header defines SCardIntroduceCardType as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext)

[SCardForgetCardType](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardforgetcardtypea)

[SCardIntroduceReader](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardintroducereadera)

[SCardIntroduceReaderGroup](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardintroducereadergroupa)

[SCardListCards](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlistcardsa)