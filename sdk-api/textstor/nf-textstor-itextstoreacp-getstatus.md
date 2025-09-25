# ITextStoreACP::GetStatus

## Description

The **ITextStoreACP::GetStatus** method obtains the document status. The document status is returned through the [TS_STATUS](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_status) structure.

## Parameters

### `pdcs` [out]

Receives the **TS_STATUS** structure that contains the document status. Cannot be **NULL**.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | The pointer to the TS_STATUS parameter is invalid. |

## See also

[ITextStoreACP](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp)

[ITfContextOwner::GetStatus](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontextowner-getstatus)

[TS_STATUS](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_status)