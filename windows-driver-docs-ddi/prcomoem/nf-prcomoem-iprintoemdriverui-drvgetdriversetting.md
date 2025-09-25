# IPrintOemDriverUI::DrvGetDriverSetting

## Description

The `IPrintOemDriverUI::DrvGetDriverSetting` method is provided by the Unidrv and Pscript5 minidrivers so that user interface plug-ins can obtain the current status of printer features and other internal information.

## Parameters

### `pci`

Caller-supplied pointer to an [OEMUIOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemuiobj) structure.

### `Feature`

Caller-supplied value identifying the printer feature for which option settings are returned. This can be either a string pointer or a constant, as described in the following Remarks section.

### `pOutput`

Caller-supplied pointer to a buffer to receive the specified information.

### `cbSize`

Caller-supplied size, in bytes, of the buffer pointed to by *pOutput*.

### `pcbNeeded`

Caller-supplied pointer to a location to receive the minimum buffer size required to contain the requested information.

### `pdwOptionsReturned`

Caller-supplied pointer to a location to receive the number of option strings placed in *pOutput*.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

When calling the `IPrintOemDriverUI::DrvGetDriverSetting` method, a user interface plug-in can specify either a string pointer or a constant value for *pFeatureKeyword*.

* If *pFeatureKeyword* is a string, it must represent one of the following:
  + A feature name specified in a [Unidrv minidriver](https://learn.microsoft.com/windows-hardware/drivers/print/unidrv-minidrivers) GPD file, or,
  + A keyword argument to an ***OpenUI** entry in a Pscript5 minidriver's PPD file.

  The method returns one or more NULL-terminated strings in the buffer pointed to by *pOutput*. Each string represents the name of a currently selected option.The number of strings is returned in *pdwOptionsReturned*.
* If *pFeatureKeyword* is a constant, it must be one of the **OEMGDS_**-prefixed constants defined in printoem.h. The method returns the value indicated by the specified constant by placing it in the buffer pointed to by *pOutput*. The value returned in *pdwOptionsReturned* is always 1.