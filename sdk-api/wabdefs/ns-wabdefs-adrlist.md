# ADRLIST structure

## Description

Do not use. Describes zero or more properties belonging to one or more recipients.

## Members

### `cEntries`

Type: **ULONG**

Variable of type **ULONG** that specifies the entry count in the array specified by the **aEntries** member.

### `aEntries`

Type: **[ADRENTRY](https://learn.microsoft.com/windows/desktop/api/wabdefs/ns-wabdefs-adrentry)[MAPI_DIM]**

Variable of type [ADRENTRY](https://learn.microsoft.com/windows/desktop/api/wabdefs/ns-wabdefs-adrentry) that specifies the array of **ADRENTRY** structures, one structure for each recipient.