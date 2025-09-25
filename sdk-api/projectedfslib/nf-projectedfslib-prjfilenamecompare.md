# PrjFileNameCompare function

## Description

Compares two file names and returns a value that indicates their relative collation order.

## Parameters

### `fileName1` [in]

A null-terminated Unicode string specifying the first name to compare.

### `fileName2` [in]

A null-terminated Unicode string specifying the second name to compare.

## Return value

* <0 indicates fileName1 is before fileName2 in collation order
* 0 indicates fileName1 is equal to fileName2
* >0 indicates fileName1 is after fileName2 in collation order

## Remarks

The provider may use this routine to determine how to sort file names in the same order that the file system does.