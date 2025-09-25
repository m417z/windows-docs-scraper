# GetFileTitleA function

## Description

Retrieves the name of the specified file.

## Parameters

### `unnamedParam1` [in]

Type: **LPCTSTR**

The name and location of a file.

### `Buf` [out]

Type: **LPTSTR**

The buffer that receives the name of the file.

### `cchSize` [in]

Type: **WORD**

The length, in
characters, of the buffer pointed to by the *lpszTitle* parameter.

## Return value

Type: **short**

If the function succeeds, the return value is zero.

If the file name is invalid, the return value is unknown. If there is an error, the return value is a negative number.

If the buffer pointed to by the *lpszTitle* parameter is too small, the return value is a positive integer that specifies the required buffer size, in characters. The required buffer size includes the terminating null character.

## Remarks

**GetFileTitle** should only be called with legal file names; using an illegal file name has an undefined result.

To get the buffer size needed for the name of a file, call the function with *lpszTitle* set to **NULL** and *cchSize* set to zero. The function returns the required size.

**GetFileTitle** returns the string that the system would use to display the file name to the user. The display name includes an extension only if that is the user's preference for displaying file names. This means that the returned string may not accurately identify the file if it is used in calls to file system functions.

If the *lpszTitle* buffer is too small, **GetFileTitle** returns the size required to hold the display name. However, there is no guaranteed relationship between the required size and the characters originally specified in the *lpszFile* buffer. For example, do not call **GetFileTitle** with *lpszTitle* set to **NULL** and *cchSize* set to zero, and then try to use the return value as an index into the *lpszFile* string. You can usually achieve similar results (and superior performance) with C run-time library functions such as **strrchr**, **wcsrchr**, and **_mbsrchr**.

> [!NOTE]
> The commdlg.h header defines GetFileTitle as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Common Dialog Box Library](https://learn.microsoft.com/windows/desktop/dlgbox/common-dialog-box-library)

**Conceptual**

[GetOpenFileName](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-getopenfilenamea)

[GetSaveFileName](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-getsavefilenamea)

**Reference**