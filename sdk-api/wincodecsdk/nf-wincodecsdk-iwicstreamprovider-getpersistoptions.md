# IWICStreamProvider::GetPersistOptions

## Description

Gets the persist options used when initializing the component with a stream.

## Parameters

### `pdwPersistOptions` [out]

Type: **DWORD***

Pointer that receives the persist options used when initializing the component with a stream. If none were provided, **WICPersistOptionDefault** is returned.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.