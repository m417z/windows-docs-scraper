# TF_CreateCategoryMgr function

## Description

The **TF_CreateCategoryMgr** function creates a category manager object without having to initialize COM. Usage must be done carefully because the calling thread must maintain the reference count on an object that is owned by MSCTF.DLL.

## Parameters

### `ppcat` [out]

Pointer to ITFCategoryMgr interface pointer that receives the category manager object.

## Return value

| Value | Meaning |
| --- | --- |
| S_OK | The function was successful. |
| E_FAIL | An unspecified error occurred. |