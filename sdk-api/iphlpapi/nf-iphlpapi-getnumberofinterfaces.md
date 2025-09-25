# GetNumberOfInterfaces function

## Description

The
**GetNumberOfInterfaces** functions retrieves the number of interfaces on the local computer.

## Parameters

### `pdwNumIf` [out]

Pointer to a **DWORD** variable that receives the number of interfaces on the local computer.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, use
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error.

## Remarks

The
**GetNumberOfInterfaces** function returns the number of interfaces on the local computer, including the loopback interface. This number is one more than the number of adapters returned by the
[GetAdaptersInfo](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersinfo) and
[GetInterfaceInfo](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getinterfaceinfo) functions because these functions do not return information about the loopback interface.

## See also

[GetAdaptersInfo](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersinfo)

[GetIfEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getifentry)

[GetInterfaceInfo](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getinterfaceinfo)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)