# EndInkInput function

## Description

Indicates that no more ink will be added to the context.

You cannot add strokes to the context after calling this function.

## Parameters

### `hrc`

The handle to the recognizer context.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | An invalid argument was received. |
| **E_POINTER** | The recognizer context handle is invalid or null. |

## Remarks

The recognition results you receive after calling this function may be different from previous recognition results that were based on partial ink input.

The Ink Analysis API queries for the implementation of this method. If implemented, the InkAnalyzer will call it each time it performs an analysis operation. If not implemented, EndInkInput is never called. Therefore, you should only expose and implement this method if it is explicitly needed by your recognizer.

**Note** This function is not guaranteed to be called by all applications or operating system components, such as the Tablet PC Input Panel. Therefore, recognizers should not rely on it being called.