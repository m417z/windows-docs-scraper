## Description

Gets a value that specifies whether Zero Trust DNS (ZTDNS) is enabled on the current device.

## Return value

True if ZTDNS is enabled; otherwise, false.

## Remarks

Because there is no import library for this function, you must call [LoadLibrary](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryw), specifying the dll name "dnsapi.dll", and then [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress), specifying the function name "DnsIsZtEnabled".

## See also