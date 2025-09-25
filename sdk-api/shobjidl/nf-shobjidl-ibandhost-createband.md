# IBandHost::CreateBand

## Description

Creates a specified band.

## Parameters

### `rclsidBand` [in]

Type: **REFCLSID**

A reference to a CLSID. Used to ensure a duplicate band is not created.

### `fAvailable` [in]

Type: **BOOL**

Specifies band availability.

### `fVisible` [in]

Type: **BOOL**

Specifies band visibility.

### `riid` [in]

Type: **REFIID**

A reference to a desired IID.

### `ppv` [out]

Type: **void****

Contains the address of a pointer to a band specified by *riid*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.