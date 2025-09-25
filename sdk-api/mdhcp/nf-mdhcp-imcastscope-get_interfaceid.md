# IMcastScope::get_InterfaceID

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**get_InterfaceID** method obtains an interface identifier of this scope, which identifies the interface on which the server that published this scope resides. This is normally the network address of the interface.

## Parameters

### `pID` [out]

Pointer to a **LONG** that will receive the server ID of this scope, which is the ID that was assigned to the multicast address allocation server that published this scope at the time that the server was configured.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The caller passed in an invalid pointer argument. |

## Remarks

The InterfaceID is provided for informational purposes only; it is not required as input to any of the methods in these interfaces. However, it may factor into the application's (or the user's) decision as to which scope to use when requesting an address. This is because, in a multihomed scenario, using a multicast address on one network that was obtained from a server on another network may cause address conflicts.

## See also

[IMcastScope](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastscope)