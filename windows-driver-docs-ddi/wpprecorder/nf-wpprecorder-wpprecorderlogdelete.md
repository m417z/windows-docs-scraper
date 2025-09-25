# WppRecorderLogDelete macro

## Description

The [WppRecorderLogDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wpprecorder/nf-wpprecorder-wpprecorderlogdelete) method deletes the specified recorder log.

## Parameters

### `RecorderLog` [in]

Handle to the recorder log to delete.

## Remarks

When a thread enters this function, no threads can subsequently log to this buffer.