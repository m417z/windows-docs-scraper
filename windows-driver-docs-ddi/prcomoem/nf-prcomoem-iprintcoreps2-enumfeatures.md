# IPrintCorePS2::EnumFeatures

## Description

The `IPrintCorePS2::EnumFeatures` method enumerates a printer's available features.

## Parameters

### `pdevobj` [in]

Pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

### `dwFlags` [in]

Is reserved and must be set to zero.

### `pmszFeatureList` [out]

Pointer to a caller-supplied buffer that receives a null-delimited list of feature keywords in MULTI_SZ format. The list is terminated with two null characters.

Set this parameter to **NULL** to simply query for the size (**pcbNeeded*) of the feature list without having the list filled in.

### `cbSize` [in]

Specifies the size, in bytes, of the buffer pointed to by *pmszFeatureList*.

### `pcbNeeded` [out]

Pointer to a memory location that receives the actual size, in bytes, of the requested data.

## Return value

This method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | The value in *cbSize* was smaller than the number of bytes to be written to the output buffer (the buffer pointed to by *pmszFeatureList*).<br><br>The method was called with *pmszFeatureList* set to **NULL**. |
| **E_INVALIDARG** | The *pdevobj* parameter pointed to an invalid driver context object. |
| **E_FAIL** | The method failed. |

## Remarks

[printer-sticky](https://learn.microsoft.com/windows-hardware/drivers/) features (see [Replacing Driver-Supplied Property Sheet Pages](https://learn.microsoft.com/windows-hardware/drivers/print/replacing-driver-supplied-property-sheet-pages)), such as those that determine installable memory and the presence of optional accessories, are included in the feature keyword list, which appears in the output buffer pointed to by *pmszFeatureList*. For Pscript5, such features have the **OpenGroupType** feature attribute set to "InstallableOptions".

To reduce the need to make two calls per data access, pass the method an output buffer of a fixed size (1 KB, for example), and then check the function return value. If the method returns S_OK, the buffer already contains the data of interest. If the method returns E_OUTOFMEMORY, the value in **pcbNeeded* is the buffer size needed to hold the data of interest. The caller should then allocate a buffer of that larger size and proceed with a second call to the method.

This method is supported for any Pscript5 render plug-in.

For more information, see [Using EnumFeatures](https://learn.microsoft.com/windows-hardware/drivers/print/using-enumfeatures).

## See also

[DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj)

[IPrintCorePS2](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcoreps2)

[IPrintCorePS2::EnumOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcoreps2-enumoptions)