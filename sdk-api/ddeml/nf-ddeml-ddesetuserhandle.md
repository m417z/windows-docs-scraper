# DdeSetUserHandle function

## Description

Associates an application-defined value with a conversation handle or a transaction identifier. This is useful for simplifying the processing of asynchronous transactions. An application can use the [DdeQueryConvInfo](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddequeryconvinfo) function to retrieve this value.

## Parameters

### `hConv` [in]

Type: **HCONV**

A handle to the conversation.

### `id` [in]

Type: **DWORD**

The transaction identifier to associate with the value specified by the
*hUser* parameter. An application should set this parameter to QID_SYNC to associate
*hUser* with the conversation identified by the
*hConv* parameter.

### `hUser` [in]

Type: **DWORD_PTR**

The value to be associated with the conversation handle.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

The [DdeGetLastError](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddegetlasterror) function can be used to get the error code, which can be one of the following values:

## See also

**Conceptual**

[DdeQueryConvInfo](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddequeryconvinfo)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

**Reference**