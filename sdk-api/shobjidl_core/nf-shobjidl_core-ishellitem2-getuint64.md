# IShellItem2::GetUInt64

## Description

Gets the UInt64 value of a specified property key.

## Parameters

### `key` [in]

Type: **REFPROPERTYKEY**

A reference to a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure.

### `pull` [out]

Type: **ULONGLONG***

A pointer to a UInt64 value.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.