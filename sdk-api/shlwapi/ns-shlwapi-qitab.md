# QITAB structure

## Description

Used by the [QISearch](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-qisearch) function to describe a single interface.

## Members

### `piid`

Type: **const IID***

A pointer to the IID of the interface represented by this structure.

### `dwOffset`

Type: **int**

The offset, in bytes, from the base of the object to the start of the interface.

## Remarks

**Note** Prior to Windows Vista, **QITAB** was not declared in a public header file. To use it in those cases, you must use define it yourself as it is given here. Under Windows Vista, **QITAB** is included in Shlwapi.h and this is not necessary.

To mark the end of a **QITAB** table, set the **piid** member to **NULL** and the **dwOffset** member to 0. See the [QISearch](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-qisearch) function for an example of how to use this structure.