# GetAdapterIndex function

## Description

The
**GetAdapterIndex** function obtains the index of an adapter, given its name.

## Parameters

### `AdapterName` [in]

A pointer to a Unicode string that specifies the name of the adapter.

### `IfIndex` [in, out]

A pointer to a **ULONG** variable that points to the index of the adapter.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, use
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error.

## Remarks

Until an adapter is fully disabled, the **GetAdapterIndex** function reports the adapter as present. For example, the [NotifyAddrChange](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-notifyaddrchange) function may indicate a recently disabled adapter's IP address is removed, but **GetAdapterIndex** continues to report an adapter index until the process of disabling the adapter is complete.

When one or more adapters are present on the system, **GetAdapterIndex** returns ERROR_DEV_NOT_EXIST when the adapter being queried does not exist. When no adapters are present, the **GetAdapterIndex** function returns ERROR_NO_DATA.

 The adapter index may change when an adapter is disabled and then enabled, or under other circumstances, and should not be considered persistent.

## See also

[GetAdaptersInfo](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersinfo)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IP_ADAPTER_INFO](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_adapter_info)

[MprConfigGetFriendlyName](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiggetfriendlyname)

[MprConfigGetGuidName](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mprconfiggetguidname)

[NotifyAddrChange](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-notifyaddrchange)