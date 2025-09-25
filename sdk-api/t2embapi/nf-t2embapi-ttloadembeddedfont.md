# TTLoadEmbeddedFont function

## Description

Reads an embedded font from the document stream and installs it. Also allows a client to further restrict embedding privileges of the font.

## Parameters

### `phFontReference` [out]

A pointer to a handle that identifies the installed embedded font. This handle references an internal structure, not an Hfont.

### `ulFlags` [in]

A flag specifying loading and installation options. Currently, this flag can be set to zero or the following value:

| Value | Meaning |
| --- | --- |
| **TTLOAD_PRIVATE** | Load the font so that it is not enumerated to the user. If the font is not installable, it will remain private. |

### `pulPrivStatus` [out]

A pointer to flag indicating embedding privileges of the font. This flag is written upon completion of this function and can have one of the following values. This function returns the least restrictive license granted.

| Value | Meaning |
| --- | --- |
| **EMBED_PREVIEWPRINT** | Preview and Print Embedding. The font may be embedded within documents, but must only be installed temporarily on the remote system. A document containing this type of font can only be opened as read-only. The application must not allow the user to edit the document. The document can only be viewed and/or printed. |
| **EMBED_EDITABLE** | Editable Embedding. The font may be embedded within documents, but must only be installed temporarily on the remote system. A document containing this type of font may be opened "read/write," with editing permitted. |
| **EMBED_INSTALLABLE** | Installable Embedding. The font may be embedded and permanently installed on the remote system. The user of the remote system acquires the identical rights, obligations, and licenses for that font as the original purchaser of the font, and is subject to the same end-user license agreement, copyright, design patent, and/or trademark as was the original purchaser. |
| **EMBED_NOEMBEDDING** | Restricted License Embedding. The font must not be modified, embedded, or exchanged in any manner without first obtaining permission of the legal owner. |

### `ulPrivs` [in]

A flag indicating a further restriction of embedding privileges, imposed by the client loading the font. This flag must have one of the following values.

| Value | Meaning |
| --- | --- |
| **LICENSE_PREVIEWPRINT** | Preview and Print Embedding. |
| **LICENSE_EDITABLE** | Editable Embedding. |
| **LICENSE_INSTALLABLE** | Installable Embedding. |
| **LICENSE_NOEMBEDDING** | Restricted License Embedding. |
| **LICENSE_DEFAULT** | Use default embedding level. |

### `pulStatus` [out]

A pointer to a bitfield containing status information about the **TTLoadEmbeddedFont** request. This field is filled upon completion of this function and can have zero or more of the following values.

| Value | Meaning |
| --- | --- |
| **TTLOAD_FONT_SUBSETTED** | The font loaded is a subset of the original font. |
| **TTLOAD_FONT_IN_SYSSTARTUP** | The font loaded was labeled as installable and has been added to the registry so it will be available upon startup. |

### `lpfnReadFromStream` [in]

A pointer to the client-defined callback function that reads the font structure from the document stream.

### `lpvReadStream` [in]

A pointer to the stream (font structure).

### `szWinFamilyName` [in, optional]

A pointer to the new 16-bit-character Unicode Microsoft Windows family name of the font. Set to **NULL** to use existing name. When changing the name of a font upon loading, you must supply both this parameter and the *szMacFamilyName* parameter.

### `szMacFamilyName` [in, optional]

A pointer to the new 8-bit-character Macintosh family name of the font. Set to **NULL** to use existing name. When changing the name of a font upon loading, you must supply both this parameter and the *szWinFamilyName* parameter.

### `pTTLoadInfo` [in, optional]

A pointer to a [TTLOADINFO](https://learn.microsoft.com/windows/desktop/api/t2embapi/ns-t2embapi-ttloadinfo) structure containing the URL from which the embedded font object has been obtained. If this value does not match one of those contained in the [TTEMBEDINFO](https://learn.microsoft.com/windows/desktop/api/t2embapi/ns-t2embapi-ttembedinfo) structure, the font will not load successfully.

## Return value

If successful, returns E_NONE.

If font loading is successful, a font indicated by *phFontReference* is created from the font structure with the names referenced in *szWinFamilyName* and *szMacFamilyName*. *pulPrivStatus* is set indicating the embedding privileges of the font; and *pulStatus* may be set indicating status information about the font loading operation.

Otherwise, returns an error code described in [Embedding Function Error Messages](https://learn.microsoft.com/windows/desktop/gdi/font-embedding-function-error-messages).

## Remarks

To assist a client in determining whether an embedded font is already installed on the system, the font loading function will return an error message indicating a font with the same name exists on the system (E_FONTNAMEALREADYEXISTS), and if that font has the same checksum as the embedded font (E_FONTALREADYEXISTS). The client then has two options:

1. Assume that the installed font is really the same as the embedded font and covers the same subsets.
2. Force the embedded font to be installed with a different name to avoid incompatibilities with the font already on the system.

To change the name of an embedded font prior to installing, the client must supply both the 8-bit-character and 16-bit-character name strings as parameters. The font name will be changed in the name table of the newly installed font. The new name is only available to the client and will not be enumerated to the user.

To use the existing name of the embedded font, the name string parameters need to be set to **NULL**.

## See also

[TTDeleteEmbeddedFont](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttdeleteembeddedfont)

[TTEMBEDINFO](https://learn.microsoft.com/windows/desktop/api/t2embapi/ns-t2embapi-ttembedinfo)

[TTGetEmbeddingType](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttgetembeddingtype)

[TTGetNewFontName](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttgetnewfontname)

[TTLOADINFO](https://learn.microsoft.com/windows/desktop/api/t2embapi/ns-t2embapi-ttloadinfo)