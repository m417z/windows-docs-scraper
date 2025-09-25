# IPrintOemUni2::GetImplementedMethod

## Description

The `IPrintOemUni2::GetImplementedMethod` method is used by Unidrv to determine which **IPrintOemUni2** interface methods a rendering plug-in has implemented.

## Parameters

### `pMethodName`

Caller-supplied pointer to a string that represents the name of an **IPrintOemUni2** interface method, such as "ImageProcessing" for **IPrintOemUni2::ImageProcessing** or "FilterGraphics" for **IPrintOemUni2::FilterGraphics**.

## Return value

`GetImplementedMethod` must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded (that is, the specified method is implemented). |
| **S_FALSE** | The operation failed (that is, the specified method is not implemented). |

## Remarks

A rendering plug-in for Unidrv must implement the `IPrintOemUni2::GetImplementedMethod` method, together with several other methods in this interface. For those methods that are optional, `IPrintOemUni2::GetImplementedMethod` examines the input method name string and returns a value that indicates whether the associated method is implemented within the plug-in. For example, if `IPrintOemUni2::GetImplementedMethod` is called with the string "ImageProcessing", it should return S_OK if the **IPrintOemUni2::ImageProcessing** method is implemented and S_FALSE otherwise.

The `IPrintOemUni2::GetImplementedMethod` method must recognize the following name strings:

"CommandCallback"

"Compression"

"DownloadCharGlyph"

"DownloadFontHeader"

"FilterGraphics"

"HalftonePattern"

"ImageProcessing"

"MemoryUsage"

"OutputCharStr"

"SendFontCmd"

"TextOutAsBitmap"

"TTDownloadMethod"

"TTYGetInfo"

"WritePrinter"