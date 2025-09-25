# GdiComment function

## Description

The **GdiComment** function copies a comment from a buffer into a specified enhanced-format metafile.

## Parameters

### `hdc` [in]

A handle to an enhanced-metafile device context.

### `nSize` [in]

The length of the comment buffer, in bytes.

### `lpData` [in]

A pointer to the buffer that contains the comment.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

A comment can include any kind of private information, for example, the source of a picture and the date it was created. A comment should begin with an application signature, followed by the data.

Comments should not contain application-specific or position-specific data. Position-specific data specifies the location of a record, and it should not be included because one metafile may be embedded within another metafile.

A public comment is a comment that begins with the comment signature identifier GDICOMMENT_IDENTIFIER. The following public comments are defined.

|  |  |
| --- | --- |
| GDICOMMENT_WINDOWS_METAFILE | The GDICOMMENT_WINDOWS_METAFILE public comment contains a Windows-format metafile that is equivalent to an enhanced-format metafile. This comment is written only by the [SetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwinmetafilebits) function. The comment record, if given, follows the [ENHMETAHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-enhmetaheader) metafile record. The comment has the following form: |

``` syntax

DWORD ident;         // This contains GDICOMMENT_IDENTIFIER.
DWORD iComment;      // This contains GDICOMMENT_WINDOWS_METAFILE.
DWORD nVersion;      // This contains the version number of the
                     // Windows-format metafile.
DWORD nChecksum;     // This is the additive DWORD checksum for
                     // the enhanced metafile.  The checksum
                     // for the enhanced metafile data including
                     // this comment record must be zero.
                     // Otherwise, the enhanced metafile has been
                     //  modified and the Windows-format
                     // metafile is no longer valid.
DWORD fFlags;        // This must be zero.
DWORD cbWinMetaFile; // This is the size, in bytes. of the
                     // Windows-format metafile data that follows.

```

|  |  |
| --- | --- |
| GDICOMMENT_BEGINGROUP | The GDICOMMENT_BEGINGROUP public comment identifies the beginning of a group of drawing records. It identifies an object within an enhanced metafile. The comment has the following form: |

``` syntax

DWORD   ident;         // This contains GDICOMMENT_IDENTIFIER.
DWORD   iComment;      // This contains GDICOMMENT_BEGINGROUP.
RECTL   rclOutput;     // This is the bounding rectangle for the
                       // object in logical coordinates.
DWORD   nDescription;  // This is the number of characters in the
                       // optional Unicode description string that
                       // follows. This is zero if there is no
                       // description string.

```

|  |  |
| --- | --- |
| GDICOMMENT_ENDGROUP | The GDICOMMENT_ENDGROUP public comment identifies the end of a group of drawing records. The GDICOMMENT_BEGINGROUP comment and the GDICOMMENT_ENDGROUP comment must be included in a pair and may be nested. The comment has the following form: |

``` syntax

DWORD   ident;       // This contains GDICOMMENT_IDENTIFIER.
DWORD   iComment;    // This contains GDICOMMENT_ENDGROUP.

```

## See also

[CreateEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createenhmetafilea)

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[SetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwinmetafilebits)