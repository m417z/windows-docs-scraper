# IPrintOemUni3::GetImplementedMethod

## Description

The `IPrintOemUni3::GetImplementedMethod` method is used by Unidrv to determine which **IPrintOemUni** interface methods a rendering plug-in has implemented.

## Parameters

### `pMethodName`

Caller-supplied pointer to a string that represents the name of an **IPrintOemUni** interface method, such as "ImageProcessing" for **IPrintOemUni3::ImageProcessing** or "FilterGraphics" for **IPrintOemUni3::FilterGraphics**.

## Return value

`GetImplementedMethod` must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded (that is, the specified method is implemented). |
| **S_FALSE** | The operation failed (that is, the specified method is not implemented). |

## Remarks

A rendering plug-in for Unidrv must implement the `IPrintOemUni3::GetImplementedMethod` method, together with several other methods in this interface. For those methods that are optional, `IPrintOemUni3::GetImplementedMethod` examines the input method name string and returns a value that indicates whether the associated method is implemented within the plug-in. For example, if `IPrintOemUni3::GetImplementedMethod` is called with the string "ImageProcessing", it should return S_OK if the **IPrintOemUni3::ImageProcessing** method is implemented and S_FALSE otherwise.

The `IPrintOemUni3::GetImplementedMethod` method must recognize the following name strings:

"CommandCallback"

"Compression"

"DownloadCharGlyph"

"DownloadFontHeader"

"DownloadPattern"

"FilterGraphics"

"GetPDEVAdjustment"

"HalftonePattern"

"ImageProcessing"

"MemoryUsage"

"OutputCharStr"

"SendFontCmd"

"SetBandSize"

"TextOutAsBitmap"

"TTDownloadMethod"

"TTYGetInfo"

"WritePrinter"