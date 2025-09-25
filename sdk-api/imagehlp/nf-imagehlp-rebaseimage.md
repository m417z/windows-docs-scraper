# ReBaseImage function

## Description

Changes the load address for the specified image, which reduces the required load time for a DLL.

Alternatively, you can use the
Rebase tool. This tool is available in Visual Studio and the [Windows SDK](https://msdn.microsoft.com/windowsserver/bb980924.aspx).

Note that this function is implemented as a call to the
[ReBaseImage64](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-rebaseimage64) function.

## Parameters

### `CurrentImageName` [in]

The name of the file to be rebased. You must specify the full path to the file unless the module is in the current working directory of the calling process.

### `SymbolPath` [in]

The path used to find the corresponding symbol file. Specify this path for executable images that have symbolic information because when image addresses change, the corresponding symbol database file (PDB) may also need to be changed. Note that even if the symbol path is not valid, the function will succeed if it is able to rebases your image.

### `fReBase` [in]

If this value is **TRUE**, the image is rebased. Otherwise, the image is not rebased.

### `fRebaseSysfileOk` [in]

If this value is **TRUE**, the system image is rebased. Otherwise, the system image is not rebased.

### `fGoingDown` [in]

If this value is **TRUE**, the image can be rebased below the given base; otherwise, it cannot.

### `CheckImageSize` [in]

The maximum size that the image can grow to, in bytes, or zero if there is no limit.

### `OldImageSize` [out]

A pointer to a variable that receives the original image size, in bytes.

### `OldImageBase` [out]

A pointer to a variable that receives the original image base.

### `NewImageSize` [out]

A pointer to a variable that receives the new image size after the rebase operation, in bytes.

### `NewImageBase` [in, out]

The base address to use for rebasing the image. If the address is not available and the *fGoingDown* parameter is set to **TRUE**, the function finds a new base address and sets this parameter to the new base address. If *fGoingDown* is **FALSE**, the function finds a new base address but does not set this parameter to the new base address.

### `TimeStamp` [in]

The new time date stamp for the image file header. The value must be represented in the number of seconds elapsed since midnight (00:00:00), January 1, 1970, Universal Coordinated Time, according to the system clock.

If this parameter is 0, the current file header time date stamp is incremented by 1 second.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**ReBaseImage** function changes the desired load address for the specified image. This operation involves reading the entire image and updating all fixups, debugging information, and checksum. You can rebase an image to reduce the required load time for its DLLs. If an application can rely on a DLL being loaded at the desired load address, then the system loader does not have to relocate the image. The image is simply loaded into the application's virtual address space and the
[DllMain](https://learn.microsoft.com/windows/desktop/Dlls/dllmain) function is called, if one is present.

All ImageHlp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

You cannot rebase DLLs that link with /DYNAMICBASE or that reside in protected directories, such as the System32 folder.

As an alternative to using this function, see the [/BASE](https://learn.microsoft.com/cpp/build/reference/base-base-address) linker option.

## See also

[DllMain](https://learn.microsoft.com/windows/desktop/Dlls/dllmain)

[ImageHlp Functions](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-functions)