# DPA_GetPtr function

## Description

[**DPA_GetPtr** is available for use in the operating

systems specified in the Requirements section. It may be altered or unavailable in

subsequent versions.]

Gets an item from a dynamic pointer array (DPA).

## Parameters

### `hdpa`

Type: **HDPA**

A handle to a DPA.

### `i`

Type: **int**

The index of item to be retrieved.

## Return value

Returns the specified item or **NULL**, if the call fails.