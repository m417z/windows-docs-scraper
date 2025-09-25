# SHPropStgReadMultiple function

## Description

[This function is available through Windows XP Service Pack 2 (SP2) and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows.]

Wraps the [IPropertyStorage::ReadMultiple](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-readmultiple) function to ensure that ANSI and Unicode translations are handled properly for deprecated property sets.

## Parameters

### `pps` [in]

Type: **[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage)***

An [IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage) interface pointer that identifies the property store.

### `uCodePage`

Type: **UINT**

A code page value for ANSI string properties.

### `cpspec`

Type: **ULONG**

A count of properties being read.

### `rgpspec` [in]

Type: **PROPSPEC const[]**

An array of properties to be read.

### `rgvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)[]**

An array of [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) types that, when this function returns successfully, receives the property values.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.