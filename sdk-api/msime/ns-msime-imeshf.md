# IMESHF structure

## Description

The header of an opened user dictionary file. Used to get the user dictionary's properties, such as version, title, description, and copyright.

## Members

### `cbShf`

The size of this structure. You must set this value before using the structure.

### `verDic`

Dictionary version.

### `szTitle`

Dictionary title.

### `szDescription`

Dictionary description.

### `szCopyright`

Dictionary copyright information.

## See also

[IFEDictionary::Create](https://learn.microsoft.com/windows/desktop/api/msime/nf-msime-ifedictionary-create)

[IFEDictionary::GetHeader](https://learn.microsoft.com/windows/desktop/api/msime/nf-msime-ifedictionary-getheader)

[IFEDictionary::Open](https://learn.microsoft.com/windows/desktop/api/msime/nf-msime-ifedictionary-open)

[IFEDictionary::SetHeader](https://learn.microsoft.com/windows/desktop/api/msime/nf-msime-ifedictionary-setheader)