# OLECLOSE enumeration

## Description

Indicates whether an object should be saved before closing.

## Constants

### `OLECLOSE_SAVEIFDIRTY:0`

The object should be saved if it is dirty.

### `OLECLOSE_NOSAVE:1`

The object should not be saved, even if it is dirty. This flag is typically used when an object is being deleted.

### `OLECLOSE_PROMPTSAVE:2`

If the object is dirty, the [IOleObject::Close](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-close) implementation should display a dialog box to let the end user determine whether to save the object. However, if the object is in the running state but its user interface is invisible, the end user should not be prompted, and the close should be handled as if OLECLOSE_SAVEIFDIRTY had been specified.

## See also

[IOleObject::Close](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-close)