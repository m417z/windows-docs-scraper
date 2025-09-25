# SHGetMalloc function

## Description

[**SHGetMalloc** is available through Windows Vista and Windows Server 2003, but may be altered or unavailable in subsequent versions of the operating system or product. See the Remarks section for alternate recommendations.]

Retrieves a pointer to the Shell's [IMalloc](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imalloc) interface.

## Parameters

### `ppMalloc`

Type: **LPMALLOC***

The address of a pointer that receives the Shell's [IMalloc](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imalloc) interface pointer.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**SHGetMalloc** was introduced in Windows 95 and Microsoft Windows NT 4.0, but as of Windows 2000 it is no longer necessary. In its place, programs can call the equivalent (and easier to use) [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) and [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree). If you find an older reference document that suggests or even requires the use of **SHGetMalloc**, it is acceptable and encouraged to use **CoTaskMemAlloc** and **CoTaskMemFree** instead.