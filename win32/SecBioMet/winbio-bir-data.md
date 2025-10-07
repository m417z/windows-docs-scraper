# WINBIO\_BIR\_DATA structure

The **WINBIO\_BIR\_DATA** structure specifies the size, in bytes, and the offset of a block of biometric information. This structure is used by the [**WINBIO\_BIR**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-bir) structure to specify where the various parts of a biometric information record are located.

## Members

**Size**

Size, in bytes, of the biometric information.

**Offset**

Offset, in bytes from the beginning of the [**WINBIO\_BIR**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-bir) structure, of the biometric information.

## Remarks

The use of offsets rather than pointers allows for easy serialization of the BIR and for less complicated translation between 32 and 64-bit environments or between user and kernel mode.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | Winbio\_types.h (include Winbio.h) |

## See also

[Client Application Structures](https://learn.microsoft.com/windows/win32/secbiomet/client-application-structures)

[**WINBIO\_BIR**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-bir)

[**WINBIO\_BIR\_HEADER**](https://learn.microsoft.com/windows/win32/secbiomet/winbio-bir-header)

