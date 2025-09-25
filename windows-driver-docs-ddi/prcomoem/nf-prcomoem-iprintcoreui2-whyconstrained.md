# IPrintCoreUI2::WhyConstrained

## Description

The `IPrintCoreUI2::WhyConstrained` method determines why the specified feature/option selection is constrained.

## Parameters

### `poemuiobj` [in]

Pointer to the current context, an [OEMUIOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemuiobj) structure.

### `dwFlags` [in]

Is reserved and must be set to zero.

### `pszFeatureKeyword` [in]

Pointer to a caller-supplied buffer containing the single feature keyword of interest to the caller.

### `pszOptionKeyword` [in]

Pointer to a caller-supplied buffer containing the option keyword.

### `pmszReasonList` [out]

Pointer to a caller-supplied buffer that receives a list of the feature/option keyword pairs that place constraints on the specified feature/option. This list is in MULTI_SZ format with each item in the list separated from the next by a null character. The list is terminated with two null characters.

Set this parameter to **NULL** to simply query for the size (**pcbNeeded*) of the reason list without having the list filled in.

### `cbSize` [in]

Specifies the size, in bytes, of the buffer pointed to by *pmszReasonList*.

### `pcbNeeded` [out]

Pointer to a memory location that receives the actual size, in bytes, of the reason list.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | The value in *cbSize* was smaller than the number of bytes to be written to the output buffer (the buffer pointed to by *pmszReasonList*).<br><br>The method was called with *pmszReasonList* set to **NULL**. |
| **E_NOTIMPL** | The method is not supported. |
| **E_INVALIDARG** | The *poemuiobj* parameter pointed to an invalid context object.<br><br>The feature keyword or option keyword was not recognized.<br><br>The feature stickiness (see [Replacing Driver-Supplied Property Sheet Pages](https://learn.microsoft.com/windows-hardware/drivers/print/replacing-driver-supplied-property-sheet-pages)) did not match that specified in the current context. |
| **E_FAIL** | The method failed |

## Remarks

This method is supported only for Windows XP Pscript5 UI plug-ins that fully replace the core driver's standard UI pages, and is supported only during the UI plug-in's [IPrintOemUI::DocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-documentpropertysheets) and [IPrintOemUI::DevicePropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-devicepropertysheets) functions, and their property sheet callback routines. See [Replacing Driver-Supplied Property Sheet Pages](https://learn.microsoft.com/windows-hardware/drivers/print/replacing-driver-supplied-property-sheet-pages) for more information.

When a user of the OEM UI attempts to select an item that is constrained, the caller can use this method to display a message explaining why the item is constrained. When this method returns, *pmszReasonList* points to a list of one or more feature/option pairs that appear in the current driver settings, but conflict with the selected feature/option keywords. If there were no conflicts, the method should return S_OK, *pmszReasonList* should be filled in with an empty ASCII string containing only a null character, and **pcbNeeded* should be set to 1.

To reduce the need to make two calls per data access, pass the method an output buffer of a fixed size (1 KB, for example), and then check the function return value. If the method returns S_OK, the buffer already contains the data of interest. If the method returns E_OUTOFMEMORY, the value in **pcbNeeded* is the buffer size needed to hold the data of interest. The caller should then allocate a buffer of that larger size and proceed with a second call to the method.

## See also

[IPrintCoreUI2](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcoreui2)

[IPrintCoreUI2::EnumConstrainedOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcoreui2-enumconstrainedoptions)

[IPrintOemUI::DevicePropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-devicepropertysheets)

[IPrintOemUI::DocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-documentpropertysheets)

[OEMUIOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemuiobj)