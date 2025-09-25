# OperationStart function

## Description

Notifies the system that the application is about to start an operation.

 If an application calls **OperationStart** with a valid [OPERATION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/oprec/operation-id) value, the system records the specified operation’s file access patterns until [OperationEnd](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-operationend) is called for the same operation ID. This record is stored in a *filename.pf* prefetch file. Every call to **OperationStart** must be followed by a call to **OperationEnd**, otherwise the operation's record is discarded after 10 seconds.

If an application calls **OperationStart** for an operation ID for which a prefetch file exists, the system loads the operation's files into memory prior to running the operation. The recording process remains the same and the system updates the appropriate *filename.pf* prefetch file.

## Parameters

### `OperationStartParams` [in]

An [_OPERATION_START_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-operation_start_parameters) structure that specifies **VERSION**, **OPERATION_ID** and **FLAGS**.

## Return value

**TRUE** for all valid parameters and **FALSE** otherwise. To get extended error information, call **GetLastError**.

## Remarks

The version of the [_OPERATION_START_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-operation_start_parameters) structure is defined as **OPERATION_API_VERSION** in the Windows SDK.

Because the **OperationStart** function is synchronous, it can take several seconds to return. This should be avoided in UI threads for the best responsiveness.

There is a single instance of the operation recorder in a process. Although the operation recorder APIs can be called from multiple threads within the process, all calls act on the single instance.

Application launch tracing lasts for the first 10 second of the process lifetime. **OperationStart** should be called after the end of application launch tracing by the system.

Every call to **OperationStart** must be followed by a call to [OperationEnd](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-operationend). Otherwise, the operation trace will be discarded after about 10s.

The maximum number of operations that can be recorded on a given system is configurable. If this maximum is exceeded, the least recently used prefetch files are replaced.

On Windows 8, this functionality requires the Superfetch service to be enabled. Windows 8 will have the service enabled by default.
For Windows Server 2012, this prefetching functionality needs to be enabled and disabled as required. This can be done using CIM based PowerShell cmdlets. The prefetcher functionality can be exposed using the [CIM class](https://learn.microsoft.com/windows/desktop/WmiSdk/cimclas) of the **CIM_PrefetcherService**.

#### Examples

``` syntax
    BOOL Success;
    DWORD ErrorCode;
    OPERATION_START_PARAMETERS OpStart;
    OPERATION_END_PARAMETERS OpEnd;

    // We want to notify Windows that we are going to be performing some
    // disk-bound work that repeatedly access the same file data. The system will
    // try to record data about our activity to make future operations faster.

    ZeroMemory(&OpStart, sizeof(OpStart));
    OpStart.Version = OPERATION_API_VERSION;
    OpStart.OperationId = MY_OPERATION_ID_1;

    ZeroMemory(&OpEnd, sizeof(OpEnd));
    OpEnd.Version = OPERATION_API_VERSION;
    OpEnd.OperationId = MY_OPERATION_ID_1;

    // We want the system to only record activity in this thread.

    OpStart.Flags = OPERATION_START_TRACE_CURRENT_THREAD;
    OpEnd.Flags = 0;

    Success = OperationStart(&OpStart);

    if (!Success) {
        ErrorCode = GetLastError();
        fprintf(stderr, "OperationStart failed: %d\n", ErrorCode);

        // We could not notify the system about our operation. That's OK.

                  }

    // Perform the disk-bound work that should be recorded here.
    // This may involve opening/reading many files or loading
    // and running many DLLs.

    Success = OperationEnd(&OpEnd);

    if (!Success) {
        fprintf(stderr, "OperationEnd failed: %d\n", GetLastError());
                  }

```

## See also

[OPERATION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/oprec/operation-id)

[Operation Recorder](https://learn.microsoft.com/previous-versions/windows/desktop/oprec/-operation-portal)

[OperationEnd](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-operationend)

[_OPERATION_END_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-operation_end_parameters)

[_OPERATION_START_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-operation_start_parameters)