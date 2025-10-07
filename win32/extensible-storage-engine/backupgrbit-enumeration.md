# BackupGrbit enumeration

Options for [JetBackupInstance(JET_INSTANCE, String, BackupGrbit, JET_PFNSTATUS)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/api.jetbackupinstance-method).

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum BackupGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. |
|  | Incremental | Creates an incremental backup as opposed to a full backup. This means that only the log files created since the last full or incremental backup will be backed up. |
|  | Atomic | Creates a full backup of the database. This allows the preservation of an existing backup in the same directory if the new backup fails. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)