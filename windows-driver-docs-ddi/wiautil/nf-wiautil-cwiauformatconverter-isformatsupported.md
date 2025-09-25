# CWiauFormatConverter::IsFormatSupported

## Description

The **CWiauFormatConverter::IsFormatSupported** method verifies that GDI+ supports the image format that is to be converted.

## Parameters

### `pguidFormat`

Points to the GUID of the format. The format GUIDs are defined in *gdiplusimaging.h*.

## Return value

The method returns **TRUE** if the format indicated by the format GUID is supported, and **FALSE** if it is not supported.

## See also

[CWiauFormatConverter](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540363(v=vs.85))

[CWiauFormatConverter::ConvertToBmp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-cwiauformatconverter-converttobmp)