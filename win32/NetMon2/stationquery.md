# STATIONQUERY structure

The **STATIONQUERY** structure provides information about a specific computer using Network Monitor.

## Members

**Flags**

Flags that Identify the current state of Network Monitor.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------|
| **STATIONQUERY\_FLAGS\_LOADED** | The driver is loaded, but the kernel is not.<br> |
| **STATIONQUERY\_FLAGS\_RUNNING** | The driver is loaded but not capturing data.<br> |
| **STATIONQUERY\_FLAGS\_CAPTURING** | The driver is actively engaged in a capture.<br> |
| **STATIONQUERY\_FLAGS\_TRANSMITTING** | This flag is obsolete.<br> |

**BCDVerMinor**

Minor version number of Network Monitor installed on the computer.

**BCDVerMajor**

Major version number of Network Monitor installed on the computer.

**LicenseNumber**

Software license number.

**MachineName**

Computer manufacturer name, if any.

**UserName**

User name or system identifier.

**Reserved**

Reserved for future use.

**AdapterAddress**

NIC address.

**WMachineName**

Unicode computer name. This member applies to Network Monitor 2.0 or later.

**WUserName**

Unicode user name. This member applies to Network Monitor 2.0 or later.

## Remarks

An array of these structures is used by the [QUERYTABLE](https://learn.microsoft.com/windows/win32/netmon2/querytable) structure to provide a list of the computers that are currently using Network Monitor to capture data.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[QUERYTABLE](https://learn.microsoft.com/windows/win32/netmon2/querytable)

