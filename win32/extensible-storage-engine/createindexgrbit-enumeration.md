# CreateIndexGrbit enumeration

Options for JetCreateIndex.

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum CreateIndexGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. |
|  | IndexUnique | Duplicate index entries (keys) are disallowed. This is enforced when JetUpdate is called, not when JetSetColumn is called. |
|  | IndexPrimary | The index is a primary (clustered) index. Every table must have exactly one primary index. If no primary index is explicitly defined over a table, then the database engine will create its own primary index. |
|  | IndexDisallowNull | None of the columns over which the index is created may contain a NULL value. |
|  | IndexIgnoreNull | Do not add an index entry for a row if all of the columns being indexed are NULL. |
|  | IndexIgnoreAnyNull | Do not add an index entry for a row if any of the columns being indexed are NULL. |
|  | IndexIgnoreFirstNull | Do not add an index entry for a row if the first column being indexed is NULL. |
|  | IndexLazyFlush | Specifies that the index operations will be logged lazily. JET_bitIndexLazyFlush does not affect the laziness of data updates. If the indexing operations is interrupted by process termination, Soft Recovery will still be able to able to get the database to a consistent state, but the index may not be present. |
|  | IndexEmpty | Do not attempt to build the index, because all entries would evaluate to NULL. grbit MUST also specify JET_bitIgnoreAnyNull when JET_bitIndexEmpty is passed. This is a performance enhancement. For example if a new column is added to a table, then an index is created over this newly added column, all of the records in the table would be scanned even though they would never get added to the index anyway. Specifying JET_bitIndexEmpty skips the scanning of the table, which could potentially take a long time. |
|  | IndexUnversioned | Causes index creation to be visible to other transactions. Normally a session in a transaction will not be able to see an index creation operation in another session. This flag can be useful if another transaction is likely to create the same index, so that the second index-create will simply fail instead of potentially causing many unnecessary database operations. The second transaction may not be able to use the index immediately. The index creation operation needs to complete before it is usable. The session must not currently be in a transaction to create an index without version information. |
|  | IndexSortNullsHigh | Specifying this flag causes NULL values to be sorted after data for all columns in the index. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)