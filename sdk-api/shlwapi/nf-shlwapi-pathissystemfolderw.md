# PathIsSystemFolderW function

## Description

Determines if an existing folder contains the attributes that make it a system folder. Alternately, this function indicates if certain attributes qualify a folder to be a system folder.

## Parameters

### `pszPath` [in, optional]

Type: **LPCTSTR**

A pointer to a null-terminated string of maximum length MAX_PATH that contains the name of an existing folder. The attributes for this folder will be retrieved and compared with those that define a system folder. If this folder contains the attributes to make it a system folder, the function returns nonzero. If this value is **NULL**, this function determines if the attributes passed in *dwAttrb* qualify it to be a system folder.

### `dwAttrb` [in]

Type: **DWORD**

The file attributes to be compared. Used only if *pszPath* is **NULL**. In that case, the attributes passed in this value are compared with those that qualify a folder as a system folder. If the attributes are sufficient to make this a system folder, this function returns nonzero. These attributes are the attributes that are returned from [GetFileAttributes](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesa).

## Return value

Type: **BOOL**

Returns nonzero if the *pszPath* or *dwAttrb* represent a system folder, or zero otherwise.

## Remarks

> [!NOTE]
> The shlwapi.h header defines PathIsSystemFolder as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).