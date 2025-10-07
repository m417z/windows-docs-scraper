# JetRelop enumeration

Comparison operation for filter defined as [JET_INDEX_COLUMN](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-index-column-class).

**Namespace:** [Microsoft.Isam.Esent.Interop.Windows8](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop.windows8-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
public enum JetRelop
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | Equals | Accept only rows which have column value equal to the given value. |
|  | PrefixEquals | Accept only rows which have columns whose prefix matches the given value. |
|  | NotEquals | Accept only rows which have column value not equal to the given value. |
|  | LessThanOrEqual | Accept only rows which have column value less than or equal a given value. |
|  | LessThan | Accept only rows which have column value less than a given value. |
|  | GreaterThanOrEqual | Accept only rows which have column value greater than or equal a given value. |
|  | GreaterThan | Accept only rows which have column value greater than a given value. |
|  | BitmaskEqualsZero | Accept only rows which have column value ANDed with a given bitmask yielding zero. |
|  | BitmaskNotEqualsZero | Accept only rows which have column value ANDed with a given bitmask yielding non-zero. |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop.Windows8 namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop.windows8-namespace)