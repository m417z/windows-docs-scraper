# FWEnumFirewallRules function

Requests the server to return all the firewall rules contained in the specified store.

See **Remarks** for info about how to call the function.

## Parameters

`hPolicyStore`

An opened policy store **HANDLE** that was successfully opened by using the [FWOpenPolicyStore](https://learn.microsoft.com/windows/win32/ics/firewall/nf-firewall-fwopenpolicystore) function. The handle must have read/write access rights.

`dwFilteredByStatus`

A combination of flags from the **FW_RULE_STATUS_CLASS** enumeration. The function uses this bitmask to determine which rules will be returned. Rules that contain a status code from the class specified by this parameter will be returned.

`dwProfileFilter`

A combination of flags from the **FW_PROFILE_TYPE** enumeration. The function uses this bitmask to determine which rules will be returned. Rules that contain a profile specified by this parameter will be returned.

`wFlags`

A combination of flags from the **FW_ENUM_RULES_FLAGS** enumeration, which modifies the behavior of the function, and performs operations on the rules before returning them.

`pdwNumRules`

This output parameter, if the function completes successfully, is equal to the number of rules returned.

`ppRules`

A pointer to a pointer to an [FW_RULE](https://learn.microsoft.com/windows/win32/ics/firewall/ns-firewall-fw_rule). This output parameter, if the function completes successfully, contains a linked list of [FW_RULE2_27](https://learn.microsoft.com/openspecs/windows_protocols/ms-fasp/a6175371-a526-4e65-a14e-1929fd60dcec) data types.

## Return value

0 if successful. If it fails, it returns a nonzero error code, as specified in [MS-ERREF](https://learn.microsoft.com/openspecs/windows_protocols/ms-erref/1bc92ddf-b79e-413c-bbaa-99a5281a6c90).

## Remarks

This function does not have an associated header file or library file. Your application can call [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) with the DLL name (`FirewallAPI.dll`) to obtain a module handle. It can then call [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) with the module handle and the name of this function to get the function address.

## Requirements

|   |   |
| ---- |:---- |
| **Minimum supported client** | Windows 11, version 23H2 [desktop apps only] |
| **Target Platform** | Windows |
| **Header** | None |
| **Library** | None |
| **DLL** | FirewallAPI.dll |

## See also

* [Windows Firewall with Advanced Security enums and structs](https://learn.microsoft.com/windows/win32/ics/firewall-enums-structs)