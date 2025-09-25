# _PDO_CAPS enumeration

## Description

This enumeration describes the capabilities of Physical Device Objects (PDOs).

## Constants

### `PDO_CAPABILITY_UNDEFINED`

Command data block size granularity is undefined.

### `PDO_CAPABILITY_INC512_SET`

Command data block size granularity of 512 bytes is supported.

### `PDO_CAPABILITY_INC512_CLEAR`

Command data block size granularity of 1 byte is supported.

## Remarks

A silo must support either PDO_CAPABILITY_INC512_SET or PDO_CAPABILITY_INC512_CLEAR. It may also indicate that both values are supported by returning a logical OR of these two bits.