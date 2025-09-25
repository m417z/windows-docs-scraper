# EVT_VARIANT_TYPE enumeration

## Description

Defines the possible data types of a variant data item.

## Constants

### `EvtVarTypeNull:0`

Null content that implies that the element that contains the content does not exist.

### `EvtVarTypeString:1`

A null-terminated Unicode string.

### `EvtVarTypeAnsiString:2`

A null-terminated ANSI string.

### `EvtVarTypeSByte:3`

A signed 8-bit integer value.

### `EvtVarTypeByte:4`

An unsigned 8-bit integer value.

### `EvtVarTypeInt16:5`

An signed 16-bit integer value.

### `EvtVarTypeUInt16:6`

An unsigned 16-bit integer value.

### `EvtVarTypeInt32:7`

A signed 32-bit integer value.

### `EvtVarTypeUInt32:8`

An unsigned 32-bit integer value.

### `EvtVarTypeInt64:9`

A signed 64-bit integer value.

### `EvtVarTypeUInt64:10`

An unsigned 64-bit integer value.

### `EvtVarTypeSingle:11`

A single-precision real value.

### `EvtVarTypeDouble:12`

A double-precision real value.

### `EvtVarTypeBoolean:13`

A Boolean value.

### `EvtVarTypeBinary:14`

A hexadecimal binary value.

### `EvtVarTypeGuid:15`

A GUID value.

### `EvtVarTypeSizeT:16`

An unsigned 32-bit or 64-bit integer value that contains a pointer address.

### `EvtVarTypeFileTime:17`

A FILETIME value.

### `EvtVarTypeSysTime:18`

 A SYSTEMTIME value.

### `EvtVarTypeSid:19`

A security identifier ([SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)) structure

### `EvtVarTypeHexInt32:20`

A 32-bit hexadecimal number.

### `EvtVarTypeHexInt64:21`

A 64-bit hexadecimal number.

### `EvtVarTypeEvtHandle:32`

An EVT_HANDLE value.

### `EvtVarTypeEvtXml:35`

A null-terminated Unicode string that contains XML.

## See also

[EVT_VARIANT](https://learn.microsoft.com/windows/desktop/api/winevt/ns-winevt-evt_variant)