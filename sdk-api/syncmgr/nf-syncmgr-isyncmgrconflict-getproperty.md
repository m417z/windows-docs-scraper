# ISyncMgrConflict::GetProperty

## Description

Gets a conflict property, given a property key.

## Parameters

### `propkey` [in]

Type: **REFPROPERTYKEY**

A reference to the property key for which the property is being requested. Any property key is valid here, including but not limited to the following values.

#### PKEY_ItemNameDisplay

Name of the conflict.

#### PKEY_Sync_ConflictDescription

Summary of the conflict.

#### PKEY_Sync_HandlerID

Sync handler that created the conflict.

#### PKEY_Sync_ItemID

Sync item that created the conflict.

#### PKEY_DateModified

Time the conflict was detected.

### `ppropvar` [out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

When this method returns, contains a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure that contains the requested property.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The properties returned are properties of the conflict and not of the **IShellItems** that are in conflict.

If the [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) referenced in *propkey* is not present in the property store, this method returns S_OK and the **vt** member of the structure pointed to by *ppropvar* is set to VT_EMPTY.