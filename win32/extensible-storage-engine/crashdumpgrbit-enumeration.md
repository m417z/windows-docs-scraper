# CrashDumpGrbit enumeration

Options for JetConfigureProcessForCrashDump.

This enumeration has a [FlagsAttribute](https://learn.microsoft.com/dotnet/api/system.flagsattribute) attribute that allows a bitwise combination of its member values.

**Namespace:** [Microsoft.Isam.Esent.Interop.Windows7](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop.windows7-namespace)
**Assembly:** Microsoft.Isam.Esent.Interop (in Microsoft.Isam.Esent.Interop.dll)

``` csharp
[FlagsAttribute]
public enum CrashDumpGrbit
```

## Members

|  | Member name | Description |
| --- | --- | --- |
|  | None | Default options. |
|  | Minimum | Dump minimum includes CacheMinimum. |
|  | Maximum | Dump maximum includes CacheMaximum. |
|  | CacheMinimum | CacheMinimum includes pages that are latched. CacheMinimum includes pages that are used for memory. CacheMinimum includes pages that are flagged with errors. |
|  | CacheMaximum | Cache maximum includes cache minimum. Cache maximum includes the entire cache image. |
|  | CacheIncludeDirtyPages | Dump includes pages that are modified. |
|  | CacheIncludeCachedPages | Dump includes pages that contain valid data. |
|  | CacheIncludeCorruptedPages | Dump includes pages that are corrupted (expensive to compute). |

## See also

#### Reference

[Microsoft.Isam.Esent.Interop.Windows7 namespace](https://learn.microsoft.com/windows/win32/extensible-storage-engine/microsoft.isam.esent.interop.windows7-namespace)