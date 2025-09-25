# IMcastLeaseInfo::put_LeaseStartTime

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

 The
**put_LeaseStartTime** method sets the start time of the lease. This method, along with
[put_LeaseStopTime](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastleaseinfo-put_leasestoptime), allows renewal of a lease without calling
[IMcastAddressAllocation::CreateLeaseInfo](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastaddressallocation-createleaseinfo).

## Parameters

### `time` [in]

A **DATE** specifying the start time of the lease.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | Format conversion failed for the start time or stop time. |

## Remarks

This function may send data over the wire in unencrypted form; therefore, someone eavesdropping on the network may be able to read the data. The security risk of sending the data in clear text should be considered before using this method.

## See also

[IMcastLeaseInfo](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastleaseinfo)

[get_LeaseStartTime](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastleaseinfo-get_leasestarttime)