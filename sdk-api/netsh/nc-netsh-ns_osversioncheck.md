# NS_OSVERSIONCHECK callback function

## Description

The
**NS_OSVERSIONCHECK** command is the operating system check function for helpers. This function can be called on a per-function basis, and verifies whether the associated function is supported on the specified operating system. This function is registered within the
[CMD_GROUP_ENTRY](https://learn.microsoft.com/windows/desktop/api/netsh/ns-netsh-cmd_group_entry) or
[CMD_ENTRY](https://learn.microsoft.com/windows/desktop/api/netsh/ns-netsh-cmd_entry) parameter of the
[RegisterContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-registercontext) function. The following is an example of an operating system check function. Be aware that **SampleOsVersionCheck** is a placeholder for the application-defined function name.

## Parameters

### `CIMOSType` [in]

### `CIMOSProductSuite` [in]

### `CIMOSVersion` [in]

### `CIMOSBuildNumber` [in]

### `CIMServicePackMajorVersion` [in]

### `CIMServicePackMinorVersion` [in]

### `uiReserved`

### `dwReserved` [in]

## Return value

Returns **TRUE** of the command or group should be available, **FALSE** if the command or group should be hidden.

## Remarks

Parameters passed by this function are retrieved from WMI. Refer to the latest
[WMI documentation](https://learn.microsoft.com/windows/desktop/WmiSdk/wmi-reference) to obtain these parameter definitions.

The operating system check function is useful for commands used by administrators who manage down-level servers or computers from a more recent version of Windows.

## See also

[RegisterContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-registercontext)

[Windows WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/wmi-start-page)