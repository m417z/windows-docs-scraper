## Description

Retrieves a DXGI interface from an object.

## Parameters

### `object`

Type: **Platform::Object\^**

The object to retrieve the DXGI interface from.

### `iid`

Type: **REFIID**

The ID of the interface to retrieve.

### `p`

Type: **void\*\***

On return, contains the retrieved DXGI interface.

## Return value

Type: [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes)

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/desktop/com/com-error-codes-10).

## Remarks

## See also