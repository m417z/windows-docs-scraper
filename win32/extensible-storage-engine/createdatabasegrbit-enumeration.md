# CreateDatabaseGrbit enumeration

Options for [JetCreateDatabase(JET_SESID, String, String, JET_DBID, CreateDatabaseGrbit)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/api.jetcreatedatabase-method).

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum CreateDatabaseGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. |
|  | OverwriteExisting | By default, if JetCreateDatabase is called and the database already exists, the Api call will fail and the original database will not be overwritten. OverwriteExisting changes this behavior, and the old database will be overwritten with a new one. |
|  | RecoveryOff | Turns off logging. Setting this bit loses the ability to replay log files and recover the database to a consistent usable state after a crash. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)