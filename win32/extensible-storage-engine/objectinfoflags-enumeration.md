# ObjectInfoFlags enumeration

Flags for ESENT objects (tables). Used in [JET_OBJECTINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-objectinfo-class).

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum ObjectInfoFlags
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. |
|  | System | Object is for internal use only. |
|  | TableFixedDDL | Table's DDL is fixed. |
|  | TableTemplate | Table's DDL is inheritable. |
|  | TableDerived | Table's DDL is inherited from a template table. |
|  | TableNoFixedVarColumnsInDerivedTables | Fixed or variable columns in derived tables (so that fixed or variable columns can be added to the template in the future). Used in conjunction with TableTemplate. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop-namespace)