# MF\_SIGNATURE structure

Contains a global revocation list (GRL) signature.

## Members

**dwSignVer**

The signature version number.

**cbSign**

The size of the signature in bytes.

**rgSign**

A byte array of size **cbSign** that contains the signature. The actual array size is larger than the size given in the structure declaration.

## Remarks

This structure is not declared in an SDK header. To use this structure, add the declaration shown here to your source code.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |

## See also

[OPM Certificate Revocation](https://learn.microsoft.com/windows/win32/medfound/opm-certificate-revocation)

[OPM Structures](https://learn.microsoft.com/windows/win32/medfound/opm-structures)

