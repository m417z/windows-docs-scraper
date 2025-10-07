# ODJ_BLOB structure

Specifies a structure containing either a serialized ODJ_WIN7BLOB structure or a serialized OP_PACKAGE structure.

## Members

### ulODJFormat

Specifies the logical version of the structure and must be set to one of the following values:

|Value|Meaning|
| --- | --- |
|ODJ_WIN7_FORMAT (0x00000001)|The bytes contained in pBlob must contain a serialized ODJ_WIN7_BLOB structure.|
|ODJ_WIN8_FORMAT (0x00000002)|The bytes contained in pBlob must contain a serialized OP_PACKAGE structure.|

### cbBlob

This must be set to the number of bytes in the pBlob array.

### pBlob

Points to a byte buffer containing a serialized structure as specified by ulODJFormat above.

## See also

[**Offline Domain Join IDL Definitions**](https://learn.microsoft.com/windows/win32/netmgmt/odj-idl)