# ImageGetDigestStream function

## Description

Retrieves the requested data from the specified image file.

## Parameters

### `FileHandle` [in]

A handle to the image file. This handle must be opened for FILE_READ_DATA access.

### `DigestLevel` [in]

The aspects of the image that are to be included in the returned data stream. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_PE_IMAGE_DIGEST_ALL_IMPORT_INFO**<br><br>0x04 | Include all import information. |
| **CERT_PE_IMAGE_DIGEST_DEBUG_INFO**<br><br>0x01 | Include symbolic debugging information. |
| **CERT_PE_IMAGE_DIGEST_RESOURCES**<br><br>0x02 | Include resource information. |

### `DigestFunction` [in]

A pointer to a callback routine to process the data. For more information, see
[DigestFunction](https://learn.microsoft.com/windows/desktop/api/imagehlp/nc-imagehlp-digest_function).

### `DigestHandle` [in]

 A user-supplied handle to the digest. This parameter is passed to [DigestFunction](https://learn.microsoft.com/windows/desktop/api/imagehlp/nc-imagehlp-digest_function) as the first argument.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**ImageGetDigestStream** function returns the data to be digested from a specified image file, subject to the passed *DigestLevel* parameter. The order of the bytes will be consistent for different calls, which is required to ensure that the same message digest is always produced from the retrieved byte stream.

To ensure cross-platform compatibility, all implementations of this function must behave in a consistent manner with respect to the order in which the various parts of the image file are returned.

Data should be returned in the following order:

1. Image (executable and static data) information.
2. Resource data.
3. Debugging information.

If any of these are not specified, the remaining parts must be returned in the same order.

All ImageHlp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[ImageHlp Functions](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-functions)