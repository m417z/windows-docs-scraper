# wiasReadMultiple function

## Description

The **wiasReadMultiple** function retrieves multiple property values from a WIA item.

## Parameters

### `pWiasContext` [in]

Pointer to a WIA item context.

### `ulCount`

Specifies the number of properties to read.

### `ps` [in]

Pointer to the first element of an array of [PROPSPEC](https://learn.microsoft.com/windows/win32/api/propidl/ns-propidl-propspec) structures, containing the properties to read.

### `pv` [out]

Pointer to the first element of an array of [PROPVARIANT](https://learn.microsoft.com/windows/win32/api/propidl/ns-propidl-propvariant) structures. Upon return, these structures contain new values for the properties.

### `pvOld` [out, optional]

Pointer to the first element of an array of PROPVARIANT structures previously allocated by the minidriver. Upon return, the array contains the previous values of the property data. If this information is not needed, this parameter can be set to **NULL**.

## Return value

On success, the function returns S_OK.

If the function fails, it returns a standard COM error or one of the [WIA error codes](https://learn.microsoft.com/windows/win32/wia/-wia-error-codes).

## Remarks

This function reads multiple properties from a WIA item. When the call succeeds, the minidriver must call [**PropVariantClear**](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-propvariantclear) on each element in the array specified by the *pv* parameter. See [**IPropertyStorage::ReadMultiple**](https://learn.microsoft.com/windows/win32/api/propidl/nf-propidl-ipropertystorage-readmultiple) for more information.

## See also

[wiasWriteMultiple](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiaswritemultiple)