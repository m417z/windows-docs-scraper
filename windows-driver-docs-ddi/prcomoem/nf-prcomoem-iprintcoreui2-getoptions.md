# IPrintCoreUI2::GetOptions

## Description

The `IPrintCoreUI2::GetOptions` method retrieves the driver's current feature settings in the format of a list of feature/option keyword pairs.

## Parameters

### `poemuiobj` [in]

Pointer to the current context, an [OEMUIOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemuiobj) structure.

### `dwFlags` [in]

Is reserved and must be set to zero.

### `pmszFeaturesRequested` [in]

Pointer to caller-supplied buffer containing a list of feature keywords (in MULTI_SZ format) whose settings are requested. Set this parameter to **NULL** to obtain settings for all features.

### `cbIn` [in]

Specifies the size, in bytes, of the buffer pointed to by *pmszFeaturesRequested*. The size includes the last MULTI_SZ null character.

### `pmszFeatureOptionBuf` [out]

Pointer to a caller-supplied buffer that receives a list of feature/option keyword pairs (in MULTI_SZ format) obtained from the driver settings. Each feature/option keyword pair contains the feature keyword name, a null character, the option keyword name, and another null character. The list is terminated by two null characters.

### `cbSize` [in]

Specifies the size, in bytes, of the buffer pointed to by *pmszFeatureOptionBuf*.

### `pcbNeeded` [out]

Pointer to a memory location that receives the actual size, in bytes, of the feature/option keyword pairs.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | The value in *cbSize* was smaller than the number of bytes to be written to the output buffer (the buffer pointed to by *pmszFeatureOptionBuf*).<br><br>The method was called with *pmszFeatureOptionBuf* set to **NULL**. |
| **E_INVALIDARG** | The input buffer (the buffer pointed to by *pmszFeaturesRequested*) was provided, but its contents were not in MULTI_SZ format.<br><br>The *poemuiobj* parameter pointed to an invalid context object. |
| **E_NOTIMPL** | The method is not supported. |
| **E_FAIL** | The method failed |

## Remarks

This method is supported only for Windows XP Pscript5 UI plug-ins that fully replace the core driver's standard UI pages, and is supported only during the UI plug-in's [IPrintOemUI::DocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-documentpropertysheets) and [IPrintOemUI::DevicePropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-devicepropertysheets) functions, and their property sheet callback routines. See [Replacing Driver-Supplied Property Sheet Pages](https://learn.microsoft.com/windows-hardware/drivers/print/replacing-driver-supplied-property-sheet-pages) for more information.

If a requested feature keyword is not recognized, or recognized but not supported in the current sticky mode ([document-sticky](https://learn.microsoft.com/windows-hardware/drivers/) or [printer-sticky](https://learn.microsoft.com/windows-hardware/drivers/) -- see [Replacing Driver-Supplied Property Sheet Pages](https://learn.microsoft.com/windows-hardware/drivers/print/replacing-driver-supplied-property-sheet-pages)), or the feature keyword is recognized but there is currently no option selection for it, the feature is simply ignored and the feature/option keyword pair is not placed in the output buffer.

To reduce the need to make two calls per data access, pass the method an output buffer of a fixed size (1 KB, for example), and then check the function return value. If the method returns S_OK, the buffer already contains the data of interest. If the method returns E_OUTOFMEMORY, the value in **pcbNeeded* is the buffer size needed to hold the data of interest. The caller should then allocate a buffer of that larger size and proceed with a second call to the method.

For more information, see [Using GetOptions and SetOptions](https://learn.microsoft.com/windows-hardware/drivers/print/using-getoptions-and-setoptions).

## See also

[IPrintCoreUI2](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcoreui2)

[IPrintCoreUI2::SetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcoreui2-setoptions)

[IPrintOemUI::DevicePropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-devicepropertysheets)

[IPrintOemUI::DocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-documentpropertysheets)

[OEMUIOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemuiobj)