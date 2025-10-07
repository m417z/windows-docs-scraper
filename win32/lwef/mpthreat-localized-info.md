# MPTHREAT\_LOCALIZED\_INFO structure

Localized information for a threat.

## Members

**ThreatID**

Type: **MPTHREAT\_ID**

Threat identifier. Upper bit is set to identify antivirus-related threats.

**CategoryName**

Type: **MP\_MIDL\_STRING LPWSTR**

Threat classification, such as a trojan or a keylogger.

**CategoryDescription**

Type: **MP\_MIDL\_STRING LPWSTR**

Description of threat category.

**SeverityName**

Type: **MP\_MIDL\_STRING LPWSTR**

Threat severity level, such as severe or moderate.

**SeverityDescription**

Type: **MP\_MIDL\_STRING LPWSTR**

Description of threat severity level.

**ShortDescription**

Type: **MP\_MIDL\_STRING LPWSTR**

Short description of threat.

**DefaultActionName;**

Type: **MP\_MIDL\_STRING LPWSTR**

Name of default action, such as remove or quarantine, suggested by engine.

**Advice**

Type: **MP\_MIDL\_STRING LPWSTR**

Advice for the particular threat.

**ThreatUrl**

Type: **MP\_MIDL\_STRING LPWSTR**

A URL to a webpage containing information about the threat.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |