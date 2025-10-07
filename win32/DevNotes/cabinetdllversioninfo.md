# CABINETDLLVERSIONINFO structure

\[This structure contains information required only when using the **DllGetVersion** function, which is not supported. This documentation is provided for informational purposes only.\]

The **CABINETDLLVERSIONINFO** contains the version information for Cabinet.dll.

## Members

**cbStruct**

The size of this structure, in bytes.

**dwReserved1**

Reserved.

**dwReserved2**

Reserved.

**dwFileVersionMS**

Contains the most significant bits of the version information. Bits 0-15 contain the minor version, and bits 16-31 contain the major version.

**dwFileVersionLS**

Contains the least significant bits of the version information. Bits 0-15 contain the revision number, and bits 16-31 contain the build number.

## See also

[**DllGetVersion**](https://learn.microsoft.com/windows/win32/devnotes/dllgetversion)

