# IObjectWithBackReferences::RemoveBackReferences

## Description

Removes all back references held by an object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is used for all tasks associated with freeing/releasing back references held
by an object, and may prepare an object for reuse.