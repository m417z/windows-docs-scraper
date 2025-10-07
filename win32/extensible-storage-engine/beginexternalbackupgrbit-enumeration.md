# BeginExternalBackupGrbit enumeration

Options for [JetBeginExternalBackupInstance(JET_INSTANCE, BeginExternalBackupGrbit)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/api.jetbeginexternalbackupinstance-method).

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum BeginExternalBackupGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. |
|  | Incremental | Creates an incremental backup as opposed to a full backup. This means that only the log files since the last full or incremental backup will be backed up. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)