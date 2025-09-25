# ICategoryProvider::CreateCategory

## Description

Creates a category object.

## Parameters

### `pguid` [in]

Type: **const GUID***

A pointer to the **GUID** for the category object.

### `riid` [in]

Type: **REFIID**

The identifier of the object to return. Currently, the only value supported by the system folder view object is IID_ICategorizer.

### `ppv` [out]

Type: **void****

When this method returns, contains the address of a pointer to the category object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.