# SCardReconnect function

## Description

The **SCardReconnect** function reestablishes an existing connection between the calling application and a [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). This function moves a card handle from direct access to general access, or acknowledges and clears an error condition that is preventing further access to the card.

## Parameters

### `hCard` [in]

Reference value obtained from a previous call to
[SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta).

### `dwShareMode` [in]

Flag that indicates whether other applications may form connections to this card.

| Value | Meaning |
| --- | --- |
| **SCARD_SHARE_SHARED** | This application will share this card with other applications. |
| **SCARD_SHARE_EXCLUSIVE** | This application will not share this card with other applications. |

### `dwPreferredProtocols` [in]

Bitmask of acceptable protocols for this connection. Possible values may be combined with the **OR** operation.

The value of this parameter should include the current protocol. Attempting to reconnect with a protocol other than the current protocol will result in an error.

| Value | Meaning |
| --- | --- |
| **SCARD_PROTOCOL_T0** | [T=0](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) is an acceptable protocol. |
| **SCARD_PROTOCOL_T1** | [T=1](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) is an acceptable protocol. |

### `dwInitialization` [in]

Type of initialization that should be performed on the card.

| Value | Meaning |
| --- | --- |
| **SCARD_LEAVE_CARD** | Do not do anything special on reconnect. |
| **SCARD_RESET_CARD** | Reset the card (Warm Reset). |
| **SCARD_UNPOWER_CARD** | Power down the card and reset it (Cold Reset). |

### `pdwActiveProtocol` [out, optional]

Flag that indicates the established active protocol.

| Value | Meaning |
| --- | --- |
| **SCARD_PROTOCOL_T0** | [T=0](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) is the active protocol. |
| **SCARD_PROTOCOL_T1** | [T=1](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly) is the active protocol. |

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

**SCardReconnect** is a [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) and [reader](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) access function. For information about other access functions, see
[Smart Card and Reader Access Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-and-reader-access-functions).

#### Examples

The following example shows reestablishing a connection.

```cpp
DWORD     dwAP;
LONG      lReturn;

// Reconnect.
// hCardHandle was set by a previous call to SCardConnect.
lReturn = SCardReconnect(hCardHandle,
                         SCARD_SHARE_SHARED,
                         SCARD_PROTOCOL_T0 | SCARD_PROTOCOL_T1,
                         SCARD_LEAVE_CARD,
                         &dwAP );
if ( SCARD_S_SUCCESS != lReturn )
    printf("Failed SCardReconnect\n");

```

## See also

[SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta)

[SCardDisconnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scarddisconnect)