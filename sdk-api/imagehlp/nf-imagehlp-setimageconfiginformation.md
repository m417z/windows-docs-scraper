# SetImageConfigInformation function

## Description

Locates and changes the load configuration data of an image.

## Parameters

### `LoadedImage` [in]

A pointer to a
[LOADED_IMAGE](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-loaded_image) structure that is returned from a call to
[MapAndLoad](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-mapandload) or **LoadImage**.

### `ImageConfigInformation` [in]

A pointer to an
[IMAGE_LOAD_CONFIG_DIRECTORY64](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_load_config_directory32) structure.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**SetImageConfigInformation** function locates and returns the load configuration data of an image.

All ImageHlp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[GetImageConfigInformation](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-getimageconfiginformation)

[IMAGE_LOAD_CONFIG_DIRECTORY64](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_load_config_directory32)

[ImageHlp Functions](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-functions)

[LOADED_IMAGE](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-loaded_image)