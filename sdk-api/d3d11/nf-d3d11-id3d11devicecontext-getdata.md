# ID3D11DeviceContext::GetData

## Description

Get data from the graphics processing unit (GPU) asynchronously.

## Parameters

### `pAsync` [in]

Type: **[ID3D11Asynchronous](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11asynchronous)***

A pointer to an [ID3D11Asynchronous](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11asynchronous) interface for the object about which **GetData** retrieves data.

### `pData` [out, optional]

Type: **void***

Address of memory that will receive the data. If **NULL**, **GetData** will be used only to check status. The type of data output depends on the type of asynchronous interface.

### `DataSize` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the data to retrieve or 0. Must be 0 when *pData* is **NULL**.

### `GetDataFlags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Optional flags. Can be 0 or any combination of the flags enumerated by [D3D11_ASYNC_GETDATA_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_async_getdata_flag).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues). A return value of S_OK indicates that the data at *pData* is available for the calling application to access. A return value of S_FALSE indicates that the data is not yet available. If the data is not yet available, the application must call **GetData** until the data is available.

## Remarks

Queries in a deferred context are limited to predicated drawing. That is, you cannot call **ID3D11DeviceContext::GetData** on a deferred context to get data about a query; you can only call **GetData** on the immediate context to get data about a query. For predicated drawing, the results of a predication-type query are used by the GPU and not returned to an application. For more information about predication and predicated drawing, see [D3D11DeviceContext::SetPredication](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-setpredication).

**GetData** retrieves the data that the runtime collected between calls to [ID3D11DeviceContext::Begin](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-begin) and [ID3D11DeviceContext::End](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-end). Certain queries only require a call to **ID3D11DeviceContext::End** in which case the data returned by **GetData** is accurate up to the last call to **ID3D11DeviceContext::End**. For information about the queries that only require a call to **ID3D11DeviceContext::End** and about the type of data that **GetData** retrieves for each query, see [D3D11_QUERY](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_query).

If *DataSize* is 0, **GetData** is only used to check status.

An application gathers counter data by calling [ID3D11DeviceContext::Begin](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-begin), issuing some graphics commands, calling [ID3D11DeviceContext::End](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-end), and then calling **ID3D11DeviceContext::GetData** to get data about what happened in between the **Begin** and **End** calls. For information about performance counter types, see [D3D11_COUNTER](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_counter).

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)