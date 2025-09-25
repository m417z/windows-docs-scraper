# CreateTypeLib2 function

## Description

Creates a type library in the current file format.

The file and in-memory format for the current version of Automation makes use of memory-mapped files. The [CreateTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-createtypelib) function is still available for creating a type library in the older format.

## Parameters

### `syskind`

The target operating system for which to create a type library.

### `szFile`

The name of the file to create.

### `ppctlib`

The [ICreateTypeLib2](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-icreatetypelib2) interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.