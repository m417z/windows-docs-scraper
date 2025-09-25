# DISCARDCACHE enumeration

## Description

Specifies what to do with caches that are to be discarded from memory if their dirty bit has been set.

## Constants

### `DISCARDCACHE_SAVEIFDIRTY:0`

The cache is to be saved to disk.

### `DISCARDCACHE_NOSAVE:1`

The cache can be discarded without saving it.

## See also

[IOleCache2::DiscardCache](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecache2-discardcache)