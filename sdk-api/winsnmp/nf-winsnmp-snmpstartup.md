# SnmpStartup function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The
**SnmpStartup** function notifies the Microsoft WinSNMP implementation that the WinSNMP application requires the implementation's services. The WinSNMP
**SnmpStartup** function enables the implementation to initialize and to return to the application the version of the Windows SNMP Application Programming Interface (WinSNMP API), the level of SNMP communications that the implementation supports, and the implementation's default translation and retransmission modes.

**Note** A WinSNMP application must call the
**SnmpStartup** function successfully before it calls any other WinSNMP function.

## Parameters

### `nMajorVersion` [out]

Pointer to an unsigned long integer variable to receive the major version number of the WinSNMP API that the implementation supports. For example, to indicate that the implementation supports WinSNMP version 2.0, the function returns a value of 2.

### `nMinorVersion` [out]

Pointer to an unsigned long integer variable to receive the minor version number of the WinSNMP API that the implementation supports. For example, to indicate that the implementation supports WinSNMP version 2.0, the function returns a value of 0.

### `nLevel` [out]

Pointer to an unsigned long integer variable to receive the highest level of SNMP communications the implementation supports. Upon successful return, this parameter contains a value of 2. For a description of level 2 support, see
[Levels of SNMP Support](https://learn.microsoft.com/windows/desktop/SNMP/levels-of-snmp-support).

### `nTranslateMode` [out]

Pointer to an unsigned long integer variable to receive the default translation mode in effect for the implementation. The translation mode applies to the implementation's interpretation of the *entity* parameter that the WinSNMP application passes to the
[SnmpStrToEntity](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstrtoentity) function. The translation mode also applies to the *string* parameter that the WinSNMP application passes to the
[SnmpStrToContext](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstrtocontext) function. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SNMPAPI_TRANSLATED** | The implementation uses its database to translate user-friendly names for SNMP entities and managed objects. The implementation translates them into their SNMPv1 or SNMPv2C components. |
| **SNMPAPI_UNTRANSLATED_V1** | The implementation interprets SNMP entity parameters as SNMP transport addresses, and context parameters as SNMP community strings. For SNMPv2 destination entities, the implementation creates outgoing SNMP messages that contain a value of zero in the version field. |
| **SNMPAPI_UNTRANSLATED_V2** | The implementation interprets SNMP entity parameters as SNMP transport addresses, and context parameters as SNMP community strings. For SNMPv2 destination entities, the implementation creates outgoing SNMP messages that contain a value of 1 in the version field. |

For additional information, see
[Setting the Entity and Context Translation Mode](https://learn.microsoft.com/windows/desktop/SNMP/setting-the-entity-and-context-translation-mode).

### `nRetransmitMode` [out]

Pointer to an unsigned long integer variable to receive the default retransmission mode in effect for the implementation. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SNMPAPI_OFF** | The implementation is not executing the retransmission policy of the WinSNMP application. |
| **SNMPAPI_ON** | The implementation is executing the retransmission policy of the WinSNMP application. |

For additional information, see
[About Retransmission](https://learn.microsoft.com/windows/desktop/SNMP/about-retransmission).

## Return value

If the function succeeds, the return value is SNMPAPI_SUCCESS, and the parameters contain appropriate values, as indicated in the preceding parameter descriptions.

If the function fails, the return value is SNMPAPI_FAILURE. To get extended error information, call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror) specifying a **NULL** value in its *session* parameter. The
**SnmpGetLastError** function can return one of the following errors. For additional information, see the Remarks section that follows.

| Return code | Description |
| --- | --- |
| **SNMPAPI_NOT_INITIALIZED** | The **SnmpStartup** function did not complete successfully. |
| **SNMPAPI_ALLOC_ERROR** | An error occurred during memory allocation. |
| **SNMPAPI_OTHER_ERROR** | An unknown or undefined error occurred. |

## Remarks

A WinSNMP application must call the
**SnmpStartup** function successfully at least once, before it calls any other WinSNMP function. If a WinSNMP application does call another WinSNMP function, before it successfully calls
**SnmpStartup**, the implementation returns the error SNMPAPI_NOT_INITIALIZED.

The WinSNMP application can call
[SnmpGetLastError](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpgetlasterror) for error information, or retry
**SnmpStartup** if a call to the
**SnmpStartup** function fails. When
**SnmpStartup** returns SNMPAPI_FAILURE, and a subsequent call to
**SnmpGetLastError** returns SNMP_ALLOC_ERROR, the WinSNMP application can elect to wait. It can retry the call to
**SnmpStartup** when the implementation has adequate free resources.

A WinSNMP application can call
**SnmpStartup** multiple times. For example, it may need to retry the function call for the reasons discussed preceding. A WinSNMP application must also call
[SnmpCleanup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcleanup) at least once, as the last WinSNMP function call before it terminates. Multiple
**SnmpStartup** calls do not require multiple
**SnmpCleanup** calls.

For additional information, see
[Levels of SNMP Support](https://learn.microsoft.com/windows/desktop/SNMP/levels-of-snmp-support) and
[About SNMP Versions](https://learn.microsoft.com/windows/desktop/SNMP/about-snmp-versions).

## See also

[SnmpCleanup](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcleanup)

[SnmpStrToContext](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstrtocontext)

[SnmpStrToEntity](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpstrtoentity)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)