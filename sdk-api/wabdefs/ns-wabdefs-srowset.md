# SRowSet structure

## Description

Do not use. Contains an array of [SRow](https://learn.microsoft.com/windows/desktop/api/wabdefs/ns-wabdefs-srow) structures. Each **SRow** structure describes a row from a table.

## Members

### `cRows`

Type: **ULONG**

Variable of type **ULONG** that specifies the number of [SRow](https://learn.microsoft.com/windows/desktop/api/wabdefs/ns-wabdefs-srow) structures in the **aRow** member.

### `aRow`

Type: **[SRow](https://learn.microsoft.com/windows/desktop/api/wabdefs/ns-wabdefs-srow)[MAPI_DIM]**

Array of variables of type [SRow](https://learn.microsoft.com/windows/desktop/api/wabdefs/ns-wabdefs-srow) that specifies the structures that represent the rows in the table.