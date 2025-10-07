# LsGrbit enumeration

Options for [JetSetLS(JET_SESID, JET_TABLEID, JET_LS, LsGrbit)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/api.jetsetls-method) and [JetGetLS(JET_SESID, JET_TABLEID, JET_LS, LsGrbit)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/api.jetgetls-method).

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum LsGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. |
|  | Reset | The context handle for the chosen object should be reset to JET_LSNil. |
|  | Cursor | Specifies the context handle should be associated with the given cursor. |
|  | Table | Specifies that the context handle should be associated with the table associated with the given cursor. It is illegal to use this option with Cursor. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)