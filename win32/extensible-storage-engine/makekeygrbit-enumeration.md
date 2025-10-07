# MakeKeyGrbit enumeration

Options for JetMakeKey.

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum MakeKeyGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. |
|  | NewKey | A new search key should be constructed. Any previously existing search key is discarded. |
|  | NormalizedKey | When this option is specified, all other options are ignored, any previously existing search key is discarded, and the contents of the input buffer are loaded as the new search key. |
|  | KeyDataZeroLength | If the size of the input buffer is zero and the current key column is a variable length column, this option indicates that the input buffer contains a zero length value. Otherwise, an input buffer size of zero would indicate a NULL value. |
|  | StrLimit | This option indicates that the search key should be constructed such that any key columns that come after the current key column should be considered to be wildcards. |
|  | SubStrLimit | This option indicates that the search key should be constructed such that the current key column is considered to be a prefix wildcard and that any key columns that come after the current key column should be considered to be wildcards. |
|  | FullColumnStartLimit | The search key should be constructed such that any key columns that come after the current key column should be considered to be wildcards. |
|  | FullColumnEndLimit | The search key should be constructed in such a way that any key columns that come after the current key column are considered to be wildcards. |
|  | PartialColumnStartLimit | The search key should be constructed such that the current key column is considered to be a prefix wildcard and that any key columns that come after the current key column should be considered to be wildcards. |
|  | PartialColumnEndLimit | The search key should be constructed such that the current key column is considered to be a prefix wildcard and that any key columns that come after the current key column should be considered to be wildcards. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)