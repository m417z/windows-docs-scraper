# ResizeDatabaseGrbit enumeration

Options for [JetResizeDatabase(JET_SESID, JET_DBID, Int32, Int32, ResizeDatabaseGrbit)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/windows8api.jetresizedatabase-method).

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop.Windows8](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop.windows8-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum ResizeDatabaseGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | No option. |
|  | OnlyGrow | Only grow the database. If the resize call would shrink the database, do nothing. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop.Windows8 namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop.windows8-namespace)