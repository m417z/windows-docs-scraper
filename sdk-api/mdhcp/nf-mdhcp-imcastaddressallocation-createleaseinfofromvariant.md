# IMcastAddressAllocation::CreateLeaseInfoFromVariant

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

 The
**CreateLeaseInfoFromVariant** method creates a lease information object for a subsequent call to
[RenewAddress](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastaddressallocation-renewaddress) or
[ReleaseAddress](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastaddressallocation-releaseaddress). This method is similar to
[CreateLeaseInfo](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastaddressallocation-createleaseinfo) but is used by Automation client languages such as Visual Basic.

## Parameters

### `LeaseStartTime` [in]

The start time of the lease.

### `LeaseStopTime` [in]

The stop time of the lease.

### `vAddresses` [in]

A **VARIANT** containing a SAFEARRAY of **BSTR** strings. Each **BSTR** is an IP version 4 address in dotted quad notation (for example, 10.111.222.111).

### `pRequestID` [in]

Pointer to a **BSTR** specifying the request ID for the original request. This is obtained by calling
[IMcastLeaseInfo::get_RequestID](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastleaseinfo-get_requestid) on the lease information object corresponding to the original request. The request ID should be saved in persistent storage between executions of the application program. If you are renewing or releasing a lease that was requested during the same run of the application, you have no reason to use
[CreateLeaseInfo](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastaddressallocation-createleaseinfo); just pass the existing
[IMcastLeaseInfo](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastleaseinfo) pointer to
[RenewAddress](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastaddressallocation-renewaddress) or
[ReleaseAddress](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastaddressallocation-releaseaddress).

### `pServerAddress` [in]

Pointer to a **BSTR** specifying the server address.

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

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for the *pRequestID* and *pServerAddress* parameters. The application must use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variables are no longer needed.

TAPI calls the **AddRef** method on the
[IMcastLeaseInfo](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastleaseinfo) interface returned by **IMcastAddressAllocation::CreateLeaseInfoFromVariant**. The application must call **Release** on the
**IMcastLeaseInfo** interface to free resources associated with it.

This function may send data over the wire in unencrypted form; therefore, someone eavesdropping on the network may be able to read the data. The security risk of sending the data in clear text should be considered before using this method.

## See also

[IMcastAddressAllocation](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastaddressallocation)

[IMcastLeaseInfo](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastleaseinfo)