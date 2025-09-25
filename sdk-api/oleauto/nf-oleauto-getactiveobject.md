# GetActiveObject function

## Description

Retrieves a pointer to a running object that has been registered with OLE.

## Parameters

### `rclsid` [in]

The class identifier (CLSID) of the active object from the OLE registration database.

### `pvReserved`

Reserved for future use. Must be null.

### `ppunk` [out]

The requested active object.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.