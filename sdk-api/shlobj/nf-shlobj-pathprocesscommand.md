# PathProcessCommand function

## Description

Deprecated. Processes a string that contains a command line and generates a suitably quoted string, with arguments attached if required.

## Parameters

### `pszSrc` [in]

Type: **PCWSTR**

A pointer to a null-terminated string that contains the command line to process.

### `pszDest` [out]

Type: **PWSTR**

Pointer to a buffer that receives a null-terminated Unicode string with the appropriate quotation marks. To determine how large this buffer must be, set this parameter to **NULL**. The function returns the required buffer size.

### `cchDest`

Type: **int**

The maximum number of characters that can be put in *pszDest*, not including the terminating null character. If this value is too small, the function fails.

### `dwFlags`

Type: **DWORD**

Flags that control the procedure. One or more of the following values:

#### PPCF_ADDQUOTES (0x00000001)

Add quotes if the path requires them.

#### PPCF_ADDARGUMENTS (0x00000003)

Append trailing arguments to the output string. This value includes **PPCF_ADDQUOTES**.

#### PPCF_NODIRECTORIES (0x00000010)

Do not match the input string against folders, only against file objects.

#### PPCF_FORCEQUALIFY (0x00000040)

Qualify even non-relative file names.

#### PPCF_LONGESTPOSSIBLE (0x00000080)

Always choose the longest possible executable name.

## Return value

Type: **LONG**

Returns a positive value if successful. If *lpDest* is set to **NULL**, the function returns the required buffer size in characters, including the terminating null character. If the call fails, the function returns a negative value.

## Remarks

**Note** This function is available through Windows XP Service Pack 2 (SP2) and Windows Server 2003. It is not supported in Windows Vista and later versions of Windows.