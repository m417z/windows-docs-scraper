# INetFwMgr::IsIcmpTypeAllowed

## Description

[The Windows Firewall API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For Windows Vista and later, use of the [Windows Firewall with Advanced Security](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-advanced-security-start-page) API is recommended.]

Determines whether the specified ICMP type is allowed.

## Parameters

### `ipVersion` [in]

IP version of the traffic. This cannot be **NET_FW_IP_VERSION_ANY**.

IP version of the traffic.
This cannot be **NET_FW_IP_VERSION_ANY**.

### `localAddress` [in]

Either a dotted-decimal IPv4 address or an IPv6 hex
address specifying the local address of the traffic. Typically, this is
the address passed to bind. If *localAddress* is **NULL**, the function
determines whether the port is allowed for all interfaces.

### `type` [in]

ICMP type. For a list of possible ICMP types, see [ICMP Type Numbers](https://www.iana.org/assignments/icmp-parameters).

### `allowed` [out]

Indicates by a value of VARIANT_TRUE or VARIANT_FALSE whether the port is allowed for at least some local
interfaces and remote addresses.

### `restricted` [out]

Indicates by a value of VARIANT_TRUE or VARIANT_FALSE whether some local interfaces or remote addresses
are blocked for this port. For example, if the port is restricted to the
local subnet only.

## Return value

### C++

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The operation was stopped because of permissions issues. |
| **E_INVALIDARG** | The method failed because a parameter was not valid. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |
| **E_POINTER** | The method failed because a pointer was not valid. |

### VB

If the method succeeds the return value is **S_OK**.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The operation was stopped because of permissions issues. |
| **E_INVALIDARG** | The method failed because a parameter was not valid. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |
| **E_POINTER** | The method failed because a pointer was not valid. |

## Remarks

The [INetFwPolicy2::IsRuleGroupEnabled](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nf-netfw-inetfwpolicy2-isrulegroupenabled) method is generally recommended in place of this method.

## See also

[INetFwMgr](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwmgr)

[NET_FW_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/icftypes/ne-icftypes-net_fw_ip_version)