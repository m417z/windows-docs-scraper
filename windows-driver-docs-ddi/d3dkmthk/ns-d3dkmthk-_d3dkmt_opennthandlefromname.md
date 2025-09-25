# _D3DKMT_OPENNTHANDLEFROMNAME structure

## Description

Describes information that is required to open an NT handle to the process from a graphics adapter name.

## Members

### `dwDesiredAccess` [in]

Specifies read and write access for the resource.

### `pObjAttrib` [in]

A pointer to an [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that specifies attributes of the adapter, including its name.

### `hNtHandle` [out]

An NT handle to the process.