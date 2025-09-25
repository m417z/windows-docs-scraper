# PssCaptureSnapshot function

## Description

Captures a snapshot of a target process.

## Parameters

### `ProcessHandle` [in]

A handle to the target process.

### `CaptureFlags` [in]

Flags that specify what to capture. For more information, see [PSS_CAPTURE_FLAGS](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ne-processsnapshot-pss_capture_flags).

### `ThreadContextFlags` [in, optional]

The **CONTEXT** record flags to capture if *CaptureFlags* specifies thread contexts.

### `SnapshotHandle` [out]

A handle to the snapshot that this function captures.

## Return value

This function returns **ERROR_SUCCESS** on success.

All error codes are defined in winerror.h. Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) with the **FORMAT_MESSAGE_FROM_SYSTEM** flag to get a message for an error code.