# IShellItemResources::GetAttributes

## Description

Gets resource attributes.

## Parameters

### `pdwAttributes` [out]

Type: **DWORD***

A pointer to resource attributes. The following are attribute values.

#### FILE_ATTRIBUTE_READONLY

Value is 0x00000001.

#### FILE_ATTRIBUTE_HIDDEN

Value is 0x00000002.

#### FILE_ATTRIBUTE_SYSTEM

Value is 0x00000004.

#### FILE_ATTRIBUTE_DIRECTORY

Value is 0x00000010.

#### FILE_ATTRIBUTE_ARCHIVE

Value is 0x00000020.

#### FILE_ATTRIBUTE_ENCRYPTED

Value is 0x00000040.

#### FILE_ATTRIBUTE_NORMAL

Value is 0x00000080.

#### FILE_ATTRIBUTE_TEMPORARY

Value is 0x00000100.

#### FILE_ATTRIBUTE_SPARSE_FILE

Value is 0x00000200.

#### FILE_ATTRIBUTE_REPARSE_POINT

Value is 0x00000400.

#### FILE_ATTRIBUTE_COMPRESSED

Value is 0x00000800.

#### FILE_ATTRIBUTE_OFFLINE

Value is 0x00001000.

#### FILE_ATTRIBUTE_CONTENT_INDEXED

Value is 0x00002000.

#### FILE_ATTRIBUTE_VALID_FLAGS

Value is 0x00001ff7.

#### FILE_ATTRIBUTE_VALID_SET_FLAGS

Value is 0x000011a7.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.