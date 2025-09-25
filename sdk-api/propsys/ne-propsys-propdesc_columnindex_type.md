# PROPDESC_COLUMNINDEX_TYPE enumeration

## Description

Indicates whether or how a property can be indexed.

## Constants

### `PDCIT_NONE:0`

Never generate any index on this property.

### `PDCIT_ONDISK:1`

Always build the individual value index, but build the vector index only on demand.

### `PDCIT_INMEMORY:2`

Obsolete.

### `PDCIT_ONDEMAND:3`

**Windows 7 and later**. Build the individual value index or vector index the first time the index is used in a query to filter, group, or sort. After being generated the first time, the index is maintained for future queries. Most property indexes should be built on demand, because building and maintaining indexes is expensive and they should be built only if they will be used.

### `PDCIT_ONDISKALL:4`

**Windows 7 and later**. Always build both the individual value index and the vector index.

### `PDCIT_ONDISKVECTOR:5`

**Windows 7 and later**. Always build the vector index, but build the value index only on demand.

## Remarks

Windows Search builds indexes for the values found in the property store to efficiently support filtering, sorting, and grouping over indexed properties. There are two kinds of indexes: an individual value index that indexes an item by single values, and a vector index that indexes all the vector values of a row as a single index entry.