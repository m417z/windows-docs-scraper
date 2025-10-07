# DefragGrbit enumeration

Options for [JetDefragment(JET_SESID, JET_DBID, String, Int32, Int32, DefragGrbit)](https://learn.microsoft.com/windows/win32/extensible-storage-engine/api.jetdefragment-method).

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum DefragGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | AvailSpaceTreesOnly | Defragments the available space portion of ESE database space allocation. Database space is divided into two types, owned space and available space. Owned space is allocated to a table or index while available space is ready for use within the table or index, respectively. Available space is much more dynamic in behavior and requires on-line defragmentation more so than owned space or table or index data. |
|  | BatchStart | Starts a new defragmentation task. |
|  | BatchStop | Stops a defragmentation task. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)