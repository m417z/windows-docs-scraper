# METARECORD structure

## Description

The **METARECORD** structure contains a Windows-format metafile record.

## Members

### `rdSize`

The size, in words, of the record.

### `rdFunction`

The function number.

### `rdParm`

An array of words containing the function parameters, in reverse of the order they are passed to the function.

## See also

[METAHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-metaheader)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)