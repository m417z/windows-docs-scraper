# SLAcquireGenuineTicket function

## Description

Gets a XrML genuine ticket acquired from the Software Licensing Server (SLS).

## Parameters

### `ppTicketBlob` [out]

The address of a pointer to a buffer that receives the ticket BLOB. When you have finished using this buffer, free it by calling the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

### `pcbTicketBlob` [out]

A pointer to the size, in bytes, of the *ppTicketBlob* buffer.

### `pwszTemplateId` [in]

A pointer to a null-terminated string that contains the ID of the BLOB template stored on the SLS.

### `pwszServerUrl` [in]

A pointer to a null-terminated string that contains the URL of the SLS.

### `pwszClientToken` [in, optional]

Reserved.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).