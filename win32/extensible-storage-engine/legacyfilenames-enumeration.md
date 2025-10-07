# LegacyFileNames enumeration

Options for LegacyFileNames

**Namespace:** [Microsoft.Isam.Esent.Interop.Vista](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop.vista-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
public enum LegacyFileNames
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | ESE98FileNames | When this option is present then the database engine will use the following naming conventions for its files: o Transaction Log files will use .LOG for their file extension o Checkpoint files will use .CHK for their file extension |
|  | EightDotThreeSoftCompat | Preserve the 8.3 naming syntax for as long as possible. (this should not be changed, w/o ensuring there are no log files) |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop.Vista namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop.vista-namespace)