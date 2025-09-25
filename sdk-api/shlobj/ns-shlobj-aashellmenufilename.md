# AASHELLMENUFILENAME structure

## Description

A variable-size structure that contains information about a menu file name.

## Members

### `cbTotal`

Type: **SHORT**

The size of the structure, in bytes.

### `rgbReserved`

Type: **BYTE[12]**

Reserved. Applications should ignore this value.

### `szFileName`

Type: **TCHAR[1]**

The menu file name. This string is in Unicode on Windows 2000.

## Remarks

**Important** This structure cannot be used with operating systems later than Windows 2000.

When reading an **AASHELLMENUFILENAME** structure, first read a single SHORT to determine the total size of the structure, then use that value to read the remainder of the structure.

## See also

[AASHELLMENUITEM](https://learn.microsoft.com/windows/desktop/api/shlobj/ns-shlobj-aashellmenuitem)