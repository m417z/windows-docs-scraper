# IPrintCoreUI2::EnumConstrainedOptions

## Description

The `IPrintCoreUI2::EnumConstrainedOptions` method determines which options of a feature are constrained.

## Parameters

### `poemuiobj` [in]

Pointer to the current context, an [OEMUIOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemuiobj) structure.

### `dwFlags` [in]

Is reserved and must be set to zero.

### `pszFeatureKeyword` [in]

Pointer to a caller-supplied buffer containing the single feature keyword of interest to the caller.

### `pmszConstrainedOptionList` [out]

Pointer to a caller-supplied buffer that receives the list of option keywords, in MULTI_SZ format, for this feature. Each keyword represents an option that is constrained in the current configuration.

Set this parameter to **NULL** to simply query for the size (**pcbNeeded*) of the constrained option list without having the list filled in.

### `cbSize` [in]

Specifies the size, in bytes, of the buffer pointed to by *pmszConstrainedOptionList*.

### `pcbNeeded` [out]

Pointer to a memory location that receives the actual size, in bytes, of the constrained option list.

## Return value

This method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. The method should also return this value if none of the feature's options are constrained. In this case, the method should place one null character into the buffer pointed to by *pmszConstrainedOptionList*, and should set **pcbNeeded* to 1. |
| **E_OUTOFMEMORY** | The value in *cbSize* was smaller than the number of bytes to be written to the output buffer (the buffer pointed to by *pmszConstrainedOptionList*).<br><br>The method was called with *pmszConstrainedOptionList* set to **NULL**. |
| **E_INVALIDARG** | The string pointed to by *pszFeatureKeyword* was not a recognized feature.<br><br>The *poemuiobj* parameter pointed to an invalid context object.<br><br>The stickiness of the feature did not match that of the context object pointed to by *peomuiobj*. (See [Replacing Driver-Supplied Property Sheet Pages](https://learn.microsoft.com/windows-hardware/drivers/print/replacing-driver-supplied-property-sheet-pages).) |
| **E_FAIL** | The method failed. |
| **E_NOTIMPL** | The method is not supported. |

## Remarks

This method is supported only for Windows XP Pscript5 UI plug-ins that fully replace the core driver's standard UI pages, and is supported only during the UI plug-in's [IPrintOemUI::DocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-documentpropertysheets) and [IPrintOemUI::DevicePropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-devicepropertysheets) functions, and their property sheet callback routines. See [Replacing Driver-Supplied Property Sheet Pages](https://learn.microsoft.com/windows-hardware/drivers/print/replacing-driver-supplied-property-sheet-pages) for more information.

To reduce the need to make two calls per data access, pass the method an output buffer of a fixed size (1 KB, for example), and then check the function return value. If the method returns S_OK, the buffer already contains the data of interest. If the method returns E_OUTOFMEMORY, the value in **pcbNeeded* is the buffer size needed to hold the data of interest. The caller should then allocate a buffer of that larger size and proceed with a second call to the method.

## See also

[IPrintCoreUI2](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcoreui2)

[IPrintCoreUI2::WhyConstrained](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcoreui2-whyconstrained)

[IPrintOemUI::DevicePropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-devicepropertysheets)

[IPrintOemUI::DocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-documentpropertysheets)

[OEMUIOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemuiobj)