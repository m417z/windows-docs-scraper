# EdpAuditAction function

> [!NOTE]
> Starting in July 2022, Microsoft is deprecating Windows Information Protection (WIP) and the APIs that support WIP. Microsoft will continue to support WIP on supported versions of Windows. New versions of Windows won't include new capabilities for WIP, and it won't be supported in future versions of Windows. For more information, see [Announcing sunset of Windows Information Protection](https://techcommunity.microsoft.com/t5/windows-it-pro-blog/announcing-the-sunset-of-windows-information-protection-wip/ba-p/3579282).
>
> For your data protection needs, Microsoft recommends that you use [Microsoft Purview Information Protection](https://learn.microsoft.com/microsoft-365/compliance/information-protection) and [Microsoft Purview Data Loss Prevention](https://learn.microsoft.com/microsoft-365/compliance/dlp-learn-about-dlp). Purview simplifies the configuration set-up and provides an advanced set of capabilities.

In the presence of WIP policy, writes an event to the WIP audit log.

## Parameters

### ObjectDescription

Description of data that is being transferred.

### Action

A member of the [EDP_AUDIT_ACTION](https://learn.microsoft.com/windows/win32/devnotes/edp_audit_action-enum) enumeration.

### SourceName

Source of the data (such as application name or email address).

### SourceEID

Enterprise identity of the source data.

### DestinationName

Name of destination (such as application name or email address).

### DestinationEID

Enterprise identity of the destination.

### Application

Unique ID of the application where the transfer took place.

## Return value

An HRESULT value.

## Remarks

This must be called when an application detects data shared from work to personal, for example through copying and pasting.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------|
| Minimum supported client | Windows 10 |
| Minimum supported server | Windows 10 |
| Header | None |
| DLL | edputil.dll |

