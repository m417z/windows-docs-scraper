# SHCoCreateInstance function

## Description

[**SHCoCreateInstance** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance).]

Creates Component Object Model (COM) objects that are implemented in Shell32.dll.

## Parameters

### `pszCLSID` [in, optional]

Type: **PCWSTR**

A pointer to a string to convert to a CLSID. If **NULL**, *pclsid* is used as the CLSID.

### `pclsid` [in, optional]

Type: **const CLSID***

The CLSID to create.

### `pUnkOuter` [in, optional]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to outer [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown). Used for aggregation.

### `riid` [in]

Type: **REFIID**

A reference to the IID of the interface to retrieve through *ppv*.

### `ppv` [out]

Type: **void****

When this function returns successfully, receives the interface pointer requested in *riid*.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

We recommend that you use the [IID_PPV_ARGS](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-iid_ppv_args) macro, defined in Objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, which eliminates the possibility of a coding error in *riid* that could lead to unexpected results.