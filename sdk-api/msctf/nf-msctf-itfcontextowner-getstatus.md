# ITfContextOwner::GetStatus

## Description

The **ITfContextOwner::GetStatus** method obtains the status of a document. The document status is returned through the [TS_STATUS](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_status) structure.

## Parameters

### `pdcs` [out]

Receives the [TS_STATUS](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_status) structure that contains the document status. Cannot be **NULL**.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## See also

[ITextStoreACP::GetStatus](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-getstatus)

[ITfContextOwner](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontextowner)

[TS_STATUS](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_status)