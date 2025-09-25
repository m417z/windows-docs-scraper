# CHUNK_BREAKTYPE enumeration

## Description

Describes the type of break that separates the current chunk from the previous chunk.

## Constants

### `CHUNK_NO_BREAK:0`

No break is placed between the current chunk and the previous chunk. The chunks are glued together.

### `CHUNK_EOW:1`

A word break is placed between this chunk and the previous chunk that had the same attribute. Use of CHUNK_EOW should be minimized because the choice of word breaks is language-dependent, so determining word breaks is best left to the search engine.

### `CHUNK_EOS:2`

A sentence break is placed between this chunk and the previous chunk that had the same attribute.

### `CHUNK_EOP:3`

A paragraph break is placed between this chunk and the previous chunk that had the same attribute.

### `CHUNK_EOC:4`

A chapter break is placed between this chunk and the previous chunk that had the same attribute.

## Remarks

A change in attributes implies a word, sentence, paragraph, or chapter break.

## See also

[IFilter::GetChunk](https://learn.microsoft.com/windows/desktop/api/filter/nf-filter-ifilter-getchunk)

[STAT_CHUNK](https://learn.microsoft.com/windows/desktop/api/filter/ns-filter-stat_chunk)