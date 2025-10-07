# DeleteColumnGrbit enumeration

Options for [JetDeleteColumn2(JET_SESID, JET_TABLEID, String, DeleteColumnGrbit)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/api.jetdeletecolumn2-method).

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum DeleteColumnGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. |
|  | IgnoreTemplateColumns | The API should only attempt to delete columns in the derived table. If a column of that name exists in the base table it will be ignored. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)