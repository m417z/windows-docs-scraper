# JET_INDEXID structure

Holds an index ID. An index ID is a hint that is used to accelerate the selection of the current index using JetSetCurrentIndex. It is most useful when there is a very large number of indexes over a table. The index ID can be retrieved using JetGetIndexInfo or JetGetTableIndexInfo.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
public struct JET_INDEXID : IEquatable<JET_INDEXID>
```

## Remarks

The Pack attribute is necessary because the C++ version is defined as a byte array. If the C\# compiler inserts the usual padding between the uint cbStruct and the IntPtr, then the structure ends up too large.

## Thread safety

Any public static (Shared in Visual Basic) members of this type are thread safe. Any instance members are not guaranteed to be thread safe.

## See also

#### Reference

[JET_INDEXID members](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexid-members)

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)