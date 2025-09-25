# IMcastLeaseInfo::get_RequestID

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

 The
**get_RequestID** method obtains the request ID for a lease. The primary purpose of this method is to allow you to save the request ID after your application exits, so that you can call
[IMcastAddressAllocation::CreateLeaseInfo](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastaddressallocation-createleaseinfo) to re-create the lease information object during a subsequent run. This allows you to renew or release a lease after the instance of your program that originally requested the lease has exited.

## Parameters

### `ppRequestID` [out]

Pointer to a **BSTR** that will receive the request ID for this lease. The request ID uniquely identifies this lease request to the server.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **S_FAIL** | The lease information object contains an invalid request ID. |
| **E_POINTER** | The caller passed in an invalid pointer argument. |
| **E_OUTOFMEMORY** | Not enough memory to allocate the **BSTR**. |

## Remarks

The application must use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory allocated for the *ppRequestID* parameter.

This function may send data over the wire in unencrypted form; therefore, someone eavesdropping on the network may be able to read the data. The security risk of sending the data in clear text should be considered before using this method.

## See also

[IMcastLeaseInfo](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastleaseinfo)