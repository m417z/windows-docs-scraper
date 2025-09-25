# AssocCreate function

## Description

Returns a pointer to an [IQueryAssociations](https://learn.microsoft.com/windows/desktop/api/shlwapi/nn-shlwapi-iqueryassociations) object.

## Parameters

### `clsid` [in]

Type: **CLSID**

The CLSID of the object that exposes the interface. This parameter must be set to CLSID_QueryAssociations, which is defined in Shlguid.h.

### `riid` [in]

Type: **REFIID**

Reference to the IID IID_IQueryAssociations, which is defined in Shlguid.h.

### `ppv` [out]

Type: **void***

When this method returns, contains the [IQueryAssociations](https://learn.microsoft.com/windows/desktop/api/shlwapi/nn-shlwapi-iqueryassociations) interface pointer requested in *riid*.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

As of Windows Vista, [AssocCreateForClasses](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-assoccreateforclasses) is preferred to **AssocCreate**.