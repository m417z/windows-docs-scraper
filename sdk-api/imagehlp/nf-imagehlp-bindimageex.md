# BindImageEx function

## Description

Computes the virtual address of each function that is imported.

## Parameters

### `Flags` [in]

The bind options. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **BIND_ALL_IMAGES**<br><br>0x00000004 | Bind all images in the call tree for this file. |
| **BIND_CACHE_IMPORT_DLLS**<br><br>0x00000008 | Do not discard DLL information in the cache between calls. This improves performance when binding a large number of images. |
| **BIND_NO_BOUND_IMPORTS**<br><br>0x00000001 | Do not generate a new import address table. <br><br> |
| **BIND_NO_UPDATE**<br><br>0x00000002 | Do not make changes to the file. |

### `ImageName` [in]

The name of the file to be bound. This value can be a file name, a partial path, or a full path.

### `DllPath` [in]

The root of the search path to use if the file specified by the *ImageName* parameter cannot be opened.

### `SymbolPath` [in]

The root of the path to search for the file's corresponding symbol file.

### `StatusRoutine` [in]

A pointer to a status routine. The status routine is called during the progress of the image binding. For more information, see
[StatusRoutine](https://learn.microsoft.com/windows/desktop/api/imagehlp/nc-imagehlp-pimagehlp_status_routine).

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The process of binding an image consists of computing the virtual address of each imported function. The computed virtual address is then saved in the importing image's Import Address Table (IAT). As a result, the image is loaded much faster, particularly if it uses many DLLs, because the system loader does not have to compute the address of each imported function.

If a corresponding symbol file can be located, its time stamp and checksum are updated.

All ImageHlp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[ImageHlp Functions](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-functions)

[StatusRoutine](https://learn.microsoft.com/windows/desktop/api/imagehlp/nc-imagehlp-pimagehlp_status_routine)