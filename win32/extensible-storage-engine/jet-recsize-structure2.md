# JET_RECSIZE structure

Used by [JetGetRecordSize(JET_SESID, JET_TABLEID, JET_RECSIZE, GetRecordSizeGrbit)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/vistaapi.jetgetrecordsize-method) to return information about a record's usage requirements in user data space, number of set columns, number of values, and ESENT record structure overhead space.

**Namespace:** [Microsoft.Isam.Esent.Interop.Vista](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop.vista-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[SerializableAttribute]
public struct JET_RECSIZE : IEquatable<JET_RECSIZE>
```

## Thread safety

Any public static (Shared in Visual Basic) members of this type are thread safe. Any instance members are not guaranteed to be thread safe.

## See also

#### Reference

[JET_RECSIZE members](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-recsize-members)

[Microsoft.Isam.Esent.Interop.Vista namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop.vista-namespace)