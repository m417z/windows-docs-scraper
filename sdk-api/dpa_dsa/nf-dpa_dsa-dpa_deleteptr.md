# DPA_DeletePtr function

## Description

[**DPA_DeletePtr** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Removes an item from a dynamic pointer array (DPA). The DPA shrinks if necessary to accommodate the removed item.

## Parameters

### `hdpa`

Type: **HDPA**

A handle to a DPA.

### `i`

Type: **int**

An index of item to be removed from DPA.

## Return value

Returns the removed item or **NULL**, if the call fails.