# DIGEST_FUNCTION callback function

## Description

An application-defined callback function used by the
[ImageGetDigestStream](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-imagegetdigeststream) function to process data.

The **DIGEST_FUNCTION** type defines a pointer to this callback function.
**DigestFunction** is a placeholder for the application-defined function name.

## Parameters

### `refdata` [in]

A user-supplied handle to the digest. This value is passed as a parameter to the
[ImageGetDigestStream](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-imagegetdigeststream) function.

### `pData` [in]

The data stream.

### `dwLength` [in]

The size of the data stream, in bytes.

## Return value

If the function succeeds, the return value should be **TRUE**. If the function fails, the return value should be **FALSE**.

## Remarks

All ImageHlp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

## See also

[ImageGetDigestStream](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-imagegetdigeststream)

[ImageHlp Functions](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-functions)