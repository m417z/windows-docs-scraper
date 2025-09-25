# DeleteEnhMetaFile function

## Description

The **DeleteEnhMetaFile** function deletes an enhanced-format metafile or an enhanced-format metafile handle.

## Parameters

### `hmf` [in]

A handle to an enhanced metafile.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

If the *hemf* parameter identifies an enhanced metafile stored in memory, the **DeleteEnhMetaFile** function deletes the metafile. If *hemf* identifies a metafile stored on a disk, the function deletes the metafile handle but does not destroy the actual metafile. An application can retrieve the file by calling the [GetEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getenhmetafilea) function.

#### Examples

For an example, see [Opening an Enhanced Metafile and Displaying Its Contents](https://learn.microsoft.com/windows/desktop/gdi/opening-an-enhanced-metafile-and-displaying-its-contents).

## See also

[CopyEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-copyenhmetafilea)

[CreateEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createenhmetafilea)

[GetEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getenhmetafilea)

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)