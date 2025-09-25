# SERVICE_CONTROL_STATUS_REASON_PARAMSW structure

## Description

Contains service control parameters.

## Members

### `dwReason`

The reason for changing the service status to SERVICE_CONTROL_STOP. If the current control code is not SERVICE_CONTROL_STOP, this member is ignored.

This member must be set to a combination of one general code, one major reason code, and one minor reason code.

The following are the general reason codes.

| Value | Meaning |
| --- | --- |
| **SERVICE_STOP_REASON_FLAG_CUSTOM**<br><br>0x20000000 | The reason code is defined by the user. If this flag is not present, the reason code is defined by the system. If this flag is specified with a system reason code, the function call fails. <br><br>Users can create custom major reason codes in the range SERVICE_STOP_REASON_MAJOR_MIN_CUSTOM (0x00400000) through SERVICE_STOP_REASON_MAJOR_MAX_CUSTOM (0x00ff0000) and minor reason codes in the range SERVICE_STOP_REASON_MINOR_MIN_CUSTOM (0x00000100) through SERVICE_STOP_REASON_MINOR_MAX_CUSTOM (0x0000FFFF). |
| **SERVICE_STOP_REASON_FLAG_PLANNED**<br><br>0x40000000 | The service stop was planned. |
| **SERVICE_STOP_REASON_FLAG_UNPLANNED**<br><br>0x10000000 | The service stop was not planned. |

The following are the major reason codes.

| Value | Meaning |
| --- | --- |
| **SERVICE_STOP_REASON_MAJOR_APPLICATION**<br><br>0x00050000 | Application issue. |
| **SERVICE_STOP_REASON_MAJOR_HARDWARE**<br><br>0x00020000 | Hardware issue. |
| **SERVICE_STOP_REASON_MAJOR_NONE**<br><br>0x00060000 | No major reason. |
| **SERVICE_STOP_REASON_MAJOR_OPERATINGSYSTEM**<br><br>0x00030000 | Operating system issue. |
| **SERVICE_STOP_REASON_MAJOR_OTHER**<br><br>0x00010000 | Other issue. |
| **SERVICE_STOP_REASON_MAJOR_SOFTWARE**<br><br>0x00040000 | Software issue. |

The following are the minor reason codes.

| Value | Meaning |
| --- | --- |
| **SERVICE_STOP_REASON_MINOR_DISK**<br><br>0x00000008 | Disk. |
| **SERVICE_STOP_REASON_MINOR_ENVIRONMENT**<br><br>0x0000000a | Environment. |
| **SERVICE_STOP_REASON_MINOR_HARDWARE_DRIVER**<br><br>0x0000000b | Driver. |
| **SERVICE_STOP_REASON_MINOR_HUNG**<br><br>0x00000006 | Unresponsive. |
| **SERVICE_STOP_REASON_MINOR_INSTALLATION**<br><br>0x00000003 | Installation. |
| **SERVICE_STOP_REASON_MINOR_MAINTENANCE**<br><br>0x00000002 | Maintenance. |
| **SERVICE_STOP_REASON_MINOR_MMC**<br><br>0x00000016 | MMC issue. |
| **SERVICE_STOP_REASON_MINOR_NETWORK_CONNECTIVITY**<br><br>0x00000011 | Network connectivity. |
| **SERVICE_STOP_REASON_MINOR_NETWORKCARD**<br><br>0x00000009 | Network card. |
| **SERVICE_STOP_REASON_MINOR_NONE**<br><br>0x00060000 | No minor reason. |
| **SERVICE_STOP_REASON_MINOR_OTHER**<br><br>0x00000001 | Other issue. |
| **SERVICE_STOP_REASON_MINOR_OTHERDRIVER**<br><br>0x0000000c | Other driver event. |
| **SERVICE_STOP_REASON_MINOR_RECONFIG**<br><br>0x00000005 | Reconfigure. |
| **SERVICE_STOP_REASON_MINOR_SECURITY**<br><br>0x00000010 | Security issue. |
| **SERVICE_STOP_REASON_MINOR_SECURITYFIX**<br><br>0x0000000f | Security update. |
| **SERVICE_STOP_REASON_MINOR_SECURITYFIX_UNINSTALL**<br><br>0x00000015 | Security update uninstall. |
| **SERVICE_STOP_REASON_MINOR_SERVICEPACK**<br><br>0x0000000d | Service pack. |
| **SERVICE_STOP_REASON_MINOR_SERVICEPACK_UNINSTALL**<br><br>0x00000013 | Service pack uninstall. |
| **SERVICE_STOP_REASON_MINOR_SOFTWARE_UPDATE**<br><br>0x0000000e | Software update. |
| **SERVICE_STOP_REASON_MINOR_SOFTWARE_UPDATE_UNINSTALL**<br><br>0x0000000e | Software update uninstall. |
| **SERVICE_STOP_REASON_MINOR_UNSTABLE**<br><br>0x00000007 | Unstable. |
| **SERVICE_STOP_REASON_MINOR_UPGRADE**<br><br>0x00000004 | Upgrade. |
| **SERVICE_STOP_REASON_MINOR_WMI**<br><br>0x00000012 | WMI issue. |

### `pszComment`

An optional string that provides additional information about the service stop. This string is stored in the event log along with the stop reason code. This member must be **NULL** or a valid string that is less than 128 characters, including the terminating null character.

### `ServiceStatus`

A pointer to a
[SERVICE_STATUS_PROCESS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_status_process) structure that receives the latest service status information. The information returned reflects the most recent status that the service reported to the service control manager.

The service control manager fills in the structure only when
[ControlServiceEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-controlserviceexa) returns one of the following error codes: NO_ERROR, ERROR_INVALID_SERVICE_CONTROL, ERROR_SERVICE_CANNOT_ACCEPT_CTRL, or ERROR_SERVICE_NOT_ACTIVE. Otherwise, the structure is not filled in.

## See also

[ControlServiceEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-controlserviceexa)

[SERVICE_STATUS_PROCESS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_status_process)

## Remarks

> [!NOTE]
> The winsvc.h header defines SERVICE_CONTROL_STATUS_REASON_PARAMS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).