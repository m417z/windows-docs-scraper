# JET_ERRCAT enumeration

The error category. The hierarchy is as follows: JET_errcatError | |-- JET_errcatOperation | |-- JET_errcatFatal | |-- JET_errcatIO // bad IO issues, may or may not be transient. | |-- JET_errcatResource | |-- JET_errcatMemory // out of memory (all variants) | |-- JET_errcatQuota | |-- JET_errcatDisk // out of disk space (all variants) |-- JET_errcatData | |-- JET_errcatCorruption | |-- JET_errcatInconsistent // typically caused by user Mishandling | |-- JET_errcatFragmentation |-- JET_errcatApi |-- JET_errcatUsage |-- JET_errcatState |-- JET_errcatObsolete

**Namespace:** [Microsoft.Isam.Esent.Interop.Windows8](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop.windows8-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
public enum JET_ERRCAT
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | Unknown | Unknown category. |
|  | Error | A generic category. |
|  | Operation | Errors that can usually happen any time due to uncontrollable conditions. Frequently temporary, but not always. Recovery: Probably retry, or eventually inform the operator. |
|  | Fatal | This sort error happens only when ESE encounters an error condition so grave, that we cannot continue on in a safe (often transactional) way, and rather than corrupt data we throw errors of this category. Recovery: Restart the instance or process. If the problem persists inform the operator. |
|  | IO | O errors come from the OS, and are out of ESE's control, this sort of error is possibly temporary, possibly not. Recovery: Retry. If not resolved, ask operator about disk issue. |
|  | Resource | This is a category that indicates one of many potential out-of-resource conditions. |
|  | Memory | Classic out of memory condition. Recovery: Wait a while and retry, free up memory, or quit. |
|  | Quota | Certain "specialty" resources are in pools of a certain size, making it easier to detect leaks of these resources. Recovery: Might require some minor code changes. Your application should have a debug only action, such as an Assert, on these conditions in order to detect them during development. For retail code, we recommend that you treat this error like the Memory category error and either retry, free up memory, or quit the operation. |
|  | Disk | Out of disk conditions. Recovery: Can retry later in the hope more space is available, or ask the operator to free some disk space. |
|  | Data | A data-related error. |
|  | Corruption | My hard drive ate my homework. Classic corruption issues, frequently permanent without corrective action. Recovery: Restore from backup, perhaps the ese utilities repair operation (which only salvages what data is left / lossy) .Also in the case of recovery(JetInit) perhaps recovery can be performed by allowing data loss. |
|  | Inconsistent | This is similar to Corruption in that the database and/or log files are in a state that is inconsistent and unreconcilable with each other. Often this is caused by application/administrator mishandling. Recovery: Restore from backup, perhaps the ese utilities repair operation (which only salvages what data is left / lossy). Also in the case of recovery(JetInit) perhaps recovery can be performed by allowing data loss. |
|  | Fragmentation | This is a class of errors where some persisted internal resource ran out. Recovery: For database errors, offline defragmentation will rectify the problem, for the log files _first_ recover all attached databases to a clean shutdown, and then delete all the log files and checkpoint. |
|  | Api | A container for Usage and State. |
|  | Usage | Classic usage error, this means the client code did not pass correct arguments to the JET API. This error will likely not go away with retry. Recovery: Generally speaking client code should Assert() this class of errors is not returned, so issues can be caught during development. In retail, the app will probably have little option but to return the issue up to the operator. |
|  | State | This is the classification for different signals the API could return describe the state of the database, a classic case is JET_errRecordNotFound which can be returned by JetSeek() when the record you asked for was not found. Recovery: Not really relevant, depends greatly on the API. |
|  | Obsolete | The error is recognized as a valid error, but is not expected to be returned by this version of the API. |
|  | Max | The maximum value for the enum. This should not be used. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop.Windows8 namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop.windows8-namespace)