# OCTET_STRING structure

## Description

The **OCTET_STRING** structure contains a pointer to a string of byte data.

## Members

### `dwLength`

Type: **DWORD**

The length of the data.

### `lpValue`

Type: **[size_is(dwLength)]BYTE***

A pointer to the byte array containing the data.