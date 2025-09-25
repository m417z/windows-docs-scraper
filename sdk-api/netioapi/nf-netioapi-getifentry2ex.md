# GetIfEntry2Ex function

## Description

The
**GetIfEntry2Ex** function retrieves the specified level of information for the specified interface on the local computer.

## Parameters

### `Level` [in]

The level of interface information to retrieve. This parameter can be one of the values from the **MIB_IF_ENTRY_LEVEL** enumeration type defined in the *Netioapi.h* header file.

| Value | Meaning |
| --- | --- |
| **MibIfEntryNormal**<br><br>0 | The values of statistics and state returned in members of the [MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2) structure pointed to by the *Row* parameter are returned from the top of the filter stack. |
| **MibIfEntryNormalWithoutStatistics**<br><br>2 | The values of state (without statistics) returned in members of the [MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2) structure pointed to by the *Row* parameter are returned from the top of the filter stack. |

### `Row` [in, out]

A pointer to a
[MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2) structure that, on successful return, receives information for an interface on the local computer. On input, the **InterfaceLuid** or the **InterfaceIndex** member of the **MIB_IF_ROW2** must be set to the interface for which to retrieve information.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_FILE_NOT_FOUND** | The system cannot find the file specified. This error is returned if the network interface LUID or interface index specified by the **InterfaceLuid** or **InterfaceIndex** member of the [MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2) pointed to by the *Row* parameter was not a value on the local machine. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** parameter is passed in the *Row* parameter. This error is also returned if the both the **InterfaceLuid** and **InterfaceIndex** member of the [MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2) pointed to by the *Row* parameter are unspecified. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The
**GetIfEntry2Ex** function retrieves information for a specified interface on a local system and returns this information in a pointer to a
[MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2) structure. **GetIfEntry2Ex** is an enhanced version of the [GetIfEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getifentry2) function that allows selecting the level of interface information to retrieve.

On input, at least one of the following members in the [MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2) structure passed in the *Row* parameter must be initialized: **InterfaceLuid** or **InterfaceIndex**.

The fields are used in the order listed above. So if the **InterfaceLuid** is specified, then this member is used to determine the interface. If no value was set for the **InterfaceLuid** member (the value of this member was set to zero), then the **InterfaceIndex** member is next used to determine the interface.

On output, the remaining fields of the [MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2) structure pointed to by the *Row* parameter are filled in.

Note that the *Netioapi.h* header file is automatically included in *Iphlpapi.h* header file, and should never be used directly.

## See also

**GetIfEntry**

[GetIfEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getifentry2)

[GetIfTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getiftable)

[GetIfTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2)

[GetIfTable2Ex](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2ex)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[MIB_IFROW](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_ifrow)

[MIB_IFTABLE](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_iftable)

[MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2)

[MIB_IF_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_table2)