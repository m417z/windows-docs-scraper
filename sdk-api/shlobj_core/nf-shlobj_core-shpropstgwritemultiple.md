# SHPropStgWriteMultiple function

## Description

[This function is available through Windows XP Service Pack 2 (SP2) and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows.]

Wraps the [IPropertyStorage::WriteMultiple](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-writemultiple) function to ensure that ANSI and Unicode translations are handled properly for deprecated property sets.

## Parameters

### `pps` [in]

Type: **[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage)***

An [IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage) interface pointer that identifies the property store.

### `puCodePage` [in, out, optional]

Type: **UINT***

A pointer to the code page value for ANSI string properties.

### `cpspec`

Type: **ULONG**

A count of properties being set.

### `rgpspec` [in]

Type: **PROPSPEC const[]**

An array of PROPSPEC structures that contain the property information to be set.

### `rgvar` [in, out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)[]**

An array of [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) types to set the property values.

### `propidNameFirst`

Type: **PROPID**

The minimum value for property identifiers when they must be allocated. The value should be greater than or equal to PID_FIRST_USABLE.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.