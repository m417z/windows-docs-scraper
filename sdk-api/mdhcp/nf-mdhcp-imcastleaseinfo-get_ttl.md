# IMcastLeaseInfo::get_TTL

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The **get_TTL** method obtains the [time to live](https://learn.microsoft.com/windows/win32/tapi/t-tapgloss) (TTL) value associated with this lease.

## Parameters

### `pTTL` [out]

Pointer to a **LONG** that will receive the TTL value associated with this lease.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The caller passed in an invalid pointer argument. |
| **E_FAIL** | There is no TTL associated with this lease. |

## Remarks

The TTL is more or less significant in the implementation of multicast routing. Generally, the higher the TTL value, the "larger" or more inclusive the multicast scope. Most applications need not address the TTL.

This function may send data over the wire in unencrypted form; therefore, someone eavesdropping on the network may be able to read the data. The security risk of sending the data in clear text should be considered before using this method.

## See also

[IMcastLeaseInfo](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastleaseinfo)