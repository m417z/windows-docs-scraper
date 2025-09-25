# PathYetAnotherMakeUniqueName function

## Description

Creates a unique filename based on an existing filename.

## Parameters

### `pszUniqueName` [out]

Type: **PWSTR**

A string buffer that receives a null-terminated Unicode string that contains the fully qualified path of the unique file name. This buffer should be at least MAX_PATH characters long to avoid causing a buffer overrun.

### `pszPath` [in]

Type: **PCWSTR**

A null-terminated Unicode string that contains the fully qualified path of folder that will contain the new file. If *pszShort* is set to **NULL**, this string must contain a full destination path, ending with the long file name that the new file name will be base on.

### `pszShort` [in, optional]

Type: **PCWSTR**

A null-terminated Unicode string that contains the short file name that the unique name will be based on. Set this value to **NULL** to create a name based on the long file name.

### `pszFileSpec` [in, optional]

Type: **PCWSTR**

A null-terminated Unicode string that contains the long file name that the unique name will be based on.

## Return value

Type: **BOOL**

Returns **TRUE** if a unique name was successfully created; otherwise **FALSE**.

## Remarks

If the generated path exceeds MAX_PATH characters, this function may return a truncated string in **PathYetAnotherMakeUniqueName**. In that case, the function returns **FALSE**.

## See also

[PathMakeUniqueName](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-pathmakeuniquename)