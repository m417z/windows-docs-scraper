# PFAXGETPAGEDATA callback function

## Description

The **FaxGetPageData** function returns to a fax client application the first page of data for a fax job. The fax job must be an outbound job, but it can be queued or active. The function returns data in the Tagged Image File Format Class F (TIFF Class F) format.

## Parameters

### `FaxHandle` [in]

Type: **HANDLE**

Specifies a fax server handle returned by a call to the [FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera) function.

### `JobId` [in]

Type: **DWORD**

Specifies a unique number that identifies the fax job associated with the page of data.

### `Buffer` [out]

Type: **LPBYTE***

Pointer to the address of a buffer to receive the first page of data in the fax document. For information about memory allocation, see the following Remarks section.

### `BufferSize` [out]

Type: **LPDWORD**

Pointer to a **DWORD** variable to receive the size of the buffer, in bytes, pointed to by the *Buffer* parameter.

### `ImageWidth` [out]

Type: **LPDWORD**

Pointer to a **DWORD** variable to receive the width, in pixels, of the fax image.

### `ImageHeight` [out]

Type: **LPDWORD**

Pointer to a **DWORD** variable to receive the height, in pixels, of the fax image.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). GetLastError can return one of the following errors.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. [FAX_JOB_QUERY](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-specific-fax-access-rights) access is required. |
| **ERROR_INVALID_PARAMETER** | One or all of the *Buffer*, *BufferSize*, *ImageWidth*, *ImageHeight*, or *FaxHandle* parameters are **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | An error occurred during memory allocation. |
| **ERROR_INVALID_DATA** | An invalid-data error occurred. For example, the fax job identified by the *JobId* parameter is not an outgoing fax transmission; the job must be specified with the JT_SEND job type. |

## Remarks

A fax client application can call the **FaxGetPageData** function for administrative purposes, to display a thumbnail sketch of the fax documents in the fax queue.

The fax service creates fax documents as TIFF Class F files based on the Tagged Image File Format (TIFF) 6.0 specification. The **FaxGetPageData** function returns a TIFF data stream that has a Modified Modified READ (MMR) two-dimensional encoding data compression format. The calling application must decode the data stream. For more information, see [Fax Image Format](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-image-format).

The **FaxGetPageData** function allocates the memory required for the *Buffer* parameter. An application must call the [FaxFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxfreebuffer) function to deallocate the resources associated with this parameter.

For more information, see [Displaying Documents in the Fax Job Queue](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-displaying-documents-in-the-fax-job-queue) and [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).

## See also

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera)

[FaxFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxfreebuffer)

[FaxPrintCoverPage](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxprintcoverpagea)

[FaxStartPrintJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxstartprintjoba)