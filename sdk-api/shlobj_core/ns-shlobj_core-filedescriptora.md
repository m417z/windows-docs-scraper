# FILEDESCRIPTORA structure

## Description

Describes the properties of a file that is being copied by means of the clipboard during a Microsoft ActiveX [drag-and-drop](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776905(v=vs.85)) operation.

## Members

### `dwFlags`

Type: **DWORD**

An array of flags that indicate which of the other structure members contain valid data. This member can be a combination of the following values.

#### FD_CLSID (0x00000001)

0x00000001. The **clsid** member is valid.

#### FD_SIZEPOINT (0x00000002)

0x00000002. The **sizel** and **pointl** members are valid.

#### FD_ATTRIBUTES (0x00000004)

0x00000004. The **dwFileAttributes** member is valid.

#### FD_CREATETIME (0x00000008)

0x00000008. The **ftCreationTime** member is valid.

#### FD_ACCESSTIME (0x00000010)

0x00000010. The **ftLastAccessTime** member is valid.

#### FD_WRITESTIME (0x00000020)

0x00000020. The **ftLastWriteTime** member is valid.

#### FD_FILESIZE (0x00000040)

0x00000040. The **nFileSizeHigh** and **nFileSizeLow** members are valid.

#### FD_PROGRESSUI (0x00004000)

0x00004000. A progress indicator is shown with drag-and-drop operations.

#### FD_LINKUI (0x00008000)

0x00008000. Treat the operation as a shortcut.

#### FD_UNICODE ((int)0x80000000)

(int)0x80000000. **Windows Vista and later**. The descriptor is Unicode.

### `clsid`

Type: **CLSID**

The file type identifier.

### `sizel`

Type: **SIZEL**

The width and height of the file icon.

### `pointl`

Type: **[POINTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-pointl)**

The screen coordinates of the file object.

### `dwFileAttributes`

Type: **DWORD**

File attribute flags. This will be a combination of the FILE_ATTRIBUTE_ values described in [GetFileAttributes](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesa).

### `ftCreationTime`

Type: **FILETIME**

The [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the time of file creation.

### `ftLastAccessTime`

Type: **FILETIME**

The [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the time that the file was last accessed.

### `ftLastWriteTime`

Type: **FILETIME**

The [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the time of the last write operation.

### `nFileSizeHigh`

Type: **DWORD**

The high-order **DWORD** of the file size, in bytes.

### `nFileSizeLow`

Type: **DWORD**

The low-order **DWORD** of the file size, in bytes.

### `cFileName`

Type: **TCHAR[MAX_PATH]**

The null-terminated string that contains the name of the file.

## Remarks

If the [CFSTR_FILECONTENTS](https://learn.microsoft.com/windows/desktop/shell/clipboard) format that corresponds to this structure contains the file as a global memory object, **nFileSizeHigh** and **nFileSizeLow** specify the size of the associated memory block. If they are set, they can also be used if a user-interface needs to be displayed. For example, if a file is about to be overwritten, you would typically use information from this structure to display a dialog box containing the size, data, and name of the file.

To create a zero-length file, set the **FD_FILESIZE** flag in the **dwFlags**, and set **nFileSizeHigh** and **nFileSizeLow** to zero. The [CFSTR_FILECONTENTS](https://learn.microsoft.com/windows/desktop/shell/clipboard) format should represent the file as either a stream or global memory object ([TYMED_ISTREAM](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-tymed) or [TYMED_HGLOBAL](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-tymed)).

> [!NOTE]
> The shlobj_core.h header defines FILEDESCRIPTOR as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).