# StgMakeUniqueName function

## Description

Creates a unique name for a stream or storage object from a template.

## Parameters

### `pstgParent` [in]

Type: **[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage)***

A pointer to an [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) object.

### `pszFileSpec` [in]

Type: **PCWSTR**

The format or template for the name of the stream or storage object.

### `grfMode` [in]

Type: **DWORD**

The access mode to use when opening the stream or storage object. For more information and descriptions of the possible values, see STGM Constants.

### `riid` [in]

Type: **REFIID**

A reference to the IID of the interface to retrieve through *ppv*, typically IID_IStorage or IID_IStream.

### `ppv` [out]

Type: **void****

When this method returns, contains the interface pointer requested in *riid*. This is typically [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) or [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream).

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

It is recommended that you use the **IID_PPV_ARGS** macro, defined in Objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, which eliminates the possibility of a coding error.