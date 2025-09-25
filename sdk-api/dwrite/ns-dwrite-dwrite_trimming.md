## Description

Specifies the trimming option for text overflowing the layout box.

## Members

### `granularity`

Type: **[DWRITE_TRIMMING_GRANULARITY](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_trimming_granularity)**

A value that specifies the text granularity used to trim text overflowing the layout box.

### `delimiter`

Type: **UINT32**

A character code used as the delimiter that signals the beginning of the portion of text to be preserved.

Text starting from the Nth occurrence of the delimiter (where N equals *delimiterCount*) counting backwards from the end of the text block will be preserved. For example, if the text is the path `C:\w\x\y\z\file.txt`, and *delimiter* is equal to '\\', and *delimiterCount* is equal to 1, then the `file.txt` portion of the path would be preserved. Specifying a delimiterCount of 2 would preserve `z\file.txt`.

### `delimiterCount`

Type: **UINT32**

The delimiter count, counting from the end of the text, to preserve text from.