# EvtGetExtendedStatus function

## Description

Gets a text message that contains the extended error information for the current error.

## Parameters

### `BufferSize` [in]

The size of the *Buffer* buffer, in characters.

### `Buffer` [in]

A caller-allocated string buffer that will receive the extended error information. You can set this parameter to **NULL** to determine the required buffer size.

### `BufferUsed` [out]

The size, in characters, of the caller-allocated buffer that the function used or the required buffer size if the function fails with ERROR_INSUFFICIENT_BUFFER.

## Return value

The return value is ERROR_SUCCESS if the call succeeded; otherwise, a Win32 error code.

## Remarks

You must call this function on the thread that generated the error and before calling another Windows Event Log function.

The [EvtQuery](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtquery) and [EvtSubscribe](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsubscribe) functions can provide extended error information if there is a problem with the specified XPath. For example, the error information can identify the character in the XPath where a parsing error occurred. To receive the extended error information for a malformed XPath, you cannot specify the EvtQueryTolerateQueryErrors flag when calling **EvtQuery** or **EvtSubscribe**.