# wiauGetValidFormats function

## Description

The **wiauGetValidFormats** function calls the [IWiaMiniDrv::drvGetWiaFormatInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvgetwiaformatinfo) method and makes a list of valid formats, using a specified tymed value.

## Parameters

### `pDrv` [in]

Points to the WIA minidriver object. This parameter should be set to **this**.

### `pWiasContext` [in]

Pointer to a WIA item context.

### `TymedValue`

Specifies the tymed value to search for.

### `pNumFormats` [out]

Pointer to a memory location that receives the number of formats.

### `ppFormatArray` [out]

Pointer to a memory location that receives the address of the array of format GUIDs.

## Return value

On success, the function returns S_OK. If the function fails, it returns a standard COM error.

## Remarks

The caller of this function is responsible for freeing the format array, using the **delete[]** operator.