# InkClipboardFormats enumeration

## Description

Specifies the format of ink that is stored on the Clipboard.

## Constants

### `ICF_None:0`

 A flag that can be used to verify whether any formats are present by checking against it.

### `ICF_InkSerializedFormat:0x1`

Ink is encoded in ink serialized format (ISF). This is the most compact persistent representation of ink. Although it often contains only ink data, ISF is extensible. Applications can set custom attributes (identified by a globally unique identifier (GUID)) on an [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object, stroke, or point. This allows an application to store any kind of data or metadata that it requires as an attribute in an ISF stream.

### `ICF_SketchInk:0x2`

Ink is not expected to form words, but rather is interpreted as a picture. This is also useful for representing multiple words.

### `ICF_TextInk:0x6`

Ink is expected to form words. It enables the recognizer to convert the ink to text. The recognized text is either the recognition alternate with the greatest confidence rating or another alternate chosen from a list. This is useful for representing a single word.

### `ICF_EnhancedMetafile:0x8`

The enhanced metafile to play to create the background. The metafile must remain valid for as long as it is used to render the ink background.

### `ICF_Metafile:0x20`

Ink is stored as a metafile or a list of commands that can be played back to draw a graphic.

### `ICF_Bitmap:0x40`

The bitmap to use as the background. The bitmap device context must remain valid for as long as it is used to render the ink background.

### `ICF_PasteMask:0x7`

The formats that can be used for pasting, including [tInk](https://learn.microsoft.com/windows/desktop/tablet/sink-and-tink-objects), sInk, and ISF.

### `ICF_CopyMask:0x7f`

The formats that are copied to the Clipboard through ink.

This is the default value.

### `ICF_Default`

Ink is stored as a CopyMask.

## Remarks

In C++, explicit casting is required when trying to set more than one flag at a time. A compilation error occurs if explicit casting is not used.

## See also

[ClipboardCopy Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-clipboardcopy)

[ClipboardCopyWithRectangle Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-clipboardcopywithrectangle)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)

[sInk and tInk Objects](https://learn.microsoft.com/windows/desktop/tablet/sink-and-tink-objects)