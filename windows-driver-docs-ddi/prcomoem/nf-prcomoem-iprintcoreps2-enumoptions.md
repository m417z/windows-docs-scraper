# IPrintCorePS2::EnumOptions

## Description

The `IPrintCorePS2::EnumOptions` method enumerates the available options of a specific feature.

## Parameters

### `pdevobj` [in]

Pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

### `dwFlags` [in]

Is reserved and must be set to zero.

### `pszFeatureKeyword` [in]

Pointer to a caller-supplied buffer containing an ASCII string, specifying a feature keyword whose options are requested.

### `pmszOptionList` [out]

Pointer to a caller-supplied buffer that receives a null-delimited list, in MULTI_SZ format, containing the option keywords for the feature keyword pointed to by *pszFeatureKeyword*. This list is terminated with two null characters.

Set this parameter to **NULL** to simply query for the size (**pcbNeeded*) of the option list without having the list filled in.

### `cbSize` [in]

Specifies the size, in bytes, of the buffer pointed to by *pmszOptionList*.

### `pcbNeeded` [out]

Pointer to a memory location that receives the actual size, in bytes, of the requested data.

## Return value

This method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | The value in *cbSize* was smaller than the number of bytes to be written to the output buffer (the buffer pointed to by *pmszOptionList*).<br><br>The method was called with *pmszOptionList* set to **NULL**. |
| **E_INVALIDARG** | The string pointed to by *pszFeatureKeyword* is not a recognized feature.<br><br>The *pdevobj* parameter pointed to an invalid driver context object. |
| **E_NOTIMPL** | (Pscript only)<br><br>The Pscript5 driver feature is not supported under the current configuration.<br><br>The Pscript5 driver feature is supported under the current configuration, but the Pscript5 driver feature's options are not enumerable. |
| **E_FAIL** | The method failed. |

## Remarks

To reduce the need to make two calls per data access, pass the method an output buffer of a fixed size (1 KB, for example), and then check the function return value. If the method returns S_OK, the buffer already contains the data of interest. If the method returns E_OUTOFMEMORY, the value in **pcbNeeded* is the buffer size needed to hold the data of interest. The caller should then allocate a buffer of that larger size and proceed with a second call to the method.

This method is supported for any Pscript5 render plug-in.

For more information, see [Using EnumOptions](https://learn.microsoft.com/windows-hardware/drivers/print/using-enumoptions).

## See also

[DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj)

[IPrintCorePS2](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcoreps2)

[IPrintCorePS2::EnumFeatures](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcoreps2-enumfeatures)