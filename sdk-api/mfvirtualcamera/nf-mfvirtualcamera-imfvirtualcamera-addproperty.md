## Description

Adds custom device interface properties to the virtual camera.

## Parameters

### `pKey`

Pointer to a [DEVPROPKEY](https://learn.microsoft.com/windows-hardware/drivers/install/devpropkey) to add to the virtual camera device interface. For more information, see [Unified Device Property Model](https://learn.microsoft.com/windows-hardware/drivers/install/unified-device-property-model--windows-vista-and-later-).

### `Type`

Property type for the specified *pKey*. The [DEVPROP_TYPE_NULL](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-null) and [DEVPROP_TYPE_EMPTY](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-empty) types are not supported.

### `pbData`

Pointer to the property data.

### `cbData`

Size in bytes contained in the buffer pointed to by *data*.

## Return value

Returns an HRESULT value, including but not limited to the following values:

| Error code | Description |
|------------|-------------|
| S_OK | Succeeded |
| E_INVALIDARG | An input parameter is invalid. |
| E_ACCESSDENIED | Caller has insufficient permissions to add properties. |

## Remarks

Callers must have administrator-level permissions to use this API. UWP and packaged apps do not have permissions to call this method.

Callers should use caution when adding known Windows device properties as this may have unintended effects.

## See also