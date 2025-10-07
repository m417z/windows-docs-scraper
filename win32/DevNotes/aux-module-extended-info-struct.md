# AUX\_MODULE\_EXTENDED\_INFO structure

Contains extended module information.

## Members

**BasicInfo**

An [**AUX\_MODULE\_BASIC\_INFO**](https://learn.microsoft.com/windows/win32/devnotes/aux-module-basic-info-struct) structure.

**ImageSize**

The size, in bytes, of the loaded module.

**FileNameOffset**

The offset of the file name within the **FullPathName** buffer.

**FullPathName**

The full path of the module.

## Remarks

The object library that implements this API can be downloaded from [here](https://www.microsoft.com/?ref=go).

## Requirements

| Requirement | Value |
|----------------------------|----------------------------------------------------------------------------------------|
| Redistributable<br> | Windows Auxiliary API library version 1.0 or later<br> |
| Header<br> | Aux\_klib.h |

## See also

[**AuxKlibQueryModuleInformation**](https://learn.microsoft.com/windows/win32/devnotes/auxklibquerymoduleinformation-func)

[**AUX\_MODULE\_BASIC\_INFO**](https://learn.microsoft.com/windows/win32/devnotes/aux-module-basic-info-struct)

