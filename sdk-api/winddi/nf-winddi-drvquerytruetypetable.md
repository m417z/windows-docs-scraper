# DrvQueryTrueTypeTable function

## Description

The **DrvQueryTrueTypeTable** function accesses specific tables in a TrueType font-description file.

## Parameters

### `iFile`

Pointer to a driver-defined value that identifies the driver-provided TrueType font file. This pointer is obtained from [DrvLoadFontFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvloadfontfile).

### `ulFont`

Specifies the one-based index of the driver font.

### `ulTag`

Specifies the table to access. If *ulTag* is zero, the driver should return access to the entire file.

### `dpStart`

Specifies the offset from the beginning of the tables from which to begin access. If *ulTag* is zero, *dpStart* is the offset from the beginning of the file.

### `cjBuf`

Specifies the size in bytes of the buffer to which *pjBuf* points, or zero.

### `pjBuf`

If not **NULL**, points to the buffer into which the driver should copy the table or font data.

### `ppjTable`

If not **NULL**, points to the location in which the driver should return the address of the table or font data.

### `pcjTable`

If not **NULL**, points to the location in which the driver should return the length in bytes of the table or font data to which **ppjTable* points.

## Return value

**DrvQueryTrueTypeTable** returns one of the following values:

* If *pjBuf* is **NULL**, the number of bytes required for the buffer to hold the entire table (this would be the same as the value returned in *pcjTable*).
* If *pjBuf* is not **NULL**, the number of bytes copied.
* If an error occurs, FD_ERROR.

## Remarks

**DrvQueryTrueTypeTable** must be implemented in TrueType font drivers.

There are two ways in which **DrvQueryTrueTypeTable** can be requested to return table or font data:

1. When neither *cjBuf* nor *pjBuf* are **NULL**, the driver should copy the contents of the requested table into the buffer to which *pjBuf* points. In this situation, *ppjTable* and *pcjTable* will be **NULL** and should be ignored by the driver.
2. When neither *ppjTable* nor *pcjTable* are **NULL**, the driver should place a pointer to the table in **ppjTable*, and the length, in bytes, of the table in **pciTable*. In this situation, *cjBuf* and *pjBuf* will be **NULL** and should be ignored by the driver.

## See also

[DrvLoadFontFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvloadfontfile)