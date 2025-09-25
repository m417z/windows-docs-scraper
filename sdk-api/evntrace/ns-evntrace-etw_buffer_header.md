# ETW_BUFFER_HEADER structure

## Description

The header structure of an ETW buffer.

## Members

### `Reserved1`

Reserved.

### `TimeStamp`

The time when the buffer was flushed. It will be in the raw clock type of the session from which the buffer was collected (for example, QueryPerformanceCounter, CPU timestamp counter, or GetSystemTimeAsFileTime).

### `Reserved2`

Reserved.

### `ClientContext`

Contains information about the processor and logger that generated this buffer. See [ETW_BUFFER_CONTEXT](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-etw_buffer_context).

### `Reserved3`

### `FilledBytes`

The size of the valid data in the buffer. This is the size of the ETW_BUFFER_HEADER and the event data. When a buffer is copied, it is common to only allocate enough memory to store the valid data (for example, only FilledBytes bytes are allocated and copied), so recipients of a buffer should not read beyond this offset

### `Reserved4`

Reserved.

## Remarks

## See also