## Description

The **OEMDMPARAM** structure is used as an input parameter to the [IPrintOemUI::DevMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-devmode), [IPrintOemUni::DevMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-devmode), and [IPrintOemPS::DevMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps-devmode) methods.

## Members

### `cbSize`

Contains the size of the **OEMDMPARAM** structure. Supplied by the Unidrv or Pscript5 driver.

### `pdriverobj`

#### For IPrintOemUI::DevMode

Not used.

#### For IPrintOemUni::DevMode and IPrintOemPS::DevMode

Pointer to a [**DEVOBJ**](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

### `hPrinter`

Handle to the printer device. Supplied by the Unidrv or Pscript5 driver.

### `hModule`

Handle to the user interface plug-in module. Supplied by the Unidrv or Pscript5 driver.

### `pPublicDMIn`

Pointer to the printer device's public **DEVMODEW** structure. Supplied by the Unidrv or Pscript5 driver. (Valid if the **DevMode** method's *dwMode* value is OEMDM_DEFAULT, OEMDM_CONVERT, or OEMDM_MERGE.)

### `pPublicDMOut`

Pointer to a location to receive public **DEVMODEW** structure contents. Supplied by the Unidrv or Pscript5 driver. (Valid if the **DevMode** method's *dwMode* value is OEMDM_CONVERT or OEMDM_MERGE.)

### `pOEMDMIn`

Pointer to a set of private **DEVMODEW** members. Supplied by the Unidrv or Pscript5 driver. (Valid if the **DevMode** method's *dwMode* value is OEMDM_CONVERT or OEMDM_MERGE.)

### `pOEMDMOut`

Pointer to memory allocated to receive modified private **DEVMODEW** contents. Supplied by the Unidrv or Pscript5 driver. (Valid if the **DevMode** method's *dwMode* value is OEMDM_DEFAULT, OEMDM_CONVERT or OEMDM_MERGE.)

### `cbBufSize`

On input, contains the caller-supplied size of memory space pointed to by **pOEMDMOut**. (Not valid if the **DevMode** method's *dwMode* value is OEMDM_SIZE.)

On output, contains the method-supplied size of the current version of the private **DEVMODEW** section. (Only used if the **DevMode** method's *dwMode* value is OEMDM_SIZE.)

## Remarks

For more information about the use of **OEMDMPARAM** structure members, see the description of the [IPrintOemUI::DevMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-devmode) method.