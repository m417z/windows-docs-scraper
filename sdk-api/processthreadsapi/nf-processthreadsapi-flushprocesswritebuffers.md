# FlushProcessWriteBuffers function

## Description

Flushes the write queue of each processor that is running a thread of the current process.

## Remarks

The function generates an interprocessor interrupt (IPI) to all processors that are part of the current process affinity. It guarantees the visibility of write operations performed on one processor to the other processors.

## See also

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)