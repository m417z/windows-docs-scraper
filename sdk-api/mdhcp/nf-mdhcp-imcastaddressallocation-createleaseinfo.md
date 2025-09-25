# IMcastAddressAllocation::CreateLeaseInfo

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

 The
**CreateLeaseInfo** method creates a lease information object for a subsequent call to
[RenewAddress](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastaddressallocation-renewaddress) or
[ReleaseAddress](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastaddressallocation-releaseaddress).

## Parameters

### `LeaseStartTime` [in]

The start time of the lease.

### `LeaseStopTime` [in]

The stop time of the lease.

### `dwNumAddresses` [in]

The number of addresses associated with the lease.

### `ppAddresses` [in]

An array of **LPWSTR** pointers of size *dwNumAddresses*. Each **LPWSTR** is an IP version 4 address in dotted quad notation (for example, 10.111.222.111).

### `pRequestID` [in]

An **LPWSTR** specifying the request ID for the original request. This is obtained by calling
[IMcastLeaseInfo::get_RequestID](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastleaseinfo-get_requestid) on the lease information object corresponding to the original request. The request ID should be saved in persistent storage between executions of the application program. If you are renewing or releasing a lease that was requested during the same run of the application, you have no reason to use
**CreateLeaseInfo**; just pass the existing
[IMcastLeaseInfo](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastleaseinfo) pointer to
[RenewAddress](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastaddressallocation-renewaddress) or
[ReleaseAddress](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastaddressallocation-releaseaddress).

### `pServerAddress` [in]

Specifies server address.

### `ppReleaseRequest` [out]

Pointer to the
[IMcastLeaseInfo](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastleaseinfo) interface created.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The caller passed in an invalid pointer argument. |
| **E_OUTOFMEMORY** | Not enough memory exists to create the required objects. |

## Remarks

TAPI calls the **AddRef** method on the
[IMcastLeaseInfo](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastleaseinfo) interface returned by **IMcastAddressAllocation::CreateLeaseInfo**. The application must call **Release** on the
**IMcastLeaseInfo** interface to free resources associated with it.

This function may send data over the wire in unencrypted form; therefore, someone eavesdropping on the network may be able to read the data. The security risk of sending the data in clear text should be considered before using this method.

## See also

[IMcastAddressAllocation](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastaddressallocation)