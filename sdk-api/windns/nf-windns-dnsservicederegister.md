## Description

Used to remove a registered service.

## Parameters

### `pRequest`

A pointer to the [DNS_SERVICE_REGISTER_REQUEST](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_service_register_request) structure that was used to register the service.

### `pCancel`

Must be `nullptr`.

## Return value

If successful, returns **DNS_REQUEST_PENDING**; otherwise, returns the appropriate DNS-specific error code as defined in `Winerror.h`. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function is asynchronous. The callback will be invoked when the deregistration is completed, with a copy of the [DNS_SERVICE_INSTANCE](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_service_instance) structure that was passed to [DnsServiceRegister](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsserviceregister) when the service was registered.

## See also