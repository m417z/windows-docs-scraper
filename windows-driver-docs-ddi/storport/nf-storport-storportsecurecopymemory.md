## Description

**StorPortSecureCopyMemory** securely copies bytes between buffers.

## Parameters

### `Dest` [out]

Pointer to the destination buffer to copy to.

### `DestSizeInBytes` [in]

Size of the buffer that **Dest** points to, in bytes.

### `Src` [in]

Pointer to the source buffer to copy from.

### `Count` [in]

Number of bytes to copy from **Src** to **Dest**.

## Return value

This function returns one of the following status codes.

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_SUCCESS | The specified number of bytes were copied. |
| STOR_STATUS_INVALID_PARAMETER | A parameter is invalid; for example, **Dest** is a null pointer. |
| STOR_STATUS_BUFFER_TOO_SMALL | The destination buffer size is smaller than number of bytes to copy.|

## Remarks

A miniport calls **StorPortSecureCopyMemory** to securely copy bytes from a virtual source buffer to a virtual destination buffer. To avoid any potential security vulnerabilities, miniports should call this function instead of **StorPortCopyMemory**.