# RetrieveColumnGrbit enumeration

Options for JetRetrieveColumn.

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum RetrieveColumnGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. |
|  | RetrieveCopy | This flag causes retrieve column to retrieve the modified value instead of the original value. If the value has not been modified, then the original value is retrieved. In this way, a value that has not yet been inserted or updated may be retrieved during the operation of inserting or updating a record. |
|  | RetrieveFromIndex | This option is used to retrieve column values from the index, if possible, without accessing the record. In this way, unnecessary loading of records can be avoided when needed data is available from index entries themselves. |
|  | RetrieveFromPrimaryBookmark | This option is used to retrieve column values from the index bookmark, and may differ from the index value when a column appears both in the primary index and the current index. This option should not be specified if the current index is the clustered, or primary, index. This bit cannot be set if RetrieveFromIndex is also set. |
|  | RetrieveTag | This option is used to retrieve the sequence number of a multi-valued column value in JET_RETINFO.itagSequence. Retrieving the sequence number can be a costly operation and should only be done if necessary. |
|  | RetrieveNull | This option is used to retrieve multi-valued column NULL values. If this option is not specified, multi-valued column NULL values will automatically be skipped. |
|  | RetrieveIgnoreDefault | This option affects only multi-valued columns and causes a NULL value to be returned when the requested sequence number is 1 and there are no set values for the column in the record. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)