# DBVALUEKINDENUM enumeration

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

The **DBVALUEKINDENUM** enumerated type is used to indicate the type of the union member inside a [DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree) structure. For programming convenience, the values in this enumeration correspond exactly to the OLE Automation **VARENUM** and OLE DB **DBTYPE** enumerations. The comments associated with each enumeration value represent the type and branch of the union type inside the command structure containing the value. nodes that do not assign a value to the union member should assign a DBVALUEKIND_EMPTY to the **wKind** member of the **DBCOMMANDTREE** structure.

## Constants

### `DBVALUEKIND_BYGUID:256`

### `DBVALUEKIND_COLDESC`

### `DBVALUEKIND_ID`

### `DBVALUEKIND_CONTENT`

### `DBVALUEKIND_CONTENTVECTOR`

### `DBVALUEKIND_GROUPINFO`

### `DBVALUEKIND_PARAMETER`

### `DBVALUEKIND_PROPERTY`

### `DBVALUEKIND_SETFUNC`

### `DBVALUEKIND_SORTINFO`

### `DBVALUEKIND_TEXT`

### `DBVALUEKIND_COMMAND`

### `DBVALUEKIND_MONIKER`

### `DBVALUEKIND_ROWSET`

### `DBVALUEKIND_LIKE`

### `DBVALUEKIND_CONTENTPROXIMITY`

### `DBVALUEKIND_CONTENTSCOPE`

### `DBVALUEKIND_CONTENTTABLE`

### `DBVALUEKIND_IDISPATCH:9`

### `DBVALUEKIND_IUNKNOWN:13`

### `DBVALUEKIND_EMPTY:0`

### `DBVALUEKIND_NULL:1`

### `DBVALUEKIND_I2:2`

### `DBVALUEKIND_I4:3`

### `DBVALUEKIND_R4:4`

### `DBVALUEKIND_R8:5`

### `DBVALUEKIND_CY:6`

### `DBVALUEKIND_DATE:7`

### `DBVALUEKIND_BSTR:8`

### `DBVALUEKIND_ERROR:10`

### `DBVALUEKIND_BOOL:11`

### `DBVALUEKIND_VARIANT:12`

### `DBVALUEKIND_VECTOR:0x1000`

### `DBVALUEKIND_ARRAY:0x2000`

### `DBVALUEKIND_BYREF:0x4000`

### `DBVALUEKIND_I1:16`

### `DBVALUEKIND_UI1:17`

### `DBVALUEKIND_UI2:18`

### `DBVALUEKIND_UI4`

### `DBVALUEKIND_I8`

### `DBVALUEKIND_UI8`

### `DBVALUEKIND_GUID:72`

### `DBVALUEKIND_BYTES:128`

### `DBVALUEKIND_STR:129`

### `DBVALUEKIND_WSTR:130`

### `DBVALUEKIND_NUMERIC:131`

### `DBVALUEKIND_DBDATE:133`

### `DBVALUEKIND_DBTIME:134`

### `DBVALUEKIND_DBTIMESTAMP:135`

### `DBVALUEKIND_PROBABILISTIC:136`

### `DBVALUEKIND_RELEVANTDOCUMENT:137`

##### - See below.