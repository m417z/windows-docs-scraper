# SnapshotPrepareGrbit enumeration

Options for [JetOSSnapshotPrepare(JET_OSSNAPID, SnapshotPrepareGrbit)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/api.jetossnapshotprepare-method).

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum SnapshotPrepareGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. |
|  | IncrementalSnapshot | Only logfiles will be taken. |
|  | CopySnapshot | A copy snapshot (normal or incremental) with no log truncation. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)