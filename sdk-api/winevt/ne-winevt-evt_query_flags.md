# EVT_QUERY_FLAGS enumeration

## Description

Defines the values that specify how to return the query results and whether you are query against a channel or log file.

## Constants

### `EvtQueryChannelPath:0x1`

Specifies that the query is against one or more channels. The *Path* parameter of the [EvtQuery](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtquery) function must specify the name of a channel or **NULL**.

### `EvtQueryFilePath:0x2`

Specifies that the query is against one or more log files. The *Path* parameter of the [EvtQuery](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtquery) function must specify the full path to a log file or **NULL**.

### `EvtQueryForwardDirection:0x100`

Specifies that the events in the query result are ordered from oldest to newest. This is the default.

### `EvtQueryReverseDirection:0x200`

Specifies that the events in the query result are ordered from newest to oldest.

### `EvtQueryTolerateQueryErrors:0x1000`

Specifies that [EvtQuery](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtquery) should run the query even if the part of the query generates an error (is not well formed). The service validates the syntax of the XPath query to determine if it is well formed. If the validation fails, the service parses the XPath into individual expressions. It builds a new XPath beginning with the left most expression. The service validates the expression and if it is valid, the service adds the next expression to the XPath. The service repeats this process until it finds the expression that is failing. It then uses the valid expressions that it found beginning with the leftmost expression as the XPath query (which means that you may not get the events that you expected). If no part of the XPath is valid, the **EvtQuery** call fails.

## Remarks

The EvtQueryChannelPath and EvtQueryFilePath flags are mutually exclusive. The EvtQueryForwardDirection and EvtQueryReverseDirection flags are also mutually exclusive.

You can retrieve events only in a forward direction from Debug and Analytic channels and from .evt and .etl log files.

## See also

[EvtQuery](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtquery)