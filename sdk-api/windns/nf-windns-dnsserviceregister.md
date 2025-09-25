## Description

Used to register a discoverable service on this device.

## Parameters

### `pRequest`

A pointer to a [DNS_SERVICE_REGISTER_REQUEST](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_service_register_request) structure that contains information about the service to be registered.

### `pCancel`

An optional (it can be `nullptr`) pointer to a [DNS_SERVICE_CANCEL](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_service_cancel) structure that can be used to cancel a pending asynchronous registration operation. If not `nullptr`, then this handle must remain valid until the registration is canceled.

## Return value

If successful, returns **DNS_REQUEST_PENDING**; otherwise, returns the appropriate DNS-specific error code as defined in `Winerror.h`. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function is asynchronous. The registration callback will be called once the registration succeeds. To deregister the service, call [DnsServiceDeRegister](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsservicederegister).
The registration is tied to the lifetime of the calling process. If the process goes away, the service will be automatically deregistered.

## See also