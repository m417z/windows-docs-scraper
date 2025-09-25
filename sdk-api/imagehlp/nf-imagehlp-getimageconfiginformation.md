# GetImageConfigInformation function

## Description

Locates and returns the load configuration data of an image.

## Parameters

### `LoadedImage` [in]

A pointer to a
[LOADED_IMAGE](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-loaded_image) structure that is returned from a call to
[MapAndLoad](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-mapandload) or [ImageLoad](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-imageload).

### `ImageConfigInformation` [out]

A pointer to an IMAGE_LOAD_CONFIG_DIRECTORY structure that receives the configuration information.

If \_WIN64 is defined, then IMAGE_LOAD_CONFIG_DIRECTORY is defined as [IMAGE_LOAD_CONFIG_DIRECTORY64](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_load_config_directory64). However, if \_WIN64 is not defined, then IMAGE_LOAD_CONFIG_DIRECTORY is defined as [IMAGE_LOAD_CONFIG_DIRECTORY32](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-image_load_config_directory32).

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
[SetImageConfigInformation](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-setimageconfiginformation) function locates and changes the load configuration data of an image.

All ImageHlp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[ImageHlp Functions](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-functions)
[LOADED_IMAGE](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-loaded_image)
[SetImageConfigInformation](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-setimageconfiginformation)