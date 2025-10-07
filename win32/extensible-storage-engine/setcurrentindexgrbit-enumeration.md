# SetCurrentIndexGrbit enumeration

Options for [JetSetCurrentIndex2(JET_SESID, JET_TABLEID, String, SetCurrentIndexGrbit)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/api.jetsetcurrentindex2-method) and [JetSetCurrentIndex3(JET_SESID, JET_TABLEID, String, SetCurrentIndexGrbit, Int32)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/api.jetsetcurrentindex3-method).

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum SetCurrentIndexGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. This is the same as MoveFirst. |
|  | MoveFirst | Indicates that the cursor should be positioned on the first entry of the specified index. If the current index is being selected then this option is ignored. |
|  | NoMove | Indicates that the cursor should be positioned on the index entry of the new index that corresponds to the record associated with the index entry at the current position of the cursor on the old index. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)