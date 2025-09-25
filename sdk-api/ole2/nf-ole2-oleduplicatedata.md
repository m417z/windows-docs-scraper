# OleDuplicateData function

## Description

Duplicates the data found in the specified handle and returns a handle to the duplicated data. The source data is in a clipboard format. Use this function to help implement some of the data transfer interfaces such as [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject).

## Parameters

### `hSrc` [in]

 Handle of the source data.

### `cfFormat` [in]

Clipboard format of the source data.

### `uiFlags` [in]

Flags to be used to allocate global memory for the copied data. These flags are passed to GlobalAlloc. If the value of *uiFlags* is **NULL**, GMEM_MOVEABLE is used as a default flag.

## Return value

On success the HANDLE to the source data is returned; on failure a **NULL** value is returned.

## Remarks

The CF_METAFILEPICT, CF_PALETTE, or CF_BITMAP formats receive special handling. They are GDI handles and a new GDI object must be created instead of just copying the bytes. All other formats are duplicated byte-wise.