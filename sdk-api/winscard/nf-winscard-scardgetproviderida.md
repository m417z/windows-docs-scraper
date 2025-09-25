# SCardGetProviderIdA function

## Description

The **SCardGetProviderId** function returns the identifier (GUID) of the [primary service provider](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) for a given card.

The caller supplies the name of a [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (previously introduced to the system) and receives the registered identifier of the primary service provider GUID, if one exists.

## Parameters

### `hContext` [in]

Handle that identifies the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) for the query. The resource manager context can be set by a previous call to
[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext). This parameter cannot be **NULL**.

### `szCard` [in]

Name of the card defined to the system.

### `pguidProviderId` [out]

Identifier (GUID) of the primary service provider. This provider may be activated using COM, and will supply access to other services in the card.

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

This function is not redirected, but calling the function when inside a Remote Desktop session will not result in an error. It only means that the result will be from the remote computer instead of the local computer.

The **SCardGetProviderId** function is a database query function. For more information on other database query functions, see
[Smart Card Database Query Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-database-query-functions).

#### Examples

The following example shows how to get the provider ID for the specified card. The example assumes that hContext is a valid handle obtained from a previous call to the [SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext) function and that "MyCardName" was introduced by a previous call to the [SCardIntroduceCardType](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardintroducecardtypea) function.

```cpp
GUID    guidProv;
LONG    lReturn;

lReturn = SCardGetProviderId(hContext,
                             L"MyCardName",
                             &guidProv);
if ( SCARD_S_SUCCESS != lReturn )
    printf("Failed SCardGetProviderId - %x\n", lReturn);
else
{
    // Use the provider GUID as needed.
    // ...
}

```

> [!NOTE]
> The winscard.h header defines SCardGetProviderId as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext)

[SCardListCards](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlistcardsa)

[SCardListInterfaces](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlistinterfacesa)

[SCardListReaderGroups](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlistreadergroupsa)

[SCardListReaders](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlistreadersa)