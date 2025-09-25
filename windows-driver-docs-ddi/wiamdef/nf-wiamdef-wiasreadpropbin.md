# wiasReadPropBin function

## Description

The **wiasReadPropBin** function retrieves a binary-data property value from a WIA item.

## Parameters

### `pWiasContext` [in]

Pointer to a WIA item context.

### `propid`

Specifies the property identifier.

### `ppbVal` [out]

Pointer to a memory location that receives the address of a buffer allocated by this function. Upon return, the buffer contains the property's binary data.

### `ppbValOld` [out, optional]

Pointer to a memory location that receives the address of a buffer allocated by the minidriver. Upon return, the buffer contains the previous value of the property's binary data. If this information is not needed, this parameter can be set to **NULL**.

### `bMustExist`

Indicates whether the property must exist. If set to **TRUE**, the property must exist; if set to **FALSE**, the property does not have to exist.

## Return value

On success, the function returns S_OK.

If the function fails, it returns a standard COM error or one of the [WIA error codes](https://learn.microsoft.com/windows/win32/wia/-wia-error-codes).

## Remarks

This function allocates a buffer and stores its address in the *ppbVal* parameter. The minidriver must free the buffer by calling [**CoTaskMemFree**](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree).

## See also

[wiasReadPropFloat](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasreadpropfloat)

[wiasReadPropGuid](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasreadpropguid)

[wiasReadPropLong](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasreadproplong)

[wiasReadPropStr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasreadpropstr)

[wiasWritePropBin](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiaswritepropbin)