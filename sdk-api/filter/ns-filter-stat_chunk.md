# STAT_CHUNK structure

## Description

Describes the characteristics of a chunk.

## Members

### `idChunk`

The chunk identifier. Chunk identifiers must be unique for the current instance of the [IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter) interface. Chunk identifiers must be in ascending order. The order in which chunks are numbered should correspond to the order in which they appear in the source document. Some search engines can take advantage of the proximity of chunks of various properties. If so, the order in which chunks with different properties are emitted will be important to the search engine.

### `breakType`

The type of break that separates the previous chunk from the current chunk. Values are from the [CHUNK_BREAKTYPE](https://learn.microsoft.com/windows/desktop/api/filter/ne-filter-chunk_breaktype) enumeration.

### `flags`

Indicates whether this chunk contains a text-type or a value-type property. Flag values are taken from the [CHUNKSTATE](https://learn.microsoft.com/windows/desktop/api/filter/ne-filter-chunkstate) enumeration. If the CHUNK_TEXT flag is set, [IFilter::GetText](https://learn.microsoft.com/windows/desktop/api/filter/nf-filter-ifilter-gettext) should be used to retrieve the contents of the chunk as a series of words. If the CHUNK_VALUE flag is set, [IFilter::GetValue](https://learn.microsoft.com/windows/desktop/api/filter/nf-filter-ifilter-getvalue) should be used to retrieve the value and treat it as a single property value. If the filter dictates that the same content be treated as both text and as a value, the chunk should be emitted twice in two different chunks, each with one flag set.

### `locale`

The language and sublanguage associated with a chunk of text. Chunk locale is used by document indexers to perform proper word breaking of text. If the chunk is neither text-type nor a value-type with data type VT_LPWSTR, VT_LPSTR or VT_BSTR, this field is ignored.

### `attribute`

The property to be applied to the chunk. See [FULLPROPSPEC](https://learn.microsoft.com/windows/desktop/api/filter/ns-filter-fullpropspec). If a filter requires that the same text have more than one property, it needs to emit the text once for each property in separate chunks.

### `idChunkSource`

The ID of the source of a chunk. The value of the **idChunkSource** member depends on the nature of the chunk:

* If the chunk is a text-type property, the value of the **idChunkSource** member must be the same as the value of the **idChunk** member.
* If the chunk is an internal value-type property derived from textual content, the value of the **idChunkSource** member is the chunk ID for the text-type chunk from which it is derived.
* If the filter attributes specify to return only internal value-type properties, there is no content chunk from which to derive the current internal value-type property. In this case, the value of the **idChunkSource** member must be set to zero, which is an invalid chunk.

### `cwcStartSource`

The offset from which the source text for a derived chunk starts in the source chunk.

### `cwcLenSource`

The length in characters of the source text from which the current chunk was derived. A zero value signifies character-by-character correspondence between the source text and the derived text. A nonzero value means that no such direct correspondence exists.

## Remarks

The final three members (**idChunkSource**, **cwcStartSource**, and **cwcLenSource**) are used to describe the source of a derived chunk; that is, one that can be mapped back to a section of text. For example, the heading of a chapter can be both a text-type property and an internal value-type property ? a heading. The value-type property "heading" would be a derived chunk. If the text of the current value-type chunk (from an internal value-type property) is derived from some text-type chunk, then it must be emitted more than once.

The following segment is an example of how this might happen in a book.

The small detective exclaimed, "C'est fini!"

**Confessions**

The room was silent for several minutes. After thinking very hard about it, the young woman asked, "But how did you know?"

This segment might be broken into chunks in the following way.

| ID | Text | BreakType | Flags | Locale | Attribute |
| --- | --- | --- | --- | --- | --- |
| 1 | The small dete | N/A | CHUNK_TEXT | ENGLISH_UK | CONTENT |
| 2 | ctive exclaimed, | CHUNK_NO_BREAK | N/A | N/A | N/A |
| 3 | "C'est fini!" | CHUNK_EOW | CHUNK_TEXT | FRENCH_BELGIAN | CONTENT |
| 4 | Confessions | CHUNK_EOC | CHUNK_TEXT | ENGLISH_UK | CHAPTER_NAMES |
| 5 | Confessions | CHUNK_EOP | CHUNK_TEXT | ENGLISH_UK | CONTENT |
| 6 | The room was silent for several minutes. | CHUNK_EOP | CHUNK_TEXT | ENGLISH_UK | CONTENT |
| 7 | After thinking very hard about it, the young woman asked, "But how did you know?" | CHUNK_EOS | CHUNK_TEXT | ENGLISH_UK | CONTENT |

Information provided by **idChunkSource**, **cwcStartSource**, and **cwcLenSource** is useful for a search engine that highlights hits. If the query is done for an internal value-type property, the search engine will highlight the original text from which the text of the internal value-type property has been derived. For instance, in a C++ code filter, the browser, when searching for MyFunction in internal value-type property "function definitions," will highlight the function header in the file.

## See also

[CHUNKSTATE](https://learn.microsoft.com/windows/desktop/api/filter/ne-filter-chunkstate)

[CHUNK_BREAKTYPE](https://learn.microsoft.com/windows/desktop/api/filter/ne-filter-chunk_breaktype)

[FULLPROPSPEC](https://learn.microsoft.com/windows/desktop/api/filter/ns-filter-fullpropspec)

[IFilter](https://learn.microsoft.com/windows/desktop/api/filter/nn-filter-ifilter)