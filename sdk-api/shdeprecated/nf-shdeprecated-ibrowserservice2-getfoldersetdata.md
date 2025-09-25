# IBrowserService2::GetFolderSetData

## Description

Deprecated. Gets a structure containing folder information.

## Parameters

### `pfsd` [in, out]

Type: **tagFolderSetData***

A pointer to a [FOLDERSETDATA](https://learn.microsoft.com/windows/desktop/api/shdeprecated/ns-shdeprecated-foldersetdata) structure that receives the folder information.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is called by the derived class.