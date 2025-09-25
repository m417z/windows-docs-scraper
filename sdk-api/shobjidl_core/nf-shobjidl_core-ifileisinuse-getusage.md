# IFileIsInUse::GetUsage

## Description

Gets a value that indicates how the file in use is being used.

## Parameters

### `pfut` [out]

Type: **[FILE_USAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-file_usage_type)***

Pointer to a value that, when this method returns successfully, receives one of the [FILE_USAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-file_usage_type) values.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.