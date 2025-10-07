# DlpAuditBrowserWebsiteOperation function

Generates an ETW event for a browser website operation.

## Parameters

`browserType`: The browser type used for the event being traced.

`eventSource`: The scenario that triggered the event being traced.

`actionType` [in]: The `DlpWebSiteActionType` to trace.

`enforcementLevel` [in]: The enforcement level of the website.

`userBypass` [in]: Indicates the user decision if the `DlpEnforcementLevel` is set to Warn. A value of TRUE indicates that the operation is allowed, a value of FALSE disallows the operation.

`businessJustification` [in]: A business justification for the generated enforcement event.

`source` [in]: The source URL of the event.

`target` [in]: The target to trace. When investigating some operations like Copy to Keyboard, this property can be NULL. For operations such as Print, this might contain a specific structure.

`traceInfoEx` [in]: A reference to a Trace structure. On successful completion, this structure contains the Policy version used for evaluation and the `PolicyRuleID` assigned to the file. This value can be NULL. The caller should call [DlpFreeArchiveFileTraceInfo](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-dlpfreearchivefiletraceinfo) on this structure when done.

`printerOutputFileName` [in]: The printer output file name. Filled only in case `actionType` is `DlpWebSiteActionTypePrint`.

`printerName` [in]: The printer name. Filled only in case `actionType` is `DlpWebSiteActionTypePrint`.

`printerJobName` [in]: The printer job name. Filled only in case `actionType` is `DlpWebSiteActionTypePrint`.

## Return value

Returns an `HRESULT` including, but not limited to, the following values.

| `HRESULT` | Description |
|---------|-------------|
| `S_OK` | The function completed successfully |
| `FAILED`| An unexpected error occurred |

## Remarks

This function can be called from multiple threads.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 11, version 22H2 (10.0; Build 22621) |
| DLL<br> | EndpointDlp.dll |