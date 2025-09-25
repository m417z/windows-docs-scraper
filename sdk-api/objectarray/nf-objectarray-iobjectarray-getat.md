# IObjectArray::GetAt

## Description

Provides a pointer to a specified object's interface. The object and interface are specified by index and interface ID.

## Parameters

### `uiIndex` [in]

Type: **UINT**

The index of the object

### `riid` [in]

Type: **REFIID**

Reference to the desired interface ID.

### `ppv` [out]

Type: **void****

Receives the interface pointer requested in *riid*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.