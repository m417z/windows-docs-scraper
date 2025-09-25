## Description

Defines the reason for locking the System Monitor.

## Constants

### `sysmonBatchNone:0`

Use to free all locks. Typically, you call [SystemMonitor.BatchingLock](https://learn.microsoft.com/windows/desktop/SysMon/systemmonitor-batchinglock) with the same reason you used to gain the lock. For example, if you gained the lock using SysmonBatchAddFiles, you would use SysmonBatchAddFiles when releasing the lock.

### `sysmonBatchAddFiles:1`

Prevents the System Monitor from sampling the file immediately when you use [ILogFiles.Add](https://learn.microsoft.com/windows/desktop/SysMon/systemmonitor-logfiles-add) to add a log file to the
collection.

### `sysmonBatchAddCounters:2`

Prevents the System Monitor from sampling the counter immediately when you use [ICounters.Add](https://learn.microsoft.com/windows/desktop/SysMon/counters-add) to add a counter to the collection.

### `sysmonBatchAddFilesAutoCounters:3`

TBD

## See also

[SystemMonitor.BatchingLock](https://learn.microsoft.com/windows/desktop/SysMon/systemmonitor-batchinglock)