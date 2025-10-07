# CommitTransactionGrbit enumeration

Options for JetCommitTransaction.

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum CommitTransactionGrbit
```

## Members

| Member name | Description |
|-------------|-------------|
| None | Default options. |
| LazyFlush | The transaction is committed normally but this Api does not wait for the transaction to be flushed to the transaction log file before returning to the caller. This drastically reduces the duration of a commit operation at the cost of durability. Any transaction that is not flushed to the log before a crash will be automatically aborted during crash recovery during the next call to JetInit. If WaitLastLevel0Commit or WaitAllLevel0Commit are specified, this option is ignored. |
| WaitLastLevel0Commit | If the session has previously committed any transactions and they have not yet been flushed to the transaction log file, they should be flushed immediately. This Api will wait until the transactions have been flushed before returning to the caller. This is useful if the application has previously committed several transactions using JET_bitCommitLazyFlush and now wants to flush all of them to disk.

This option may be used even if the session is not currently in a transaction. This option cannot be used in combination with any other option.

|

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)