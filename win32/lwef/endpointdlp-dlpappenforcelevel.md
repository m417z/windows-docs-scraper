# DlpAppEnforceLevel enumeration

Specifies the enforcement level of an endpoint Data Loss Prevention (DLP) operation.

## Constants

*DlpAppEnforceLevelNone* \[in\]

No enforcement by the app. The DLP system will enforce the operation.

*DlpAppEnforceLevelNotify* \[in\]

Tne app will use the DLP APIs to notify the DLP system about the operation. The DLP system will enforce the operation.

*DlpAppEnforceLevelPrevent* \[in\]

Not supported in the current version.

*DlpAppEnforceLevelFull* \[in\]

Not supported in the current version.

*DlpAppEnforceLevelCount* \[in\]

The maximum value of the enumeration.

## Remarks

Values from this enumeration are used by the [DLP_APP_OP_ENLIGHTENED_LEVEL](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-dlp_app_op_enlightened_level) structure.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1809 (10.0; Build 17763) |