# SnmpSvcSetLogType function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpSvcSetLogType** function adjusts the destination for the debug output from the SNMP service and from SNMP extension agents using the
[SnmpUtilDbgPrint](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputildbgprint) function. This function is an element of the SNMP Utility API.

## Parameters

### `nLogType` [in]

Specifies a signed integer variable that represents the destination for the debug output from the
[SnmpUtilDbgPrint](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputildbgprint) function. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SNMP_OUTPUT_TO_CONSOLE** | The destination for the debug output is a console window. |
| **SNMP_OUTPUT_TO_LOGFILE** | The destination for the debug output is the SNMPDBG.LOG file in the SYSTEM32 directory. |
| **SNMP_OUTPUT_TO_DEBUGGER** | The destination for the debug output is a debugger utility. |

## Return value

This function does not return a value.

## Remarks

Extension agents are encouraged to use the
**SnmpSvcSetLogType** and
[SnmpSvcSetLogLevel](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpsvcsetloglevel) functions during development to adjust the output of debugging information. Extension agents can integrate the information with the debug output from the SNMP service.

## See also

[SNMP Functions](https://learn.microsoft.com/windows/desktop/SNMP/snmp-functions)

[Simple Network Management Protocol (SNMP) Overview](https://learn.microsoft.com/windows/desktop/SNMP/simple-network-management-protocol-snmp-)

[SnmpSvcSetLogLevel](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmpsvcsetloglevel)

[SnmpUtilDbgPrint](https://learn.microsoft.com/windows/desktop/api/snmp/nf-snmp-snmputildbgprint)