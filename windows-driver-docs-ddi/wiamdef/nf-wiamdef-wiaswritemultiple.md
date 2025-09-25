# wiasWriteMultiple function

## Description

The **wiasWriteMultiple** function writes multiple property values to a WIA item.

## Parameters

### `pWiasContext` [in]

Pointer to a WIA item context.

### `ulCount`

Specifies the total number of properties to write.

### `ps` [in]

Pointer to the first element of an array of PROPSPEC structures that indicate the properties to write.

### `pv`

Pointer to the first element of an array of PROPVARIANT structures that contain the values to write to the item.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error or one of the WIA_ERROR_XXX errors (described in the Microsoft Windows SDK documentation).

## Remarks

This function operates in a similar manner to **IPropertyStorage::WriteMultiple**, which is described in the Windows SDK documentation. The PROPSPEC and PROPVARIANT structures are also described in the Windows SDK documentation.

## See also

[wiasReadMultiple](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasreadmultiple)