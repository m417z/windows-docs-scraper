# IAmsiStream::GetAttribute

## Description

Returns a requested attribute from the stream.

## Parameters

### `attribute` [in]

Specifies the type of attribute to be returned. See Remarks.

### `dataSize` [in]

The size of the output buffer, *data*, in bytes.

### `data` [out]

Buffer to receive the requested attribute. *data* must be set to its size in bytes.

### `retData` [out]

The number of bytes returned in *data*. If this method returns **E_NOT_SUFFICIENT_BUFFER**, *retData* contains the number of bytes required.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_NOTIMPL** | The attribute is not supported. |
| **E_NOT_SUFFICIENT_BUFFER** | The size of the output buffer, as indicated by *data*, is not large enough. *retData* contains the number of bytes required. |
| **E_INVALIDARG** | One or more argument is invalid. |
| **E_NOT_VALID_STATE** | The object is not initialized. |

## Remarks

Depending on the attribute requested in *attribute*, the following data should be copied to *data*:

| *attribute* | *data* |
| --- | --- |
| **AMSI_ATTRIBUTE_APP_NAME** | The name, version, or GUID string of the calling application, copied from a **LPWSTR**. |
| **AMSI_ATTRIBUTE_CONTENT_NAME** | The filename, URL, unique script ID, or similar of the content, copied from a **LPWSTR**. |
| **AMSI_ATTRIBUTE_CONTENT_SIZE** | The size of the input, as a **ULONGLONG**. |
| **AMSI_ATTRIBUTE_CONTENT_ADDRESS** | The memory address if the content is fully loaded into memory. |
| **AMSI_ATTRIBUTE_SESSION** | Session is used to associate different scan calls, such as if the contents to be scanned belong to the same original script. Return **nullptr** if the content is self-contained. |

## See also

[AMSI_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/amsi/ne-amsi-amsi_attribute)

[IAmsiStream](https://learn.microsoft.com/windows/desktop/api/amsi/nn-amsi-iamsistream)