# UpdateResourceA function

## Description

Adds, deletes, or replaces a resource in a portable executable (PE) file. There are some restrictions on resource updates in files that contain Resource Configuration (RC Config) data: [language-neutral](https://learn.microsoft.com/windows/desktop/Intl/mui-resource-management) (LN) files and language-specific resource (.mui) files.

## Parameters

### `hUpdate` [in]

Type: **HANDLE**

A module handle returned by the [BeginUpdateResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-beginupdateresourcea) function, referencing the file to be updated.

### `lpType` [in]

Type: **LPCTSTR**

The resource type to be updated. Alternatively, rather than a pointer, this parameter can be [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea)(ID), where ID is an integer value representing a predefined resource type. If the first character of the string is a pound sign (#), then the remaining characters represent a decimal number that specifies the integer identifier of the resource type. For example, the string "#258" represents the identifier 258.

For a list of predefined resource types, see [Resource Types](https://learn.microsoft.com/windows/win32/menurc/resource-types).

### `lpName` [in]

Type: **LPCTSTR**

The name of the resource to be updated. Alternatively, rather than a pointer, this parameter can be [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea)(ID), where ID is a resource ID. When creating a new resource do not use a string that begins with a '#' character for this parameter.

### `wLanguage` [in]

Type: **WORD**

The [language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) of the resource to be updated. For a list of the primary language identifiers and sublanguage identifiers that make up a language identifier, see the [MAKELANGID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelangid) macro.

### `lpData` [in, optional]

Type: **LPVOID**

The resource data to be inserted into the file indicated by *hUpdate*. If the resource is one of the predefined types, the data must be valid and properly aligned. Note that this is the raw binary data to be stored in the file indicated by *hUpdate*, not the data provided by [LoadIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadicona), [LoadString](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadstringa), or other resource-specific load functions. All data containing strings or text must be in Unicode format. *lpData* must not point to ANSI data.

If *lpData* is **NULL** and *cbData* is 0, the specified resource is deleted from the file indicated by *hUpdate*.

### `cb` [in]

Type: **DWORD**

The size, in bytes, of the resource data at *lpData*.

## Return value

Type: **BOOL**

Returns **TRUE** if successful or **FALSE** otherwise. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

It is recommended that the resource file is not loaded before this function is called. However, if that file is already loaded, it will not cause an error to be returned.

An application can use **UpdateResource** repeatedly to make changes to the resource data. Each call to **UpdateResource** contributes to an internal list of additions, deletions, and replacements but does not actually write the data to the file indicated by *hUpdate*. The application must use the [EndUpdateResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-endupdateresourcea) function to write the accumulated changes to the file.

This function can update resources within modules that contain both code and resources.

**Prior to Windows 7:** If *lpData* is **NULL** and *cbData* is nonzero, the specified resource is NOT deleted and an exception is thrown.

**Starting with Windows Vista:** As noted above, there are restrictions on resource updates in files that contain RC Config data: LN files and .mui files. The restrictions are as follows:

| Action | LN file | .mui file |
| --- | --- | --- |
| 1. Add a new type that doesn't exist in the LN or .mui files. | Add type in the LN file and treat as language-neutral (non-localizable) and add new type or item in the RC Config data | The only additions allowed are the following types: file Version, RC Config data, Side-by-side Assembly XML Manifest. |
| 2. Add a new resource item to an existing type. | Uses the RC Config data to check whether the type exists in the .mui files associated with this LN file. If the type doesn't exist in the .mui files, add the item and treat new item as un-localizable. If the type exists in the .mui files, then adding is not allowed. | Only items of the following types may be added: File Version, RC Config data, Side-by-side Assembly XML Manifest. |
| 3. Update a resource item. | Uses the RC Config data to check whether the type exists in the .mui files associated with the LN file. If the type doesn't exist in the .mui files, then this resource item update is allowed in the LN file. Otherwise, if the type exists in the .mui files associated with this LN file, then this update is not allowed. | The only updates allowed are items of the following types: file Version, RC Config data, Side-by-side Assembly XML Manifest. |
| 4. Add a type/item for a new language. | Not allowed. | Not allowed. |
| 5. Remove an existing type/item. | Works similarly to case 3. Uses the RC Config data to check whether the type exists in the .mui files associated with the LN file. If not, then the removal of the type/item from the LN file is allowed. Otherwise, if the type/item exists in the .mui files associated with this LN file, then the removal is not allowed. | The only types allowed to be removed are: file Version, RC Config data, Side-by-side Assembly XML Manifest; also, only items of these types may be removed. |
| 6. Add/delete/update a type not included in the RC Config data (such as Version, Side-by-side Assembly XML Manifest, or RC Config data itself). | Allowed. | Allowed. |
| 7. Other update of non-localizable data, such as TYPELIB, reginst, and so on. | Update type or item in the LN file, treat as non-localizable, and add new type or item in the RC Config data. | Not applicable. |
| 8. Add RC Config data. | Can be done but the integrity of the RC Config data is not checked. | Can be done but the integrity of the RC Config data is not checked. |

#### Examples

For an example, see [Updating Resources](https://learn.microsoft.com/windows/desktop/menurc/using-resources).

> [!NOTE]
> The winbase.h header defines UpdateResource as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[BeginUpdateResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-beginupdateresourcea)

**Conceptual**

[EndUpdateResource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-endupdateresourcea)

[LoadIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadicona)

[LoadString](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadstringa)

[LockResource](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-lockresource)

[MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea)

[MAKELANGID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelangid)

**Other Resources**

**Reference**

[Resources](https://learn.microsoft.com/windows/desktop/menurc/resources)

[SizeofResource](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-sizeofresource)