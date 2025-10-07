# RtlGetSuiteMask function

\[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.\]

Retrieves a bit mask that identifies the product suites available on the system. If this function is called in an application that runs in the context of a server silo, the suite mask for the server silo is retrieved instead.

## Parameters

This function has no parameters.

## Return value

A bit mask that identifies the product suites available on the system. The bit mask can include the following values.

| Return value | Description |
|---------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 0x00000001 | Microsoft Small Business Server was once installed on the system, but may have been upgraded to another version of Windows. Refer to the Remarks section for more information about this bit flag.<br> |
| 0x00000002 | Windows 10 Enterprise, Windows 8.1 Enterprise, Windows Server 2008 Enterprise, Windows Server 2003, Enterprise Edition, or Windows 2000 Advanced Server is installed. Refer to the Remarks section for more information about this bit flag.<br> |
| 0x00000004 | Microsoft BackOffice components are installed.<br> |
| 0x00000008 | Communications Server 2003, Communications Server 2005, Communications Server 2007, or Communications Server 2007 R2 is installed.<br> |
| 0x00000010 | Terminal Services is installed. This value is always set.<br> If **TerminalServer** is set but **SingleUserTS** is not set, the system is running in application server mode.<br> |
| 0x00000020 | Microsoft Small Business Server is installed with the restrictive client license in force. Refer to the Remarks section for more information about this bit flag.<br> |
| 0x00000040 | Windows XP Embedded is installed.<br> |
| 0x00000080 | Windows Server 2008 Datacenter, Windows Server 2003, Datacenter Edition, or Windows 2000 Datacenter Server is installed.<br> |
| 0x00000100 | Remote Desktop is supported, but only one interactive session is supported. This value is set unless the system is running in application server mode.<br> |
| 0x00000200 | Windows Vista Home Premium, Windows Vista Home Basic, or Windows XP Home Edition is installed.<br> |
| 0x00000400 | Windows Server 2003, Web Edition is installed.<br> |
| 0x00002000 | Windows Storage Server 2003 R2 or Windows Storage Server 2003 is installed.<br> |
| 0x00004000 | Windows Server 2003, Compute Cluster Edition is installed.<br> |
| 0x00008000 | Windows Home Server is installed.<br> |

## Remarks

You should not rely upon only the 0x00000001 flag to determine whether Small Business Server has been installed on the system, as both this flag and the 0x00000020 flag are set when this product suite is installed. If you upgrade this installation to Windows Server, Standard Edition, the 0x00000020 flag will be cleared however, the 0x00000001 flag will remain set. In this case, this indicates that Small Business Server was once installed on this system. If this installation is further upgraded to Windows Server, Enterprise Edition, the 0x00000001 flag will remain set.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2016 \[desktop apps only\]<br> |
| Header<br> | Ntddk.h |
| Library<br> | Ntdll.lib |
| DLL<br> | Ntdll.dll |

