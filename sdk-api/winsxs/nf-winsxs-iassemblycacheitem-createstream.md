# IAssemblyCacheItem::CreateStream

## Description

The **CreateStream** method copies the source of a manifest or module into a stream.

## Parameters

### `dwFlags` [in]

Reserved.

### `pszStreamName` [in]

Pointer to a string value containing the name of the manifest. This becomes the name of the stream.

### `dwFormat` [in]

This parameter specifies whether a module or manifest is being copied to a stream.

| Value | Meaning |
| --- | --- |
| **STREAM_FORMAT_COMPLIB_MODULE** | Copy the source of a module for a non-Windows assembly to a stream. |
| **STREAM_FORMAT_COMPLIB_MANIFEST** | Copy the source of a manifest for a non-Windows assembly to a stream. |
| **STREAM_FORMAT_WIN32_MODULE** | Copy the source of a module for a Windows assembly to a stream. |
| **STREAM_FORMAT_WIN32_MANIFEST** | Copy the source of a manifest for a Windows assembly to a stream. |

### `dwFormatFlags` [in]

Reserved.

### `ppIStream`

Pointer to the location that contains the pointer to the IStream interface that receives the information.

### `puliMaxSize` [optional]

Reserved.

## Return value

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | The method succeeded. |
| S_FALSE | The method did not succeed. |

## See also

[IAssemblyCacheItem](https://learn.microsoft.com/windows/desktop/api/winsxs/nn-winsxs-iassemblycacheitem)