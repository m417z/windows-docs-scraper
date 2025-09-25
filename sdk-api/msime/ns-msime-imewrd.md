# IMEWRD structure

## Description

Contains data about a word in the Word data of the Microsoft IME dictionary.

## Members

### `pwchReading`

The reading string.

### `pwchDisplay`

The display string.

### `ulPos`

POS (Part of Speech), defined as JPOS_***.

### `nPos1`

Not used.

### `nPos2`

Not used.

### `rgulAttrs`

Reserved.

### `cbComment`

Size of the comment, in bytes, of **pvComment**.

### `uct`

Type of comment. This must be one of the values of the [IMEUCT](https://learn.microsoft.com/windows/desktop/api/msime/ne-msime-imeuct) enumeration.

### `pvComment`

Comment string.

## See also

[IFEDictionary::ExistWord](https://learn.microsoft.com/windows/desktop/api/msime/nf-msime-ifedictionary-existword)

[IFEDictionary::GetWords](https://learn.microsoft.com/windows/desktop/api/msime/nf-msime-ifedictionary-getwords)

[IFEDictionary::NextWords](https://learn.microsoft.com/windows/desktop/api/msime/nf-msime-ifedictionary-nextwords)

[IFEDictionary::RegisterWord](https://learn.microsoft.com/windows/desktop/api/msime/nf-msime-ifedictionary-registerword)

[IMEUCT](https://learn.microsoft.com/windows/desktop/api/msime/ne-msime-imeuct)