## Description

Used to cancel a pending registration operation.

## Parameters

### `pCancelHandle`

A pointer to the [DNS_SERVICE_CANCEL](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_service_cancel) structure that was passed to the [DnsServiceRegister](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsserviceregister) call that is to be cancelled.

## Return value

If successful, returns **ERROR_SUCCESS**. Returns **ERROR_CANCELLED** if the operation was already cancelled, or **ERROR_INVALID_PARAMETER** if the handle is invalid.

## Remarks

## See also