# BeginTransactionGrbit enumeration

Options for [JetBeginTransaction2(JET_SESID, BeginTransactionGrbit)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/api.jetbegintransaction2-method).

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum BeginTransactionGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. |
|  | ReadOnly | The transaction will not modify the database. If an update is attempted, that operation will fail with [TransReadOnly](https://learn.microsoft.com/windows/win32/extensible-storage-engine/hh564840(v=exchg.10).md). This option is ignored unless it is requested when the given session is not already in a transaction. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)