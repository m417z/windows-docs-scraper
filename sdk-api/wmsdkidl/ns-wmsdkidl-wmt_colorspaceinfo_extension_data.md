# WMT_COLORSPACEINFO_EXTENSION_DATA structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMT_COLORSPACEINFO_EXTENSION_DATA** structure contains information about the color format of output video samples. It is used as the value for the WM_SampleExtensionGUID_ColorSpaceInfo data unit extension.

## Members

### `ucColorPrimaries`

Specifies the chromaticity coordinates of the color primaries.

### `ucColorTransferChar`

Specifies the opto-electronic transfer characteristics of the source picture.

### `ucColorMatrixCoef`

Specifies the matrix coefficients used to derive Y, Cb, and Cr signals from the color primaries.

## See also

[Sample Extension Types](https://learn.microsoft.com/windows/desktop/wmformat/sample-extension-types)

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)