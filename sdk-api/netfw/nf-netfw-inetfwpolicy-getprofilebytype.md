# INetFwPolicy::GetProfileByType

## Description

[The Windows Firewall API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For Windows Vista and later, use of the [Windows Firewall with Advanced Security](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-advanced-security-start-page) API is recommended.]

Retrieves the profile of the requested type.

## Parameters

### `profileType` [in]

Type of profile from [NET_FW_PROFILE_TYPE](https://learn.microsoft.com/windows/desktop/api/icftypes/ne-icftypes-net_fw_profile_type).

### `profile` [out, ref]

Retrieved profile of type [INetFwProfile](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwprofile).

Retrieved profile of type [INetFwProfile](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwprofile).

## Return value

### C++

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The operation was aborted due to permissions issues. |
| **E_INVALIDARG** | The method failed due to an invalid parameter. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |
| **E_POINTER** | The method failed due to an invalid pointer. |

### VB

If the method succeeds, the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The operation was aborted due to permissions issues. |
| **E_INVALIDARG** | The method failed due to an invalid parameter. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |
| **E_POINTER** | The method failed due to an invalid pointer. |

## See also

[INetFwPolicy](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwpolicy)

[INetFwProfile](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwprofile)

[NET_FW_PROFILE_TYPE](https://learn.microsoft.com/windows/desktop/api/icftypes/ne-icftypes-net_fw_profile_type)