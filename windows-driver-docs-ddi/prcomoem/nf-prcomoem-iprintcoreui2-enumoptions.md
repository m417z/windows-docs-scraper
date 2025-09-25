# IPrintCoreUI2::EnumOptions

## Description

The `IPrintCoreUI2::EnumOptions` method enumerates the available options of a specific feature.

## Parameters

### `poemuiobj` [in]

Pointer to the current context, an [OEMUIOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemuiobj) structure.

### `dwFlags` [in]

Is reserved and must be set to zero.

### `pszFeatureKeyword` [in]

Pointer to a caller-supplied buffer containing an ASCII string specifying a feature keyword whose options are requested.

### `pmszOptionList` [out]

Pointer to a caller-supplied buffer that receives a NULL-delimited list, in MULTI_SZ format, containing the option keywords for the feature keyword pointed to by *pszFeatureKeyword*. This list is terminated with two null characters.

Set this parameter to **NULL** to simply query for the size (**pcbNeeded*) of the option list without having the list filled in.

### `cbSize` [in]

Specifies the size, in bytes, of the buffer pointed to by *pmszOptionList*.

### `pcbNeeded` [out]

Pointer to a memory location that receives the actual size, in bytes, of the option list.

## Return value

This method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | The value in *cbSize* was smaller than the number of bytes to be written to the output buffer (the buffer pointed to by *pmszOptionList*).<br><br>The method was called with *pmszOptionList* set to **NULL**. |
| **E_INVALIDARG** | The string pointed to by *pszFeatureKeyword* is not a recognized feature.<br><br>The *poemuiobj* parameter pointed to an invalid context object. |
| **E_NOTIMPL** | (Pscript only)<br><br>The Pscript5 driver feature is not supported under the current configuration.<br><br>The Pscript5 driver feature is supported under the current configuration, but the Pscript5 driver feature's options are not enumerable. |
| **E_FAIL** | The method failed |

## Remarks

This method is supported only for Windows XP Pscript5 plug-ins, not for Unidrv plug-ins.

To reduce the need to make two calls per data access, pass the method an output buffer of a fixed size (1 KB, for example), and then check the function return value. If the method returns S_OK, the buffer already contains the data of interest. If the method returns E_OUTOFMEMORY, the value in **pcbNeeded* is the buffer size needed to hold the data of interest. The caller should then allocate a buffer of that larger size and proceed with a second call to the method.

For more information, see [Using EnumOptions](https://learn.microsoft.com/windows-hardware/drivers/print/using-enumoptions).

## See also

[IPrintCoreUI2](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcoreui2)

[IPrintCoreUI2::EnumFeatures](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcoreui2-enumfeatures)

[OEMUIOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemuiobj)