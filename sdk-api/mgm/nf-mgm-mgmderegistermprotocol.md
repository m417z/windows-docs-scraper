# MgmDeRegisterMProtocol function

## Description

The
**MgmDeRegisterMProtocol** function deregisters a client handle obtained from a call to
[MgmRegisterMProtocol](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmregistermprotocol).

## Parameters

### `hProtocol` [in]

Handle to the protocol obtained from a previous call to
[MgmRegisterMProtocol](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmregistermprotocol).

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | Could not complete the call to this function. The client did not first release the interfaces it owns. |
| **ERROR_INVALID_PARAMETER** | Invalid handle to a client. |

## Remarks

A multicast routing protocol must not call this function until it has released ownership of all the interfaces the protocol owns by calling
[MgmReleaseInterfaceOwnership](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmreleaseinterfaceownership).

## See also

[MgmRegisterMProtocol](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmregistermprotocol)

[MgmReleaseInterfaceOwnership](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmreleaseinterfaceownership)