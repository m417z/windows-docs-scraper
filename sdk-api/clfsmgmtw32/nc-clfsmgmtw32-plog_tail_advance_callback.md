# PLOG_TAIL_ADVANCE_CALLBACK callback function

## Description

The
**LOG_TAIL_ADVANCE_CALLBACK** function is an application-defined callback function that advances the log tail. The callback is invoked in the context of an asynchronous procedure call (APC) on the thread that registers for log management.

## Parameters

### `hLogFile` [in]

The handle to the log.

### `lsnTarget` [in]

Specifies the log sequence number (LSN) to which the client is advised to advance to or beyond. The *lsnTarget* may not refer to an actual record in the log.

### `pvClientContext` [in]

A pointer to the client context.

## Remarks

This callback can be invoked at any time. This callback function should advance the base LSN of the log to greater than or equal to the value of *lsnTarget*.

## See also

[AdvanceLogBase](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-advancelogbase)

[WriteLogRestartArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-writelogrestartarea)