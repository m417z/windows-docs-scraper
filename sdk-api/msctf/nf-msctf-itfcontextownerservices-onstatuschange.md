# ITfContextOwnerServices::OnStatusChange

## Description

The **ITfContextOwnerServices::OnStatusChange** method is called by the context owner when the **dwDynamicFlags** member of the [TS_STATUS](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_status) structure returned by the [ITfContextOwner::GetStatus](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontextowner-getstatus) method changes.

## Parameters

### `dwFlags` [in]

Specifies the dynamic status flag.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## See also

[ITfContextOwner::GetStatus](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontextowner-getstatus)

[ITfContextOwnerServices](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontextownerservices)

[TS_STATUS](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_status)