# PSC_STATE enumeration

## Description

Specifies the state of a property. They are set manually by the code that is hosting the in-memory property store cache.

## Constants

### `PSC_NORMAL:0`

The property has not been altered.

### `PSC_NOTINSOURCE:1`

The requested property does not exist for the file or stream on which the property handler was initialized.

### `PSC_DIRTY:2`

The property has been altered but has not yet been committed to the file or stream.

### `PSC_READONLY:3`