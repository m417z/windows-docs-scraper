# GotoSecondaryIndexBookmarkGrbit enumeration

Options for [JetGotoSecondaryIndexBookmark(JET_SESID, JET_TABLEID, \[\], Int32, \[\], Int32, GotoSecondaryIndexBookmarkGrbit)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/api.jetgotosecondaryindexbookmark-method).

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum GotoSecondaryIndexBookmarkGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. |
|  | BookmarkPermitVirtualCurrency | In the event that the index entry can no longer be found, the cursor will be left positioned where that index entry was previously found. The operation will still fail with JET_errRecordDeleted; however, it will be possible to move to the next or previous index entry relative to the index entry that is now missing. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)