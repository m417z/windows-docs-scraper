# DWRITE_CLUSTER_METRICS structure

## Description

Contains information about a glyph cluster.

## Members

### `width`

Type: **FLOAT**

The total advance width of all glyphs in the cluster.

### `length`

Type: **UINT16**

The number of text positions in the cluster.

### `canWrapLineAfter`

Type: **UINT16**

Indicates whether a line can be broken right after the cluster.

### `isWhitespace`

Type: **UINT16**

Indicates whether the cluster corresponds to a whitespace character.

### `isNewline`

Type: **UINT16**

Indicates whether the cluster corresponds to a newline character.

### `isSoftHyphen`

Type: **UINT16**

Indicates whether the cluster corresponds to a soft hyphen character.

### `isRightToLeft`

Type: **UINT16**

Indicates whether the cluster is read from right to left.

### `padding`

Type: **UINT16**

Reserved for future use.