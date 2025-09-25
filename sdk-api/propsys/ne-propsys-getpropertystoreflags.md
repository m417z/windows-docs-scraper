# GETPROPERTYSTOREFLAGS enumeration

## Description

Indicates flags that modify the property store object retrieved by methods that create a property store, such as [IShellItem2::GetPropertyStore](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem2-getpropertystore) or [IPropertyStoreFactory::GetPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-ipropertystorefactory-getpropertystore).

## Constants

### `GPS_DEFAULT:0`

Meaning to a calling process: Return a read-only property store that contains all properties. Slow items (offline files) are not opened.

Combination with other flags: Can be overridden by other flags.

### `GPS_HANDLERPROPERTIESONLY:0x1`

Meaning to a calling process: Include only properties directly from the property handler, which opens the file on the disk, network, or device.

Meaning to a file folder: Only include properties directly from the handler.

Meaning to other folders: When delegating to a file folder, pass this flag on to the file folder; do not do any multiplexing (MUX). When not delegating to a file folder, ignore this flag instead of returning a failure code.

Combination with other flags: Cannot be combined with GPS_TEMPORARY, GPS_FASTPROPERTIESONLY, or GPS_BESTEFFORT.

### `GPS_READWRITE:0x2`

Meaning to a calling process: Can write properties to the item. Note: The store may contain fewer properties than a read-only store.

Meaning to a file folder: ReadWrite.

Meaning to other folders: ReadWrite. Note: When using default MUX, return a single unmultiplexed store because the default MUX does not support ReadWrite.

Combination with other flags: Cannot be combined with GPS_TEMPORARY, GPS_FASTPROPERTIESONLY, GPS_BESTEFFORT, or GPS_DELAYCREATION. Implies GPS_HANDLERPROPERTIESONLY.

### `GPS_TEMPORARY:0x4`

Meaning to a calling process: Provides a writable store, with no initial properties, that exists for the lifetime of the Shell item instance; basically, a property bag attached to the item instance.

Meaning to a file folder: Not applicable. Handled by the Shell item.

Meaning to other folders: Not applicable. Handled by the Shell item.

Combination with other flags: Cannot be combined with any other flag. Implies GPS_READWRITE.

### `GPS_FASTPROPERTIESONLY:0x8`

Meaning to a calling process: Provides a store that does not involve reading from the disk or network. Note: Some values may be different, or missing, compared to a store without this flag.

Meaning to a file folder: Include the "innate" and "fallback" stores only. Do not load the handler.

Meaning to other folders: Include only properties that are available in memory or can be computed very quickly (no properties from disk, network, or peripheral IO devices). This is normally only data sources from the IDLIST. When delegating to other folders, pass this flag on to them.

Combination with other flags: Cannot be combined with GPS_TEMPORARY, GPS_READWRITE, GPS_HANDLERPROPERTIESONLY, or GPS_DELAYCREATION.

### `GPS_OPENSLOWITEM:0x10`

Meaning to a calling process: Open a slow item (offline file) if necessary.

Meaning to a file folder: Retrieve a file from offline storage, if necessary. Note: Without this flag, the handler is not created for offline files.

Meaning to other folders: Do not return any properties that are very slow.

Combination with other flags: Cannot be combined with GPS_TEMPORARY or GPS_FASTPROPERTIESONLY.

### `GPS_DELAYCREATION:0x20`

Meaning to a calling process: Delay memory-intensive operations, such as file access, until a property is requested that requires such access.

Meaning to a file folder: Do not create the handler until needed; for example, either [GetCount](https://learn.microsoft.com/windows/desktop/api/gdipluspath/nf-gdipluspath-graphicspathiterator-getcount)/[GetAt](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomcolorprofileresourcecollection-getat) or [GetValue](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nf-gdipluscolor-color-getvalue), where the innate store does not satisfy the request. Note: **GetValue** might fail due to file access problems.

Meaning to other folders: If the folder has memory-intensive properties, such as delegating to a file folder or network access, it can optimize performance by supporting [IDelayedPropertyStoreFactory](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-idelayedpropertystorefactory) and splitting up its properties into a fast and a slow store. It can then use delayed MUX to recombine them.

Combination with other flags: Cannot be combined with GPS_TEMPORARY or GPS_READWRITE.

### `GPS_BESTEFFORT:0x40`

Meaning to a calling process: Succeed at getting the store, even if some properties are not returned. Note: Some values may be different, or missing, compared to a store without this flag.

Meaning to a file folder: Succeed and return a store, even if the handler or innate store has an error during creation. Only fail if substores fail.

Meaning to other folders: Succeed on getting the store, even if some properties are not returned.

Combination with other flags: Cannot be combined with GPS_TEMPORARY, GPS_READWRITE, or GPS_HANDLERPROPERTIESONLY.

### `GPS_NO_OPLOCK:0x80`

**Windows 7 and later**. Callers should use this flag only if they are already holding an opportunistic lock (oplock) on the file because without an oplock, the bind operation cannot continue. By default, the Shell requests an oplock on a file before binding to the property handler. This flag disables the default behavior.

**Windows Server 2008 and Windows Vista:** This flag is not available.

### `GPS_PREFERQUERYPROPERTIES:0x100`

**Windows 8 and later**. Use this flag to retrieve only properties from the indexer for WDS results.

### `GPS_EXTRINSICPROPERTIES:0x200`

Include properties from the file's secondary stream.

### `GPS_EXTRINSICPROPERTIESONLY:0x400`

Include only properties from the file's secondary stream.

### `GPS_VOLATILEPROPERTIES:0x800`

### `GPS_VOLATILEPROPERTIESONLY:0x1000`

### `GPS_MASK_VALID:0x1fff`

Mask for valid [GETPROPERTYSTOREFLAGS](https://learn.microsoft.com/windows/desktop/api/propsys/ne-propsys-getpropertystoreflags) values.

## Remarks

If the Shell item is a file, the property store contains the following items.

* Properties from the file system that concern the file.
* Properties from the file itself that are provided by the file's property handler, unless the file is offline (see GPS_OPENSLOWITEM).

Non-file Shell items return a similar read-only store.

**Note** GPS_INCLUDEOFFLINEPROPERTIES has been superseded by GPS_OPENSLOWITEM.