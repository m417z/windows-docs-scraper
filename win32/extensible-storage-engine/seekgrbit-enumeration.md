# SeekGrbit enumeration

Options for JetSeek.

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum SeekGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | SeekEQ | The cursor will be positioned at the index entry closest to the start of the index that exactly matches the search key. |
|  | SeekLT | The cursor will be positioned at the index entry closest to the end of the index that is less than an index entry that would exactly match the search criteria. |
|  | SeekLE | The cursor will be positioned at the index entry closest to the end of the index that is less than or equal to an index entry that would exactly match the search criteria. |
|  | SeekGE | The cursor will be positioned at the index entry closest to the start of the index that is greater than or equal to an index entry that would exactly match the search criteria. |
|  | SeekGT | The cursor will be positioned at the index entry closest to the start of the index that is greater than an index entry that would exactly match the search criteria. |
|  | SetIndexRange | An index range will automatically be setup for all keys that exactly match the search key. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)