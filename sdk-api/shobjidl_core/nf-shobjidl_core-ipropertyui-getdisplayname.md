# IPropertyUI::GetDisplayName

## Description

Developers should use [IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription) instead. Gets a string specifying the name of the property suitable for display to users.

## Parameters

### `fmtid` [in]

Type: **REFFMTID**

The FMTID of the property.

### `pid` [in]

Type: **PROPID**

The PROPID of the property.

### `flags` [in]

Type: **PROPERTYUI_NAME_FLAGS**

One of the following PROPERTYUI_NAME_FLAGS values:

#### PUIFNF_DEFAULT (0x00000000)

0x00000000.

#### PUIFNF_MNEMONIC (0x00000001)

0x00000001. Include mnemonic in display name.

### `pwszText` [out]

Type: **LPWSTR**

A string specifying the property.

### `cchText` [in]

Type: **DWORD**

The length of the property display name.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.