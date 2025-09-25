# IPrintCoreUI2::SetOptions

## Description

The `IPrintCoreUI2::SetOptions` method sets the driver's feature settings.

## Parameters

### `poemuiobj` [in]

Pointer to the current context, an [OEMUIOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemuiobj) structure.

### `dwFlags` [in]

Specifies whether the core driver is to resolve conflicts. This parameter must be set to one of the following values:

| Value | Meaning |
| --- | --- |
| SETOPTIONS_FLAG_KEEP_CONFLICT | Ask core driver to not resolve any conflict that arises. |
| SETOPTIONS_FLAG_RESOLVE_CONFLICT | Ask core driver to resolve any conflict that arises. |

### `pmszFeatureOptionBuf` [in]

Pointer to a caller-supplied buffer containing a list of feature/option keyword pairs in MULTI_SZ format. Each item in this list is separated from the next by a null character, and the list is terminated with two null characters.

### `cbIn` [in]

Specifies the size, in bytes, of the buffer pointed to by *pmszFeatureOptionBuf*. This size includes the last MULTI_SZ null character.

### `pdwResult` [out]

Pointer to a memory location that receives one of the following values. These constants are defined in printoem.h.

| Value | Meaning |
| --- | --- |
| SETOPTIONS_RESULT_CONFLICT_REMAINED | The core driver found conflicts, but has left them unresolved. |
| SETOPTIONS_RESULT_CONFLICT_RESOLVED | The core driver found and resolved all conflicts. |
| SETOPTIONS_RESULT_NO_CONFLICT | The core driver did not find any conflict. |

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | The method is not supported.<br><br>A structure of the type specified by *dwLevel* is not supported. |
| **E_INVALIDARG** | The value in *dwFlags* was incorrect.<br><br>The input buffer (pointed to by *pmszFeatureOptionBuf*) was not in MULTI_SZ format.<br><br>The *poemuiobj* parameter pointed to an invalid context object. |
| **E_FAIL** | The method failed |

## Remarks

This method is supported only for Windows XP Pscript5 plug-ins, not for Unidrv plug-ins.

This method is called to set the driver's feature settings using a list of feature/option keyword pairs. The caller can access the resultant feature settings using the [IPrintCoreUI2::GetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcoreui2-getoptions) method.

If this method returns any value other than S_OK, then it did not make any change in the driver's feature settings.

The *pmszFeatureOptionBuf* input buffer must be constructed in the same way as the output buffer of the **IPrintCoreUI2::GetOptions** method. That is, the feature/option keyword pairs must be in MULTI_SZ format, and each item in the list is separated from the next by a null character. A pair of null characters terminates the list.

If the input buffer contains a feature keyword or its option keyword that is not recognized, or the feature is recognized but not supported in the current sticky mode (see [Replacing Driver-Supplied Property Sheet Pages](https://learn.microsoft.com/windows-hardware/drivers/print/replacing-driver-supplied-property-sheet-pages)), then the feature/option pair is ignored, and the current option for that feature continues to be in effect.

This method is supported only for UI plug-ins that fully replace the core driver's standard UI pages, and is supported only during the UI plug-in's [IPrintOemUI::DocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-documentpropertysheets) and [IPrintOemUI::DevicePropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-devicepropertysheets) functions, and their property sheet callback routines.

For more information, see [Using GetOptions and SetOptions](https://learn.microsoft.com/windows-hardware/drivers/print/using-getoptions-and-setoptions).

## See also

[IPrintCoreUI2](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcoreui2)

[IPrintCoreUI2::GetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcoreui2-getoptions)

[IPrintOemUI::DevicePropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-devicepropertysheets)

[IPrintOemUI::DocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-documentpropertysheets)

[OEMUIOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemuiobj)