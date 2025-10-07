# JET_IdxInfo enumeration

Info levels for retrieve index information with JetGetIndexInfo. and JetGetTableIndexInfo.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
public enum JET_IdxInfo
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | Default | Returns a [JET_INDEXLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/dn335123(v=exchg.10).md) structure with information about the index. |
|  | List | Returns a [JET_INDEXLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/dn335123(v=exchg.10).md) structure with information about the index. |
|  | SysTabCursor | **Obsolete.** SysTabCursor is obsolete. |
|  | OLC | **Obsolete.** OLC is obsolete. |
|  | ResetOLC | **Obsolete.** Reset OLC is obsolete. |
|  | SpaceAlloc | Returns an integer with the space usage of the index. |
|  | LCID | Returns an integer with the LCID of the index. |
|  | Langid | **Obsolete.** Langid is obsolete. Use LCID instead. |
|  | Count | Returns an integer with the count of indexes in the table. |
|  | VarSegMac | Returns a ushort with the value of cbVarSegMac the index was created with. |
|  | IndexId | Returns a [JET_INDEXID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/hh557060(v=exchg.10).md) identifying the index. |
|  | KeyMost | Introduced in Windows Vista. Returns a ushort with the value of cbKeyMost the index was created with. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)