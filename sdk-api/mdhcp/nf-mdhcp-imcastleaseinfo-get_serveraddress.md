# IMcastLeaseInfo::get_ServerAddress

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

 The
**get_ServerAddress** method obtains a string representing the address of the multicast server granting this lease.

## Parameters

### `ppAddress` [out]

Pointer to a **BSTR** that will receive a string representation of the address of the server granting this request or renewal.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **S_FALSE** | Server address unspecified. |
| **E_POINTER** | The caller passed in an invalid pointer argument. |
| **E_OUTOFMEMORY** | Not enough memory exists to allocate the string. |

## Remarks

The **BSTR** string *ppAddress* is an IP version 4 address in dotted quad notation (for example, 10.111.222.111). If a lease information object does not describe a granted lease (for example, it was not returned by
[IMcastAddressAllocation::RequestAddress](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastaddressallocation-requestaddress) or
[IMcastAddressAllocation::RenewAddress](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastaddressallocation-renewaddress)), the address is reported as the string "Unspecified".

The application must use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory allocated for the *ppAddress* parameter.

This function may send data over the wire in unencrypted form; therefore, someone eavesdropping on the network may be able to read the data. The security risk of sending the data in clear text should be considered before using this method.

## See also

[IMcastLeaseInfo](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastleaseinfo)