# WTS_PROPERTY_VALUE structure

## Description

Contains information about a property value to retrieve from the protocol. The **WTS_PROPERTY_VALUE** structure is used by the [QueryProperty](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwtsprotocolconnection-queryproperty) method.

## Members

### `Type`

An integer that specifies which member of the union contains the property value information. This can be one of the following values.

#### VALUE_TYPE_ULONG

The value is contained in the **ulVal** member.

#### VALUE_TYPE_STRING

The value is contained in the **strVal** member.

#### VALUE_TYPE_BINARY

The value is contained in the **bVal** member.

#### VALUE_TYPE_GUID

The value is contained in the **guidVal** member.

### `u`

A union that contains the property value.

### `u.ulVal`

The value is contained in an integer.

### `u.strVal`

The value is contained in a string.

### `u.strVal.size`

An integer that contains the size of the string pointed to by the **pstrVal** member.

### `u.strVal.pstrVal`

A pointer to a string that contains the property value.

### `u.bVal`

The value is contained in a byte array.

### `u.bVal.size`

An integer that contains the size of the byte array pointed to by the **pbVal** member.

### `u.bVal.pbVal`

A pointer to a byte array that contains the property value.

### `u.guidVal`

A GUID that contains the property value.