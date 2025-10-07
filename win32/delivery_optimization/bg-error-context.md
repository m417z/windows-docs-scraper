# BG_ERROR_CONTEXT enumeration

The **BG_ERROR_CONTEXT** enumeration defines the constant values that specify the context in which the error occurred.

## Constants

**BG_ERROR_CONTEXT_NONE**

An error has not occurred.

**BG_ERROR_CONTEXT_UNKNOWN**

Not supported.

**BG_ERROR_CONTEXT_GENERAL_QUEUE_MANAGER**

Not supported.

**BG_ERROR_CONTEXT_QUEUE_MANAGER_NOTIFICATION**

Not supported.

**BG_ERROR_CONTEXT_LOCAL_FILE**

Not supported.

**BG_ERROR_CONTEXT_REMOTE_FILE**

The error was related to the specified remote file. For example, the URL was not accessible.

**BG_ERROR_CONTEXT_GENERAL_TRANSPORT**

Not supported.

**BG_ERROR_CONTEXT_REMOTE_APPLICATION**

Not supported.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1709 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server, version 1709 \[desktop apps only\]<br> |
| Header<br> | Deliveryoptimization.h |

## See also

[**IBackgroundCopyError::GetError**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyerror-geterror-method)

