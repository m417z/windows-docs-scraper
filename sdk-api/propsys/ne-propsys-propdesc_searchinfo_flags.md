# PROPDESC_SEARCHINFO_FLAGS enumeration

## Description

Determines whether and how a property is indexed by Windows Search.

## Constants

### `PDSIF_DEFAULT:0`

The property is not indexed.

### `PDSIF_ININVERTEDINDEX:0x1`

The property is in an inverted index to help speed searches.

### `PDSIF_ISCOLUMN:0x2`

The property is indexed by Windows Search.

### `PDSIF_ISCOLUMNSPARSE:0x4`

The property is indexed to save space for properties that are not present on all files.

### `PDSIF_ALWAYSINCLUDE:0x8`

**Windows 7 and later**. The property mnemonics are recognized by AQS even if the property is not a column (PDSIF_ISCOLUMN).

### `PDSIF_USEFORTYPEAHEAD:0x10`

Check this property for matches when looking for type ahead results.

## Remarks

For third parties, the PDSIF_ALWAYSINCLUDE flag can be referred to in user-specified query strings, even though its value may not be retrievable from the index in query results. The meaning of the PDSIF_ALWAYSINCLUDE flag to the indexer when a third party sets the flag through a custom schema definition is that it enables users to refer to this property in query strings even though its value is not stored in the index.

Property mnemonics refers to a shortened name for a property.