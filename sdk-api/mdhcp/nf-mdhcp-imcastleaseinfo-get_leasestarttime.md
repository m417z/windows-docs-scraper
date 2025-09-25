# IMcastLeaseInfo::get_LeaseStartTime

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

 The
**get_LeaseStartTime** method obtains the start time of the lease.

## Parameters

### `pTime` [out]

Pointer to a **DATE** that will receive the start time of the lease.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The caller passed in an invalid pointer argument. |
| **E_INVALIDARG** | Format conversion failed for the start time or stop time. |

## Remarks

This function may send data over the wire in unencrypted form; therefore, someone eavesdropping on the network may be able to read the data. The security risk of sending the data in clear text should be considered before using this method.

## See also

[IMcastLeaseInfo](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastleaseinfo)

[IMcastLeaseInfo::put_LeaseStartTime](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastleaseinfo-put_leasestarttime)