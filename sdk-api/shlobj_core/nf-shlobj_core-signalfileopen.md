# SignalFileOpen function

## Description

[**SignalFileOpen** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Sends a notification to the Shell that the specified file has been opened.

## Parameters

### `pidl` [in]

Type: **PCIDLIST_ABSOLUTE**

A PIDL that specifies the file.

## Return value

Type: **BOOL**

Returns **TRUE** if successful; otherwise **FALSE**.