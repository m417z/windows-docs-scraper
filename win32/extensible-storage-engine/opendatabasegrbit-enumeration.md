# OpenDatabaseGrbit enumeration

Options for [JetOpenDatabase(JET_SESID, String, String, JET_DBID, OpenDatabaseGrbit)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/api.jetopendatabase-method).

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum OpenDatabaseGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. |
|  | ReadOnly | Prevents modifications to the database. |
|  | Exclusive | Allows only a single session to attach a database. Normally, several sessions can open a database. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)