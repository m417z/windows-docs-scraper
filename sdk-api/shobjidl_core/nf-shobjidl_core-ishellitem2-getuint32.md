# IShellItem2::GetUInt32

## Description

Gets the UInt32 value of a specified property key.

## Parameters

### `key` [in]

Type: **REFPROPERTYKEY**

A reference to a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure.

### `pui` [out]

Type: **ULONG***

Receives a pointer to a UInt32 value.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.