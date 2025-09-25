# acmGetVersion function

## Description

The **acmGetVersion** function returns the version number of the ACM.

## Return value

The version number is returned as a hexadecimal number of the form 0xAABBCCCC, where AA is the major version number, BB is the minor version number, and CCCC is the build number.

## Remarks

Win32 applications must verify that the ACM version is at least 0x03320000 (version 3.50) or greater before attempting to use any other ACM functions. The build number (CCCC) is always zero for the retail (non-debug) version of the ACM.

To display the ACM version for a user, an application should use the following format (note that the values should be printed as unsigned decimals):

```cpp

{
    DWORD   dw;
    TCHAR   ach[10];

    dw = acmGetVersion();
    _stprintf_s(ach, TEXT("%u.%.02u"),
        HIWORD(dw) >> 8, HIWORD(dw) & 0x00FF);
}

```

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)