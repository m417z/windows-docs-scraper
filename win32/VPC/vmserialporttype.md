# VMSerialPortType enumeration

\[Windows Virtual PC is no longer available for use as of Windows 8. Instead, use the [Hyper-V WMI provider (V2)](https://learn.microsoft.com/windows/desktop/HyperV_v2/windows-virtualization-portal).\]

Specifies the type of serial port.

## Constants

**vmSerialPort\_HostPort**

A host serial port.

**vmSerialPort\_TextFile**

A host text file.

**vmSerialPort\_NamedPipe**

A named pipe.

**vmSerialPort\_Null**

A **NULL** serial port (discards all bits sent to it).

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| End of client support<br> | Windows 7<br> |
| Product<br> | Windows Virtual PC<br> |
| Header<br> | VPCCOMInterfaces.h |

## See also

[**IVMSerialPort**](https://learn.microsoft.com/windows/win32/vpc/ivmserialport)

