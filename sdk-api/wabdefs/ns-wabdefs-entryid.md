# ENTRYID structure

## Description

Do not use. Contains the entry identifier information for a MAPI object.

## Members

### `abFlags`

Type: **BYTE[4]**

Array of variables of type **BYTE** that specifies the bitmask of flags that provide information describing the object.

### `ab`

Type: **BYTE[MAPI_DIM]**

Array of variables of type **BYTE** that specifies the binary data used by service providers. Client applications cannot use this array.