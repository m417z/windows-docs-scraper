# JET_err enumeration

ESENT error codes.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
public enum JET_err
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | Success | Successful operation. |
|  | RfsFailure | Resource Failure Simulator failure |
|  | RfsNotArmed | Resource Failure Simulator not initialized |
|  | FileClose | Could not close file |
|  | OutOfThreads | Could not start thread |
|  | TooManyIO | System busy due to too many IOs |
|  | TaskDropped | A requested async task could not be executed |
|  | InternalError | Fatal internal error |
|  | DisabledFunctionality | You are running MinESE, that does not have all features compiled in. This functionality is only supported in a full version of ESE. |
|  | UnloadableOSFunctionality | The desired OS functionality could not be located and loaded / linked. |
|  | DatabaseBufferDependenciesCorrupted | Buffer dependencies improperly set. Recovery failure |
|  | PreviousVersion | Version already existed. Recovery failure |
|  | PageBoundary | Reached Page Boundary |
|  | KeyBoundary | Reached Key Boundary |
|  | BadPageLink | Database corrupted |
|  | BadBookmark | Bookmark has no corresponding address in database |
|  | NTSystemCallFailed | A call to the operating system failed |
|  | BadParentPageLink | Database corrupted |
|  | SPAvailExtCacheOutOfSync | AvailExt cache doesn't match btree |
|  | SPAvailExtCorrupted | AvailExt space tree is corrupt |
|  | SPAvailExtCacheOutOfMemory | Out of memory allocating an AvailExt cache node |
|  | SPOwnExtCorrupted | OwnExt space tree is corrupt |
|  | DbTimeCorrupted | Dbtime on current page is greater than global database dbtime |
|  | KeyTruncated | key truncated on index that disallows key truncation |
|  | DatabaseLeakInSpace | Some database pages have become unreachable even from the avail tree, only an offline defragmentation can return the lost space. |
|  | BadEmptyPage | Database corrupted. Searching an unexpectedly empty page. |
|  | KeyTooBig | Key is too large |
|  | CannotSeparateIntrinsicLV | illegal attempt to separate an LV which must be intrinsic |
|  | SeparatedLongValue | Operation not supported on separated long-value |
|  | MustBeSeparateLongValue | Can only preread long value columns that can be separate, e.g. not size constrained so that they are fixed or variable columns |
|  | InvalidPreread | Cannot preread long values when current index secondary |
|  | InvalidLoggedOperation | Logged operation cannot be redone |
|  | LogFileCorrupt | Log file is corrupt |
|  | NoBackupDirectory | No backup directory given |
|  | BackupDirectoryNotEmpty | The backup directory is not emtpy |
|  | BackupInProgress | Backup is active already |
|  | RestoreInProgress | Restore in progress |
|  | MissingPreviousLogFile | Missing the log file for check point |
|  | LogWriteFail | Failure writing to log file |
|  | LogDisabledDueToRecoveryFailure | Try to log something after recovery faild |
|  | CannotLogDuringRecoveryRedo | Try to log something during recovery redo |
|  | LogGenerationMismatch | Name of logfile does not match internal generation number |
|  | BadLogVersion | Version of log file is not compatible with Jet version |
|  | InvalidLogSequence | Timestamp in next log does not match expected |
|  | LoggingDisabled | Log is not active |
|  | LogBufferTooSmall | Log buffer is too small for recovery |
|  | LogSequenceEnd | Maximum log file number exceeded |
|  | NoBackup | No backup in progress |
|  | InvalidBackupSequence | Backup call out of sequence |
|  | BackupNotAllowedYet | Cannot do backup now |
|  | DeleteBackupFileFail | Could not delete backup file |
|  | MakeBackupDirectoryFail | Could not make backup temp directory |
|  | InvalidBackup | Cannot perform incremental backup when circular logging enabled |
|  | RecoveredWithErrors | Restored with errors |
|  | MissingLogFile | Current log file missing |
|  | LogDiskFull | Log disk full |
|  | BadLogSignature | Bad signature for a log file |
|  | BadDbSignature | Bad signature for a db file |
|  | BadCheckpointSignature | Bad signature for a checkpoint file |
|  | CheckpointCorrupt | Checkpoint file not found or corrupt |
|  | MissingPatchPage | Patch file page not found during recovery |
|  | BadPatchPage | Patch file page is not valid |
|  | RedoAbruptEnded | Redo abruptly ended due to sudden failure in reading logs from log file |
|  | BadSLVSignature |  |
|  | PatchFileMissing | Hard restore detected that patch file is missing from backup set |
|  | DatabaseLogSetMismatch | Database does not belong with the current set of log files |
|  | DatabaseStreamingFileMismatch | Database and streaming file do not match each other |
|  | LogFileSizeMismatch | actual log file size does not match JET_paramLogFileSize |
|  | CheckpointFileNotFound | Could not locate checkpoint file |
|  | RequiredLogFilesMissing | The required log files for recovery is missing. |
|  | SoftRecoveryOnBackupDatabase | Soft recovery is intended on a backup database. Restore should be used instead |
|  | LogFileSizeMismatchDatabasesConsistent | databases have been recovered, but the log file size used during recovery does not match JET_paramLogFileSize |
|  | LogSectorSizeMismatch | the log file sector size does not match the current volume's sector size |
|  | LogSectorSizeMismatchDatabasesConsistent | databases have been recovered, but the log file sector size (used during recovery) does not match the current volume's sector size |
|  | LogSequenceEndDatabasesConsistent | databases have been recovered, but all possible log generations in the current sequence are used; delete all log files and the checkpoint file and backup the databases before continuing |
|  | StreamingDataNotLogged | Illegal attempt to replay a streaming file operation where the data wasn't logged. Probably caused by an attempt to roll-forward with circular logging enabled |
|  | DatabaseDirtyShutdown | Database was not shutdown cleanly. Recovery must first be run to properly complete database operations for the previous shutdown. |
|  | ConsistentTimeMismatch | Database last consistent time unmatched |
|  | DatabasePatchFileMismatch | Patch file is not generated from this backup |
|  | EndingRestoreLogTooLow | The starting log number too low for the restore |
|  | StartingRestoreLogTooHigh | The starting log number too high for the restore |
|  | GivenLogFileHasBadSignature | Restore log file has bad signature |
|  | GivenLogFileIsNotContiguous | Restore log file is not contiguous |
|  | MissingRestoreLogFiles | Some restore log files are missing |
|  | MissingFullBackup | The database missed a previous full backup before incremental backup |
|  | BadBackupDatabaseSize | The backup database size is not in 4k |
|  | DatabaseAlreadyUpgraded | Attempted to upgrade a database that is already current |
|  | DatabaseIncompleteUpgrade | Attempted to use a database which was only partially converted to the current format -- must restore from backup |
|  | MissingCurrentLogFiles | Some current log files are missing for continuous restore |
|  | DbTimeTooOld | dbtime on page smaller than dbtimeBefore in record |
|  | DbTimeTooNew | dbtime on page in advance of the dbtimeBefore in record |
|  | MissingFileToBackup | Some log or patch files are missing during backup |
|  | LogTornWriteDuringHardRestore | torn-write was detected in a backup set during hard restore |
|  | LogTornWriteDuringHardRecovery | torn-write was detected during hard recovery (log was not part of a backup set) |
|  | LogCorruptDuringHardRestore | corruption was detected in a backup set during hard restore |
|  | LogCorruptDuringHardRecovery | corruption was detected during hard recovery (log was not part of a backup set) |
|  | MustDisableLoggingForDbUpgrade | Cannot have logging enabled while attempting to upgrade db |
|  | BadRestoreTargetInstance | TargetInstance specified for restore is not found or log files don't match |
|  | RecoveredWithoutUndo | Soft recovery successfully replayed all operations, but the Undo phase of recovery was skipped |
|  | DatabasesNotFromSameSnapshot | Databases to be restored are not from the same shadow copy backup |
|  | SoftRecoveryOnSnapshot | Soft recovery on a database from a shadow copy backup set |
|  | CommittedLogFilesMissing | One or more logs that were committed to this database, are missing. These log files are required to maintain durable ACID semantics, but not required to maintain consistency if the JET_bitReplayIgnoreLostLogs bit is specified during recovery. |
|  | SectorSizeNotSupported | The physical sector size reported by the disk subsystem, is unsupported by ESE for a specific file type. |
|  | RecoveredWithoutUndoDatabasesConsistent | Soft recovery successfully replayed all operations and intended to skip the Undo phase of recovery, but the Undo phase was not required |
|  | CommittedLogFileCorrupt | One or more logs were found to be corrupt during recovery. These log files are required to maintain durable ACID semantics, but not required to maintain consistency if the JET_bitIgnoreLostLogs bit and JET_paramDeleteOutOfRangeLogs is specified during recovery. |
|  | UnicodeTranslationBufferTooSmall | Unicode translation buffer too small |
|  | UnicodeTranslationFail | Unicode normalization failed |
|  | UnicodeNormalizationNotSupported | OS does not provide support for Unicode normalisation (and no normalisation callback was specified) |
|  | UnicodeLanguageValidationFailure | Cannot validate the language |
|  | ExistingLogFileHasBadSignature | Existing log file has bad signature |
|  | ExistingLogFileIsNotContiguous | Existing log file is not contiguous |
|  | LogReadVerifyFailure | Checksum error in log file during backup |
|  | SLVReadVerifyFailure |  |
|  | CheckpointDepthTooDeep | too many outstanding generations between checkpoint and current generation |
|  | RestoreOfNonBackupDatabase | hard recovery attempted on a database that wasn't a backup database |
|  | LogFileNotCopied | log truncation attempted but not all required logs were copied |
|  | SurrogateBackupInProgress | A surrogate backup is in progress. |
|  | BackupAbortByServer | Backup was aborted by server by calling JetTerm with JET_bitTermStopBackup or by calling JetStopBackup |
|  | InvalidGrbit | Invalid flags parameter |
|  | TermInProgress | Termination in progress |
|  | FeatureNotAvailable | API not supported |
|  | InvalidName | Invalid name |
|  | InvalidParameter | Invalid API parameter |
|  | DatabaseFileReadOnly | Tried to attach a read-only database file for read/write operations |
|  | InvalidDatabaseId | Invalid database id |
|  | OutOfMemory | Out of Memory |
|  | OutOfDatabaseSpace | Maximum database size reached |
|  | OutOfCursors | Out of table cursors |
|  | OutOfBuffers | Out of database page buffers |
|  | TooManyIndexes | Too many indexes |
|  | TooManyKeys | Too many columns in an index |
|  | RecordDeleted | Record has been deleted |
|  | ReadVerifyFailure | Checksum error on a database page |
|  | PageNotInitialized | Blank database page |
|  | OutOfFileHandles | Out of file handles |
|  | DiskReadVerificationFailure | The OS returned ERROR_CRC from file IO |
|  | DiskIO | Disk IO error |
|  | InvalidPath | Invalid file path |
|  | InvalidSystemPath | Invalid system path |
|  | InvalidLogDirectory | Invalid log directory |
|  | RecordTooBig | Record larger than maximum size |
|  | TooManyOpenDatabases | Too many open databases |
|  | InvalidDatabase | Not a database file |
|  | NotInitialized | Database engine not initialized |
|  | AlreadyInitialized | Database engine already initialized |
|  | InitInProgress | Database engine is being initialized |
|  | FileAccessDenied | Cannot access file, the file is locked or in use |
|  | QueryNotSupported | Query support unavailable |
|  | SQLLinkNotSupported | SQL Link support unavailable |
|  | BufferTooSmall | Buffer is too small |
|  | TooManyColumns | Too many columns defined |
|  | ContainerNotEmpty | Container is not empty |
|  | InvalidFilename | Filename is invalid |
|  | InvalidBookmark | Invalid bookmark |
|  | ColumnInUse | Column used in an index |
|  | InvalidBufferSize | Data buffer doesn't match column size |
|  | ColumnNotUpdatable | Cannot set column value |
|  | IndexInUse | Index is in use |
|  | LinkNotSupported | Link support unavailable |
|  | NullKeyDisallowed | Null keys are disallowed on index |
|  | NotInTransaction | Operation must be within a transaction |
|  | MustRollback | Transaction must rollback because failure of unversioned update |
|  | TooManyActiveUsers | Too many active database users |
|  | InvalidCountry | Invalid or unknown country/region code |
|  | InvalidLanguageId | Invalid or unknown language id |
|  | InvalidCodePage | Invalid or unknown code page |
|  | InvalidLCMapStringFlags | Invalid flags for LCMapString() |
|  | VersionStoreEntryTooBig | Attempted to create a version store entry (RCE) larger than a version bucket |
|  | VersionStoreOutOfMemoryAndCleanupTimedOut | Version store out of memory (and cleanup attempt failed to complete) |
|  | VersionStoreOutOfMemory | Version store out of memory (cleanup already attempted) |
|  | CurrencyStackOutOfMemory | UNUSED: lCSRPerfFUCB * g_lCursorsMax exceeded (XJET only) |
|  | CannotIndex | Cannot index escrow column or SLV column |
|  | RecordNotDeleted | Record has not been deleted |
|  | TooManyMempoolEntries | Too many mempool entries requested |
|  | OutOfObjectIDs | Out of btree ObjectIDs (perform offline defrag to reclaim freed/unused ObjectIds) |
|  | OutOfLongValueIDs | Long-value ID counter has reached maximum value. (perform offline defrag to reclaim free/unused LongValueIDs) |
|  | OutOfAutoincrementValues | Auto-increment counter has reached maximum value (offline defrag WILL NOT be able to reclaim free/unused Auto-increment values). |
|  | OutOfDbtimeValues | Dbtime counter has reached maximum value (perform offline defrag to reclaim free/unused Dbtime values) |
|  | OutOfSequentialIndexValues | Sequential index counter has reached maximum value (perform offline defrag to reclaim free/unused SequentialIndex values) |
|  | RunningInOneInstanceMode | Multi-instance call with single-instance mode enabled |
|  | RunningInMultiInstanceMode | Single-instance call with multi-instance mode enabled |
|  | SystemParamsAlreadySet | Global system parameters have already been set |
|  | SystemPathInUse | System path already used by another database instance |
|  | LogFilePathInUse | Logfile path already used by another database instance |
|  | TempPathInUse | Temp path already used by another database instance |
|  | InstanceNameInUse | Instance Name already in use |
|  | InstanceUnavailable | This instance cannot be used because it encountered a fatal error |
|  | DatabaseUnavailable | This database cannot be used because it encountered a fatal error |
|  | InstanceUnavailableDueToFatalLogDiskFull | This instance cannot be used because it encountered a log-disk-full error performing an operation (likely transaction rollback) that could not tolerate failure |
|  | OutOfSessions | Out of sessions |
|  | WriteConflict | Write lock failed due to outstanding write lock |
|  | TransTooDeep | Transactions nested too deeply |
|  | InvalidSesid | Invalid session handle |
|  | WriteConflictPrimaryIndex | Update attempted on uncommitted primary index |
|  | InTransaction | Operation not allowed within a transaction |
|  | RollbackRequired | Must rollback current transaction -- cannot commit or begin a new one |
|  | TransReadOnly | Read-only transaction tried to modify the database |
|  | SessionWriteConflict | Attempt to replace the same record by two diffrerent cursors in the same session |
|  | RecordTooBigForBackwardCompatibility | record would be too big if represented in a database format from a previous version of Jet |
|  | CannotMaterializeForwardOnlySort | The temp table could not be created due to parameters that conflict with JET_bitTTForwardOnly |
|  | SesidTableIdMismatch | This session handle can't be used with this table id |
|  | InvalidInstance | Invalid instance handle |
|  | DirtyShutdown | The instance was shutdown successfully but all the attached databases were left in a dirty state by request via JET_bitTermDirty |
|  | ReadPgnoVerifyFailure | The database page read from disk had the wrong page number. |
|  | ReadLostFlushVerifyFailure | The database page read from disk had a previous write not represented on the page. |
|  | FileSystemCorruption | File system operation failed with an error indicating the file system is corrupt. |
|  | RecoveryVerifyFailure | One or more database pages read from disk during recovery do not match the expected state. |
|  | FilteredMoveNotSupported | Attempted to provide a filter to JetSetCursorFilter() in an unsupported scenario. |
|  | MustCommitDistributedTransactionToLevel0 | Attempted to PrepareToCommit a distributed transaction to non-zero level |
|  | DistributedTransactionAlreadyPreparedToCommit | Attempted a write-operation after a distributed transaction has called PrepareToCommit |
|  | NotInDistributedTransaction | Attempted to PrepareToCommit a non-distributed transaction |
|  | DistributedTransactionNotYetPreparedToCommit | Attempted to commit a distributed transaction, but PrepareToCommit has not yet been called |
|  | CannotNestDistributedTransactions | Attempted to begin a distributed transaction when not at level 0 |
|  | DTCMissingCallback | Attempted to begin a distributed transaction but no callback for DTC coordination was specified on initialisation |
|  | DTCMissingCallbackOnRecovery | Attempted to recover a distributed transaction but no callback for DTC coordination was specified on initialisation |
|  | DTCCallbackUnexpectedError | Unexpected error code returned from DTC callback |
|  | DatabaseDuplicate | Database already exists |
|  | DatabaseInUse | Database in use |
|  | DatabaseNotFound | No such database |
|  | DatabaseInvalidName | Invalid database name |
|  | DatabaseInvalidPages | Invalid number of pages |
|  | DatabaseCorrupted | Non database file or corrupted db |
|  | DatabaseLocked | Database exclusively locked |
|  | CannotDisableVersioning | Cannot disable versioning for this database |
|  | InvalidDatabaseVersion | Database engine is incompatible with database |
|  | Database200Format | The database is in an older (200) format |
|  | Database400Format | The database is in an older (400) format |
|  | Database500Format | The database is in an older (500) format |
|  | PageSizeMismatch | The database page size does not match the engine |
|  | TooManyInstances | Cannot start any more database instances |
|  | DatabaseSharingViolation | A different database instance is using this database |
|  | AttachedDatabaseMismatch | An outstanding database attachment has been detected at the start or end of recovery, but database is missing or does not match attachment info |
|  | DatabaseInvalidPath | Specified path to database file is illegal |
|  | DatabaseIdInUse | A database is being assigned an id already in use |
|  | ForceDetachNotAllowed | Force Detach allowed only after normal detach errored out |
|  | CatalogCorrupted | Corruption detected in catalog |
|  | PartiallyAttachedDB | Database is partially attached. Cannot complete attach operation |
|  | DatabaseSignInUse | Database with same signature in use |
|  | DatabaseCorruptedNoRepair | Corrupted db but repair not allowed |
|  | InvalidCreateDbVersion | recovery tried to replay a database creation, but the database was originally created with an incompatible (likely older) version of the database engine |
|  | DatabaseIncompleteIncrementalReseed | The database cannot be attached because it is currently being rebuilt as part of an incremental reseed. |
|  | DatabaseInvalidIncrementalReseed | The database is not a valid state to perform an incremental reseed. |
|  | DatabaseFailedIncrementalReseed | The incremental reseed being performed on the specified database cannot be completed due to a fatal error. A full reseed is required to recover this database. |
|  | NoAttachmentsFailedIncrementalReseed | The incremental reseed being performed on the specified database cannot be completed because the min required log contains no attachment info. A full reseed is required to recover this database. |
|  | TableLocked | Table is exclusively locked |
|  | TableDuplicate | Table already exists |
|  | TableInUse | Table is in use, cannot lock |
|  | ObjectNotFound | No such table or object |
|  | DensityInvalid | Bad file/index density |
|  | TableNotEmpty | Table is not empty |
|  | InvalidTableId | Invalid table id |
|  | TooManyOpenTables | Cannot open any more tables (cleanup already attempted) |
|  | IllegalOperation | Oper. not supported on table |
|  | TooManyOpenTablesAndCleanupTimedOut | Cannot open any more tables (cleanup attempt failed to complete) |
|  | ObjectDuplicate | Table or object name in use |
|  | InvalidObject | Object is invalid for operation |
|  | CannotDeleteTempTable | Use CloseTable instead of DeleteTable to delete temp table |
|  | CannotDeleteSystemTable | Illegal attempt to delete a system table |
|  | CannotDeleteTemplateTable | Illegal attempt to delete a template table |
|  | ExclusiveTableLockRequired | Must have exclusive lock on table. |
|  | FixedDDL | DDL operations prohibited on this table |
|  | FixedInheritedDDL | On a derived table, DDL operations are prohibited on inherited portion of DDL |
|  | CannotNestDDL | Nesting of hierarchical DDL is not currently supported. |
|  | DDLNotInheritable | Tried to inherit DDL from a table not marked as a template table. |
|  | InvalidSettings | System parameters were set improperly |
|  | ClientRequestToStopJetService | Client has requested stop service |
|  | CannotAddFixedVarColumnToDerivedTable | Template table was created with NoFixedVarColumnsInDerivedTables |
|  | IndexCantBuild | Index build failed |
|  | IndexHasPrimary | Primary index already defined |
|  | IndexDuplicate | Index is already defined |
|  | IndexNotFound | No such index |
|  | IndexMustStay | Cannot delete clustered index |
|  | IndexInvalidDef | Illegal index definition |
|  | InvalidCreateIndex | Invalid create index description |
|  | TooManyOpenIndexes | Out of index description blocks |
|  | MultiValuedIndexViolation | Non-unique inter-record index keys generated for a multivalued index |
|  | IndexBuildCorrupted | Failed to build a secondary index that properly reflects primary index |
|  | PrimaryIndexCorrupted | Primary index is corrupt. The database must be defragmented or the table deleted. |
|  | SecondaryIndexCorrupted | Secondary index is corrupt. The database must be defragmented or the affected index must be deleted. If the corrupt index is over Unicode text, a likely cause a sort-order change. |
|  | InvalidIndexId | Illegal index id |
|  | IndexTuplesSecondaryIndexOnly | tuple index can only be on a secondary index |
|  | IndexTuplesTooManyColumns | tuple index may only have eleven columns in the index |
|  | IndexTuplesNonUniqueOnly | tuple index must be a non-unique index |
|  | IndexTuplesTextBinaryColumnsOnly | tuple index must be on a text/binary column |
|  | IndexTuplesVarSegMacNotAllowed | tuple index does not allow setting cbVarSegMac |
|  | IndexTuplesInvalidLimits | invalid min/max tuple length or max characters to index specified |
|  | IndexTuplesCannotRetrieveFromIndex | cannot call RetrieveColumn() with RetrieveFromIndex on a tuple index |
|  | IndexTuplesKeyTooSmall | specified key does not meet minimum tuple length |
|  | ColumnLong | Column value is long |
|  | ColumnNoChunk | No such chunk in long value |
|  | ColumnDoesNotFit | Field will not fit in record |
|  | NullInvalid | Null not valid |
|  | ColumnIndexed | Column indexed, cannot delete |
|  | ColumnTooBig | Field length is greater than maximum |
|  | ColumnNotFound | No such column |
|  | ColumnDuplicate | Field is already defined |
|  | MultiValuedColumnMustBeTagged | Attempted to create a multi-valued column, but column was not Tagged |
|  | ColumnRedundant | Second autoincrement or version column |
|  | InvalidColumnType | Invalid column data type |
|  | TaggedNotNULL | No non-NULL tagged columns |
|  | NoCurrentIndex | Invalid w/o a current index |
|  | KeyIsMade | The key is completely made |
|  | BadColumnId | Column Id Incorrect |
|  | BadItagSequence | Bad itagSequence for tagged column |
|  | ColumnInRelationship | Cannot delete, column participates in relationship |
|  | CannotBeTagged | AutoIncrement and Version cannot be tagged |
|  | DefaultValueTooBig | Default value exceeds maximum size |
|  | MultiValuedDuplicate | Duplicate detected on a unique multi-valued column |
|  | LVCorrupted | Corruption encountered in long-value tree |
|  | MultiValuedDuplicateAfterTruncation | Duplicate detected on a unique multi-valued column after data was normalized, and normalizing truncated the data before comparison |
|  | DerivedColumnCorruption | Invalid column in derived table |
|  | InvalidPlaceholderColumn | Tried to convert column to a primary index placeholder, but column doesn't meet necessary criteria |
|  | ColumnCannotBeCompressed | Only JET_coltypLongText and JET_coltypLongBinary columns can be compressed |
|  | RecordNotFound | The key was not found |
|  | RecordNoCopy | No working buffer |
|  | NoCurrentRecord | Currency not on a record |
|  | RecordPrimaryChanged | Primary key may not change |
|  | KeyDuplicate | Illegal duplicate key |
|  | AlreadyPrepared | Attempted to update record when record update was already in progress |
|  | KeyNotMade | No call to JetMakeKey |
|  | UpdateNotPrepared | No call to JetPrepareUpdate |
|  | DataHasChanged | Data has changed, operation aborted |
|  | LanguageNotSupported | Windows installation does not support language |
|  | DecompressionFailed | Internal error: data could not be decompressed |
|  | UpdateMustVersion | No version updates only for uncommitted tables |
|  | TooManySorts | Too many sort processes |
|  | InvalidOnSort | Invalid operation on Sort |
|  | TempFileOpenError | Temp file could not be opened |
|  | TooManyAttachedDatabases | Too many open databases |
|  | DiskFull | No space left on disk |
|  | PermissionDenied | Permission denied |
|  | FileNotFound | File not found |
|  | FileInvalidType | Invalid file type |
|  | AfterInitialization | Cannot Restore after init. |
|  | LogCorrupted | Logs could not be interpreted |
|  | InvalidOperation | Invalid operation |
|  | AccessDenied | Access denied |
|  | TooManySplits | Infinite split |
|  | SessionSharingViolation | Multiple threads are using the same session |
|  | EntryPointNotFound | An entry point in a DLL we require could not be found |
|  | SessionContextAlreadySet | Specified session already has a session context set |
|  | SessionContextNotSetByThisThread | Tried to reset session context, but current thread did not orignally set the session context |
|  | SessionInUse | Tried to terminate session in use |
|  | RecordFormatConversionFailed | Internal error during dynamic record format conversion |
|  | OneDatabasePerSession | Just one open user database per session is allowed (JET_paramOneDatabasePerSession) |
|  | RollbackError | error during rollback |
|  | DatabaseAlreadyRunningMaintenance | The operation did not complete successfully because the database is already running maintenance on specified database |
|  | CallbackFailed | A callback failed |
|  | CallbackNotResolved | A callback function could not be found |
|  | SpaceHintsInvalid | An element of the JET space hints structure was not correct or actionable. |
|  | SLVSpaceCorrupted |  |
|  | SLVCorrupted |  |
|  | SLVColumnDefaultValueNotAllowed |  |
|  | SLVStreamingFileMissing |  |
|  | SLVDatabaseMissing |  |
|  | SLVStreamingFileAlreadyExists |  |
|  | SLVInvalidPath |  |
|  | SLVStreamingFileNotCreated |  |
|  | SLVStreamingFileReadOnly |  |
|  | SLVHeaderBadChecksum |  |
|  | SLVHeaderCorrupted |  |
|  | SLVPagesNotFree |  |
|  | SLVPagesNotReserved |  |
|  | SLVPagesNotCommitted |  |
|  | SLVPagesNotDeleted |  |
|  | SLVSpaceWriteConflict |  |
|  | SLVRootStillOpen |  |
|  | SLVProviderNotLoaded |  |
|  | SLVEAListCorrupt |  |
|  | SLVRootNotSpecified |  |
|  | SLVRootPathInvalid |  |
|  | SLVEAListZeroAllocation |  |
|  | SLVColumnCannotDelete |  |
|  | SLVOwnerMapAlreadyExists |  |
|  | SLVOwnerMapCorrupted |  |
|  | SLVOwnerMapPageNotFound |  |
|  | SLVFileStale |  |
|  | SLVFileInUse |  |
|  | SLVStreamingFileInUse |  |
|  | SLVFileIO |  |
|  | SLVStreamingFileFull |  |
|  | SLVFileInvalidPath |  |
|  | SLVFileAccessDenied |  |
|  | SLVFileNotFound |  |
|  | SLVFileUnknown |  |
|  | SLVEAListTooBig |  |
|  | SLVProviderVersionMismatch |  |
|  | SLVBufferTooSmall |  |
|  | OSSnapshotInvalidSequence | OS Shadow copy API used in an invalid sequence |
|  | OSSnapshotTimeOut | OS Shadow copy ended with time-out |
|  | OSSnapshotNotAllowed | OS Shadow copy not allowed (backup or recovery in progress) |
|  | OSSnapshotInvalidSnapId | invalid JET_OSSNAPID |
|  | TooManyTestInjections | Internal test injection limit hit |
|  | TestInjectionNotSupported | Test injection not supported |
|  | InvalidLogDataSequence | Somehow the log data provided got out of sequence with the current state of the instance |
|  | LSCallbackNotSpecified | Attempted to use Local Storage without a callback function being specified |
|  | LSAlreadySet | Attempted to set Local Storage for an object which already had it set |
|  | LSNotSet | Attempted to retrieve Local Storage from an object which didn't have it set |
|  | FileIOSparse | an I/O was issued to a location that was sparse |
|  | FileIOBeyondEOF | a read was issued to a location beyond EOF (writes will expand the file) |
|  | FileIOAbort | instructs the JET_ABORTRETRYFAILCALLBACK caller to abort the specified I/O |
|  | FileIORetry | instructs the JET_ABORTRETRYFAILCALLBACK caller to retry the specified I/O |
|  | FileIOFail | instructs the JET_ABORTRETRYFAILCALLBACK caller to fail the specified I/O |
|  | FileCompressed | read/write access is not supported on compressed files |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)