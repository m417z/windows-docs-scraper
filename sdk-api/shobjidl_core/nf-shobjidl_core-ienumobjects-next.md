# IEnumObjects::Next

## Description

Gets the next specified number and type of objects.

## Parameters

### `celt` [in]

Type: **ULONG**

The number of objects to retrieve.

### `riid` [in]

Type: **REFIID**

Reference to the desired interface ID.

### `rgelt` [out]

Type: **void****

When this method returns, contains the interface pointer requested in *riid*.

### `pceltFetched` [out, optional]

Type: **ULONG***

Pointer to a **ULONG** value that, when this method returns, states the actual number of objects retrieved. This value can be **NULL**.

## Return value

Type: **HRESULT**

Returns S_OK if the method successfully retrieved the requested objects. This method only returns S_OK if the full count of requested items are successfully retrieved.

S_FALSE indicates that more items were requested than remained in the enumeration.