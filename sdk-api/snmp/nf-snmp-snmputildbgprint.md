# SnmpUtilDbgPrint function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpUtilDbgPrint** function enables debugging output from the SNMP service. This function is an element of the SNMP Utility API.

## Parameters

### `nLogLevel` [in]

Specifies a signed integer variable that indicates the level of detail of the log event. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SNMP_LOG_SILENT** | Disable all debugging output. |
| **SNMP_LOG_FATAL** | Display fatal errors only. |
| **SNMP_LOG_ERROR** | Display recoverable errors. |
| **SNMP_LOG_WARNING** | Display warnings and recoverable errors. |
| **SNMP_LOG_TRACE** | Display trace information. |
| **SNMP_LOG_VERBOSE** | Display verbose trace information. |

### `szFormat` [in]

Pointer to a null-terminated format string that is similar to the standard C library function **printf** style.

### `...`

Additional parameters.

## Return value

This function does not return a value.

## Remarks

Extension agents are encouraged to use this function during development to enable debug output from the SNMP service.

Use the
[SnmpSvcSetLogLevel](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpsvcsetloglevel) function to set the level of detail of the debug output from the SNMP service or from an extension agent's call to the
**SnmpUtilDbgPrint** function. Call the
[SnmpSvcSetLogType](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpsvcsetlogtype) function to specify the destination for the debug output.

## See also

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpSvcSetLogLevel](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpsvcsetloglevel)

[SnmpSvcSetLogType](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpsvcsetlogtype)