# SnmpSvcSetLogLevel function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpSvcSetLogLevel** function adjusts the level of detail of the debug output from the SNMP service and from SNMP extension agents using the
[SnmpUtilDbgPrint](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputildbgprint) function. This function is an element of the SNMP Utility API.

## Parameters

### `nLogLevel` [in]

Specifies a signed integer variable that indicates the level of detail of the debug output from the
[SnmpUtilDbgPrint](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputildbgprint) function. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SNMP_LOG_SILENT** | Disable all debugging output. |
| **SNMP_LOG_FATAL** | Display fatal errors only. |
| **SNMP_LOG_ERROR** | Display recoverable errors. |
| **SNMP_LOG_WARNING** | Display warnings and recoverable errors. |
| **SNMP_LOG_TRACE** | Display trace information. |
| **SNMP_LOG_VERBOSE** | Display verbose trace information. |

## Return value

This function does not return a value.

## Remarks

Extension agents are encouraged to use the
[SnmpSvcSetLogType](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpsvcsetlogtype) and
**SnmpSvcSetLogLevel** functions during development to adjust the output of debugging information. Extension agents can integrate the information with the debug output from the SNMP service.

## See also

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpSvcSetLogType](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpsvcsetlogtype)

[SnmpUtilDbgPrint](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputildbgprint)