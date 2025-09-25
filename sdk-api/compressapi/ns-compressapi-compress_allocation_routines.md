# COMPRESS_ALLOCATION_ROUTINES structure

## Description

A structure containing optional memory allocation and deallocation routines.

## Members

### `Allocate`

Callback that allocates memory.

### `Free`

Callback that deallocates memory.

### `UserContext`

A pointer to context information for the allocation or deallocation routine defined by the user.