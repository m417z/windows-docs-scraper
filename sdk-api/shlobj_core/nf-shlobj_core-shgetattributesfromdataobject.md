# SHGetAttributesFromDataObject function

## Description

[**SHGetAttributesFromDataObject** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Retrieves specified pieces of information from a system data object.

## Parameters

### `pdo` [in, optional]

Type: **[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)***

The data object from which to retrieve the information.

### `dwAttributeMask`

Type: **DWORD**

One or more of the [SFGAO](https://learn.microsoft.com/windows/win32/shell/sfgao) flags that indicate which pieces of information the calling application wants to retrieve.

### `pdwAttributes` [out, optional]

Type: **DWORD***

A pointer to a **DWORD** value that, when this function returns successfully, receives one or more [SFGAO](https://learn.microsoft.com/windows/win32/shell/sfgao) flags that indicate the attributes, among those requested, that are common to all items in *pdo*. This pointer can be **NULL** if this information is not needed.

### `pcItems` [out, optional]

Type: **UINT***

A pointer to a **UINT** that, when this function returns successfully, receives the number of PIDLs in the data object pointed to by *pdo*. This pointer can be **NULL** if this information is not needed.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **S_FALSE** | The object is not a system data object. In this case, *pdwAttributes* is set to 0. |