# CryptXmlClose function

## Description

The **CryptXmlClose** function closes a cryptographic XML object handle.

## Parameters

### `hCryptXml` [in]

The handle of the cryptographic XML object to be closed.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.

## Remarks

At each call to this function, the reference count on the handle is reduced by one. When the reference count reaches zero, an object encapsulated by the handle is fully released.