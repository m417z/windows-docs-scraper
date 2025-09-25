## Description

Used to cancel an asynchronous DNS-SD operation.

## Members

### `reserved`

Contains a handle associated with the asynchronous operation to cancel. Your application must not modify this value.

## Remarks

This structure is returned in the `pCancel` parameter from a previous call to [DnsServiceBrowse](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsservicebrowse), [DnsServiceRegister](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsserviceregister), or [DnsServiceResolve](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsserviceresolve).

## See also