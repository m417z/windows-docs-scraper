# FILTERREGION structure

## Description

Describes the position and extent of a specified portion of text within an object.

## Members

### `idChunk`

The chunk identifier.

### `cwcStart`

The beginning of the region, specified as an offset from the beginning of the chunk.

### `cwcExtent`

The extent of the region, specified as the number of Unicode characters.

## Remarks

The **cwcExtent** member might specify a number of characters (starting from a position the **cwcStart** member specifies) that extends beyond the end of the chunk. In that case, the region should be continued into the next chunk, which should have the same attribute as the current region.

## See also

[IFilter::BindRegion](https://learn.microsoft.com/windows/desktop/api/filter/nf-filter-ifilter-bindregion)