# SetIndexRangeGrbit enumeration

Options for JetSetIndexRange.

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum SetIndexRangeGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. |
|  | RangeInclusive | This option indicates that the limit of the index range is inclusive. |
|  | RangeUpperLimit | The search key in the cursor represents the search criteria for the index entry closest to the end of the index that will match the index range. |
|  | RangeInstantDuration | The index range should be removed as soon as it has been established. This is useful for testing for the existence of index entries that match the search criteria. |
|  | RangeRemove | Cancel and existing index range. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)