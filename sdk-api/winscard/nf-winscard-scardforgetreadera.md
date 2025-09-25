# SCardForgetReaderA function

## Description

The **SCardForgetReader** function removes a previously introduced [reader](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) from control by the [smart card subsystem](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). It is removed from the [smart card database](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly), including from any [reader group](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) that it may have been added to.

## Parameters

### `hContext` [in]

Handle that identifies the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). The resource manager context is set by a previous call to
[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext). This parameter cannot be **NULL**.

### `szReaderName` [in]

Display name of the reader to be removed from the smart card database.

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

If the specified reader is the last member of a reader group, the reader group is automatically removed as well.

The **SCardForgetReader** function is a database management function. For more information on other database management functions, see
[Smart Card Database Management Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-database-management-functions).

#### Examples

The following example removes the display name of the specified card reader from the system. The example assumes that lReturn is a valid variable of type **LONG** and that hContext is a valid handle received from a previous call to the [SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext) function.

```cpp

lReturn = SCardForgetReader(hContext,
                            TEXT("MyReader"));
if ( SCARD_S_SUCCESS != lReturn )
    printf("Failed SCardForgetReader\n");

```

> [!NOTE]
> The winscard.h header defines SCardForgetReader as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext)

[SCardForgetCardType](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardforgetcardtypea)

[SCardForgetReaderGroup](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardforgetreadergroupa)

[SCardIntroduceReader](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardintroducereadera)