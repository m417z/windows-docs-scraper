# DLP_APP_OP_ENLIGHTENED_LEVEL structure

Associates an endpoint Data Loss Prevention (DLP) action with an enforcement level.

## Members

*Operation* \[in\]

A value from the [DlpActionType](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-dlpactiontype) enumeration specifying the endpoint DLP action type.

*AppEnforcementLevel* \[in\]

A value from the [DlpAppEnforceLevel](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-dlpappenforcelevel) specifying the level of enforcement for the associated endpoint DLP action type.

## Remarks

Pass an array of these structures into [DlpInitializeEnforcementMode](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-dlpinitializeenforcementmode) to set the enforcement mode for a set of endpoint DLP operations.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1809 (10.0; Build 17763) |