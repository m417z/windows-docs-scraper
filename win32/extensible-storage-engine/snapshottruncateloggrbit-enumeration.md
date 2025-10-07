# SnapshotTruncateLogGrbit enumeration

Options for [JetOSSnapshotTruncateLog(JET_OSSNAPID, SnapshotTruncateLogGrbit)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/vistaapi.jetossnapshottruncatelog-method) and [JetOSSnapshotTruncateLogInstance(JET_OSSNAPID, JET_INSTANCE, SnapshotTruncateLogGrbit)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/vistaapi.jetossnapshottruncateloginstance-method).

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop.Vista](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop.vista-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum SnapshotTruncateLogGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | No truncation will occur. |
|  | AllDatabasesSnapshot | All the databases are attached so the storage engine can compute and do the log truncation. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop.Vista namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop.vista-namespace)