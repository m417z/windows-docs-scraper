# IPrintCorePS2::GetOptions

## Description

The `IPrintCorePS2::GetOptions` method retrieves the driver's current feature settings in the format of a list of feature/option keyword pairs.

## Parameters

### `pdevobj` [in]

Pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

### `dwFlags` [in]

Is reserved and must be set to zero.

### `pmszFeaturesRequested` [in]

Pointer to caller-supplied buffer containing a list of feature keywords (in MULTI_SZ format) whose settings are requested. Set this parameter to **NULL** to obtain settings for all features.

### `cbIn` [in]

Specifies the size, in bytes, of the buffer pointed to by *pmszFeaturesRequested*. The size includes the last MULTI_SZ null character.

### `pmszFeatureOptionBuf` [out]

Pointer to a caller-supplied buffer that receives a list of feature/option keyword pairs (in MULTI_SZ format) obtained from the driver settings. Each feature/option keyword pair contains the feature keyword name, a null character, the option keyword name, and another null character. The list is terminated by two NULL characters.

### `cbSize` [in]

Specifies the size, in bytes, of the buffer pointed to by *pmszFeatureOptionBuf*.

### `pcbNeeded` [out]

Pointer to a memory location that receives the actual size, in bytes, of the requested data.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_OUTOFMEMORY** | The value in *cbSize* was smaller than the number of bytes to be written to the output buffer (the buffer pointed to by *pmszFeatureOptionBuf*).<br><br>The method was called with *pmszFeatureOptionBuf* set to **NULL**. |
| **E_INVALIDARG** | The input buffer (the buffer pointed to by *pmszFeaturesRequested*) was provided, but its contents were not in MULTI_SZ format.<br><br>The *pdevobj* parameter pointed to an invalid driver context object. |
| **E_NOTIMPL** | The method is not supported. |
| **E_FAIL** | The method failed. |

## Remarks

This method supports both [document-sticky](https://learn.microsoft.com/windows-hardware/drivers/) and [printer-sticky](https://learn.microsoft.com/windows-hardware/drivers/) features. It is supported only after the core driver finishes its [DrvEnablePDEV](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvenablepdev) processing, which sets up all option settings. A call to `IPrintCorePS2::GetOptions` when it is not supported should cause it to return E_NOTIMPL. For example, when the core driver calls a render plug-in's [IPrintOemPS::EnablePDEV](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps-enablepdev) method, the driver is still occupied with its **DrvEnablePDEV** processing, so if the plug-in calls `IPrintCorePS2::GetOptions` within the plug-in's **IPrintOemPS::DevMode** method, the plug-in receives the E_NOTIMPL return value. However, because the plug-in's **IPrintOemPS::EnablePDEV** method is called after the core driver finishes its **DrvEnablePDEV** processing, the plug-in is able to call `IPrintCorePS2::GetOptions` successfully within its **IPrintOemPS::EnablePDEV** method.

If a requested feature keyword is not recognized, or the feature is recognized but there is currently no option selection for it, the feature is ignored and the feature/option keyword pair is not placed in the output buffer.

To reduce the need to make two calls per data access, pass the method an output buffer of a fixed size (1 KB, for example), and then check the function return value. If the method returns S_OK, the buffer already contains the data of interest. If the method returns E_OUTOFMEMORY, the value in **pcbNeeded* is the buffer size needed to hold the data of interest. The caller should then allocate a buffer of that larger size and proceed with a second call to the method.

This method is supported for any Pscript5 render plug-in.

For more information, see [Using GetOptions and SetOptions](https://learn.microsoft.com/windows-hardware/drivers/print/using-getoptions-and-setoptions).

## See also

[DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj)

[DrvEnablePDEV](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvenablepdev)

[IPrintCorePS2](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcoreps2)

[IPrintOemPS::DevMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps-devmode)

[IPrintOemPS::EnablePDEV](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps-enablepdev)