# FILE_ATTRIBUTES_ARRAY structure

## Description

Contains the clipboard format definition for CFSTR_FILE_ATTRIBUTES_ARRAY.

## Members

### `cItems`

Type: **UINT**

The number of items in the **rgdwFileAttributes** array.

### `dwSumFileAttributes`

Type: **DWORD**

All of the attributes combined using OR.

### `dwProductFileAttributes`

Type: **DWORD**

All of the attributes combined using AND.

### `rgdwFileAttributes`

Type: **DWORD[1]**

An array of file attributes.