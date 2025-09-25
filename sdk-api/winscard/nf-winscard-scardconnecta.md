# SCardConnectA function

## Description

The **SCardConnect** function establishes a connection (using a specific [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly)) between the calling application and a [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) contained by a specific reader. If no card exists in the specified reader, an error is returned.

## Parameters

### `hContext` [in]

A handle that identifies the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). The resource manager context is set by a previous call to
[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext).

### `szReader` [in]

The name of the reader that contains the target card.

### `dwShareMode` [in]

A flag that indicates whether other applications may form connections to the card.

| Value | Meaning |
| --- | --- |
| **SCARD_SHARE_SHARED** | This application is willing to share the card with other applications. |
| **SCARD_SHARE_EXCLUSIVE** | This application is not willing to share the card with other applications. |
| **SCARD_SHARE_DIRECT** | This application is allocating the reader for its private use, and will be controlling it directly. No other applications are allowed access to it. |

### `dwPreferredProtocols` [in]

A bitmask of acceptable protocols for the connection. Possible values may be combined with the **OR** operation.

| Value | Meaning |
| --- | --- |
| **SCARD_PROTOCOL_T0** | [T=0](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) is an acceptable protocol. |
| **SCARD_PROTOCOL_T1** | [T=1](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) is an acceptable protocol. |
| **0** | This parameter may be zero only if *dwShareMode* is set to SCARD_SHARE_DIRECT. In this case, no protocol negotiation will be performed by the drivers until an IOCTL_SMARTCARD_SET_PROTOCOL control directive is sent with [SCardControl](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardcontrol). |

### `phCard` [out]

A handle that identifies the connection to the [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) in the designated reader.

### `pdwActiveProtocol` [out]

A flag that indicates the established active protocol.

| Value | Meaning |
| --- | --- |
| **SCARD_PROTOCOL_T0** | [T=0](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) is the active protocol. |
| **SCARD_PROTOCOL_T1** | [T=1](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) is the active protocol. |
| **SCARD_PROTOCOL_UNDEFINED** | SCARD_SHARE_DIRECT has been specified, so that no protocol negotiation has occurred. It is possible that there is no card in the reader. |

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |
| **SCARD_E_NOT_READY** | The reader was unable to connect to the card. |

## Remarks

The **SCardConnect** function is a [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) and [reader](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) access function. For more information about other access functions, see
[Smart Card and Reader Access Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-and-reader-access-functions).

#### Examples

The following example creates a connection to a reader. The example assumes that *hContext* is a valid handle of type **SCARDCONTEXT** received from a previous call to [SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext).

```cpp
SCARDHANDLE     hCardHandle;
LONG            lReturn;
DWORD           dwAP;

lReturn = SCardConnect( hContext,
                        (LPCTSTR)"Rainbow Technologies SCR3531 0",
                        SCARD_SHARE_SHARED,
                        SCARD_PROTOCOL_T0 | SCARD_PROTOCOL_T1,
                        &hCardHandle,
                        &dwAP );
if ( SCARD_S_SUCCESS != lReturn )
{
    printf("Failed SCardConnect\n");
    exit(1);  // Or other appropriate action.
}

// Use the connection.
// Display the active protocol.
switch ( dwAP )
{
    case SCARD_PROTOCOL_T0:
        printf("Active protocol T0\n");
        break;

    case SCARD_PROTOCOL_T1:
        printf("Active protocol T1\n");
        break;

    case SCARD_PROTOCOL_UNDEFINED:
    default:
        printf("Active protocol unnegotiated or unknown\n");
        break;
}

// Remember to disconnect (by calling SCardDisconnect).
// ...

```

> [!NOTE]
> The winscard.h header defines SCardConnect as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SCardControl](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardcontrol)

[SCardDisconnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scarddisconnect)

[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext)

[SCardReconnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardreconnect)