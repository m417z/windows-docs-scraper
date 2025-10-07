# SeciAllocateAndSetIPAddress function

Sets the caller's IP address to appear in security audit events.

## Parameters

*IPAddress* `[in]`

A pointer to the IP address to be set. The IP address is represented as a [SOCKADDR](https://learn.microsoft.com/windows/win32/winsock/sockaddr-2) structure.

*IPAddressLength* `[in]`

The length of the `IPAddress` structure.

*FreeCallContext* `[out]`

If set to `TRUE`, the caller is responsible for calling [SeciFreeCallContext](https://learn.microsoft.com/windows/win32/secauthn/SeciFreeCallContext).

## Return value

If the function succeeds, it returns **SEC_E_OK**.

If the function fails, it returns a non-zero error code.

## Remarks

This function is not present in the SDK headers. To use it, call the [LoadLibrary](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) function to obtain a handle to `SSPICLI.DLL` and then use [GetProcAddress](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) to obtain the function address.

The `IPAddress` parameter should be a valid pointer to an IP address structure obtained from the network layer. This corresponds to the `addr` output parameter to the [Accept](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-accept) function.

If `FreeCallContext` is set to `TRUE` on output, the caller must call [SeciFreeCallContext](https://learn.microsoft.com/windows/win32/secauthn/SeciFreeCallContext) function before relinquishing the thread.

## Requirements

| Requirement | Value |
|--------|--------|
| Minimum supported client | Windows Vista \[desktop apps \| UWP apps\] |
| Minimum supported server | Windows Server 2008 \[desktop apps \| UWP apps\] |
| Target platform | Windows |
| Header | None |
| Library | None |
| DLL | SSPICLI.DLL |

## See also

[SeciFreeCallContext](https://learn.microsoft.com/windows/win32/secauthn/SeciFreeCallContext)

[Accept](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-accept)

[SspiUnmarshalAuthIdentity](https://learn.microsoft.com/windows/win32/api/sspi/nf-sspi-sspiunmarshalauthidentity)

[HttpListenerRequest.RemoteEndPoint](https://learn.microsoft.com/dotnet/api/system.net.httplistenerrequest.remoteendpoint)