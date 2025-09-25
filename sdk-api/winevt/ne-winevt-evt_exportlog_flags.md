# EVT_EXPORTLOG_FLAGS enumeration

## Description

Defines values that indicate whether the events come from a channel or log file.

## Constants

### `EvtExportLogChannelPath:0x1`

The source of the events is a channel.

### `EvtExportLogFilePath:0x2`

The source of the events is a previously exported log file.

### `EvtExportLogTolerateQueryErrors:0x1000`

Export events even if part of the query generates an error (is not well formed). The service validates the syntax of the XPath query to determine whether it is well formed. If the validation fails, the service parses the XPath into individual expressions. It builds a new XPath beginning with the leftmost expression. The service validates the expression and if it is valid, the service adds the next expression to the XPath. The service repeats this process until it finds the expression that is failing. It then uses the valid expressions as the XPath query (which means that you may not get the events that you expected). If no part of the XPath is valid, the [EvtExportLog](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtexportlog) call fails.

### `EvtExportLogOverwrite:0x2000`

## See also

[EvtExportLog](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtexportlog)