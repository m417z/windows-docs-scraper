# SHPropStgCreate function

## Description

[This function is available through Windows XP Service Pack 2 (SP2) and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows.]

Ensures proper handling of code page retrieval or assignment for the requested property set operation.

## Parameters

### `psstg` [in]

Type: **[IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage)***

A pointer to an [IPropertySetStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertysetstorage) interface.

### `fmtid` [in]

Type: **REFFMTID**

A property set ID to open. The values for this parameter can be either one of those defined in [Predefined Property Set Format Identifiers](https://learn.microsoft.com/windows/desktop/Stg/predefined-property-set-format-identifiers) or any other FMTID that you register.

### `pclsid` [in, optional]

Type: **const CLSID***

A pointer to the CLSID associated with the set. This parameter can be **NULL**.

### `grfFlags`

Type: **DWORD**

One or more members of the [PROPSETFLAG](https://learn.microsoft.com/windows/desktop/Stg/propsetflag-constants) enumeration that determine how the property set is created and opened. All sets containing ANSI bytes should be created with PROPSETFLAG_ANSI, otherwise PROPSETFLAG_DEFAULT.

### `grfMode`

Type: **DWORD**

The flags from the [STGM](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants) enumeration that indicate conditions for creating and deleting the object and access modes for the object. Must contain STGM_DIRECT | STGM_SHARE_EXCLUSIVE.

### `dwDisposition`

Type: **DWORD**

One of the following values, defined in Fileapi.h.

#### CREATE_NEW (1)

Create a new set if one does not already exist.

#### CREATE_ALWAYS (2)

Always create a new set, overwriting any existing set.

#### OPEN_EXISTING (3)

Open the existing set.

#### OPEN_ALWAYS (4)

### `ppstg` [out]

Type: **[IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage)****

When this method returns, contains an [IPropertyStorage](https://learn.microsoft.com/windows/desktop/api/propidl/nn-propidl-ipropertystorage) interface pointer.

### `puCodePage` [out, optional]

Type: **UINT***

When this method returns, contains the address of the code page ID for the set.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.