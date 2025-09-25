# RtlCaptureStackBackTrace function

## Description

The **RtlCaptureStackBackTrace** routine captures a stack back trace by walking up the stack and recording the information for each frame.

## Parameters

### `FramesToSkip` [in]

The number of frames to skip from the start of the back trace.

### `FramesToCapture` [in]

The number of frames to be captured.

### `BackTrace` [out]

An array of pointers captured from the current stack trace.

### `BackTraceHash` [out, optional]

An optional value that can be used to organize hash tables. If this parameter is **NULL**, no hash value is computed.

This value is calculated based on the values of the pointers returned in the *BackTrace* array. Two identical stack traces will generate identical hash values.

## Return value

The number of captured frames.