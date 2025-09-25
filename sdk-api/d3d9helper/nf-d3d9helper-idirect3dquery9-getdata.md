# IDirect3DQuery9::GetData

## Description

Polls a queried resource to get the query state or a query result. For more information about queries, see [Queries (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/queries).

## Parameters

### `pData` [in, out]

Type: **void***

Pointer to a buffer containing the query data. The user is responsible for allocating this. *pData* may be **NULL** only if dwSize is 0.

### `dwSize` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of bytes of data in *pData*. If you set dwSize to zero, you can use this method to poll the resource for the query status. See remarks.

### `dwGetDataFlags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Data flags specifying the query type. Valid values are either 0 or [D3DGETDATA_FLUSH](https://learn.microsoft.com/windows/desktop/direct3d9/d3dgetdata-flush). Use 0 to avoid flushing batched queries to the driver and use D3DGETDATA_FLUSH to go ahead and flush them. For applications writing their own version of waiting, a query result is not realized until the driver receives a flush.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

The return type identifies the query state (see [Queries (Direct3D 9)](https://learn.microsoft.com/windows/desktop/direct3d9/queries)). The method returns S_OK if the query data is available and S_FALSE if it is not. These are considered successful return values. If the method fails when [D3DGETDATA_FLUSH](https://learn.microsoft.com/windows/desktop/direct3d9/d3dgetdata-flush) is used, the return value can be D3DERR_DEVICELOST.

## Remarks

It is possible to lose the device while polling for query status. When [D3DGETDATA_FLUSH](https://learn.microsoft.com/windows/desktop/direct3d9/d3dgetdata-flush) is specified, this method will return D3DERR_DEVICELOST in response to a lost device. This allows an application to prevent threads from endlessly polling due to a lost device (which cannot respond to the query).

An application must never write code that only invokes GetData ( ... , 0 ), expecting that GetData will eventually return S_OK by itself over time. This is true, even if the application has used the FLUSH flag with GetData in the past. For example:

```
// Enables an infinite loop:
while( pQuery->GetData( ... , 0 ) == S_FALSE ) ;

// Still enables an infinite loop:
pQuery->GetData( ... , D3DGETDATA_FLUSH );
while( pQuery->GetData( ... , 0 ) == S_FALSE ) ;

// Does not enable an infinite loop because eventually the command
// buffer will fill up and that will cause a flush to occur.
while( pQuery->GetData( ..., 0 ) == S_FALSE ) {
	pDevice->SetTexture(...);
	pDevice->Draw(...);
}

```

## See also

[IDirect3DQuery9](https://learn.microsoft.com/windows/desktop/api/d3d9helper/nn-d3d9helper-idirect3dquery9)