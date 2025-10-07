# JET_wrn enumeration

ESENT warning codes.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
public enum JET_wrn
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | Success | Successful operation. |
|  | RemainingVersions | The version store is still active |
|  | UniqueKey | seek on non-unique index yielded a unique key |
|  | SeparateLongValue | Column is a separated long-value |
|  | ExistingLogFileHasBadSignature | Existing log file has bad signature |
|  | ExistingLogFileIsNotContiguous | Existing log file is not contiguous |
|  | SkipThisRecord | INTERNAL ERROR |
|  | TargetInstanceRunning | TargetInstance specified for restore is running |
|  | CommittedLogFilesLost | One or more logs that were committed to this database, were not recovered. The database is still clean/consistent, as though the lost log's transactions were committed lazily (and lost). |
|  | CommittedLogFilesRemoved | One or more logs that were committed to this database, were no recovered. The database is still clean/consistent, as though the corrupted log's transactions were committed lazily (and lost). |
|  | FinishWithUndo | Signal used by clients to indicate JetInit() finished with undo |
|  | DatabaseRepaired | Database corruption has been repaired |
|  | ColumnNull | Column is NULL-valued |
|  | BufferTruncated | Buffer too small for data |
|  | DatabaseAttached | Database is already attached |
|  | SortOverflow | Sort does not fit in memory |
|  | SeekNotEqual | Exact match not found during seek |
|  | NoErrorInfo | No extended error information |
|  | NoIdleActivity | No idle activity occured |
|  | NoWriteLock | No write lock at transaction level 0 |
|  | ColumnSetNull | Column set to NULL-value |
|  | ShrinkNotPossible | Database file could not be shrunk because there is not enough internal free space available or there is unmovable data present. |
|  | DTCCommitTransaction | Warning code DTC callback should return if the specified transaction is to be committed |
|  | DTCRollbackTransaction | Warning code DTC callback should return if the specified transaction is to be rolled back |
|  | TableEmpty | Opened an empty table |
|  | TableInUseBySystem | System cleanup has a cursor open on the table |
|  | CorruptIndexDeleted | Out of date index removed |
|  | PrimaryIndexOutOfDate | The Primary index is created with an incompatible OS sort version. The table cannot be safely modified. |
|  | SecondaryIndexOutOfDate | One or more Secondary index is created with an incompatible OS sort version. Any index over Unicode text should be deleted. |
|  | ColumnMaxTruncated | Max length too big, truncated |
|  | CopyLongValue | Single instance column bursted |
|  | TaggedColumnsRemaining | RetrieveTaggedColumnList ran out of copy buffer before retrieving all tagged columns |
|  | ColumnSkipped | Column value(s) not returned because the corresponding column id or itagSequence requested for enumeration was null |
|  | ColumnNotLocal | Column value(s) not returned because they could not be reconstructed from the data at hand |
|  | ColumnMoreTags | Column values exist that were not requested for enumeration |
|  | ColumnTruncated | Column value truncated at the requested size limit during enumeration |
|  | ColumnPresent | Column values exist but were not returned by request |
|  | ColumnSingleValue | Column value returned in JET_COLUMNENUM as a result of JET_bitEnumerateCompressOutput |
|  | ColumnDefault | Column value(s) not returned because they were set to their default value(s) and JET_bitEnumerateIgnoreDefault was specified |
|  | ColumnNotInRecord | Column value(s) not returned because they could not be reconstructed from the data in the record |
|  | DataHasChanged | Data has changed |
|  | KeyChanged | Moved to new key |
|  | FileOpenReadOnly | Database file is read only |
|  | IdleFull | Idle registry full |
|  | DefragAlreadyRunning | Online defrag already running on specified database |
|  | DefragNotRunning | Online defrag not running on specified database |
|  | DatabaseScanAlreadyRunning | JetDatabaseScan already running on specified database |
|  | DatabaseScanNotRunning | JetDatabaseScan not running on specified database |
|  | CallbackNotRegistered | Unregistered a non-existant callback function |
|  | PreviousLogFileIncomplete | The log data provided jumped to the next log suddenly, we have deleted the incomplete log file as a precautionary measure |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)