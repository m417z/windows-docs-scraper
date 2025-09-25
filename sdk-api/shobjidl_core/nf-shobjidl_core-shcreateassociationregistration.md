# SHCreateAssociationRegistration function

## Description

Creates an [IApplicationAssociationRegistration](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationassociationregistration) object based on the stock implementation of the interface provided by Windows.

## Parameters

### `riid` [in]

Type: **REFIID**

A reference to the IID of the requested interface.

### `ppv` [out]

Type: **void****

When this function returns, contains the address of a pointer to the [IApplicationAssociationRegistration](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationassociationregistration) object.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.