# PrereadIndexRangesGrbit enumeration

Options for [JetPrereadIndexRanges(JET_SESID, JET_TABLEID, \[\], Int32, Int32, Int32, \[\], PrereadIndexRangesGrbit)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/windows8api.jetprereadindexranges-method).

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop.Windows8](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop.windows8-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum PrereadIndexRangesGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | Forward | Preread forward. |
|  | Backwards | Preread backwards. |
|  | FirstPageOnly | Preread only first page of any long column. |
|  | NormalizedKey | Normalized key/bookmark provided instead of column value. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop.Windows8 namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop.windows8-namespace)