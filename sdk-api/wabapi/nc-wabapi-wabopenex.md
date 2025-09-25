# WABOpenEx callback function

## Description

[*WABOpenEx* is no longer available for use as of Windows Vista.]

Provides access to the Windows Address Book (WAB) through a number of object interfaces. The root interface is [IAddrBook](https://learn.microsoft.com/windows/desktop/api/wabiab/nn-wabiab-iaddrbook), which is a subset of the MAPI implementation of [IAddrBook](https://learn.microsoft.com/windows/desktop/api/wabiab/nn-wabiab-iaddrbook).

## Parameters

### `lppAdrBook`

Type: **LPADRBOOK***

Address of a pointer to the [IAddrBook](https://learn.microsoft.com/windows/desktop/api/wabiab/nn-wabiab-iaddrbook) interface returned by the function.

### `lppWABObject`

Type: **LPWABOBJECT***

Address of a pointer to the [IWABObject](https://learn.microsoft.com/windows/desktop/api/wabapi/nn-wabapi-iwabobject) interface returned by the function.

### `lpWP`

### `Reserved`

### `fnAllocateBuffer`

### `fnAllocateMore`

### `fnFreeBuffer`

#### - Reserved2

Type: **DWORD**

Reserved. Must be set to 0.

#### - lpWABParam

Type: **LPWAB_PARAM**

Pointer to a [WAB_PARAM](https://learn.microsoft.com/windows/desktop/api/wabapi/ns-wabapi-wab_param) structure. Supported by Internet Explorer 4.0 or later.

#### - lpfnAllocateBuffer

Type: **ALLOCATEBUFFER***

Pointer to a function that specifies the [MAPIAllocateBuffer](https://learn.microsoft.com/previous-versions/office/developer/office-2007/cc815816(v=office.12))-style allocation function. Set to **NULL** to use WAB internal routines.

#### - lpfnAllocateMore

Type: **ALLOCATEMORE***

Pointer to a function that specifies the [MAPIAllocateMore](https://learn.microsoft.com/previous-versions/office/developer/office-2007/cc765787(v=office.12))-style allocation function. Set to **NULL** to use WAB internal routines.

#### - lpfnFreeBuffer

Type: **FREEBUFFER***

Pointer to a function that specifies the [MAPIFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nf-mapi-mapifreebuffer)-style memory freeing function. Set to **NULL** to use WAB internal routines.

## Return value

Type: **HRESULT**

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function calls the [WABOpen](https://learn.microsoft.com/previous-versions/windows/desktop/api/wabapi/nc-wabapi-wabopen) function, and the extra parameters *lpfnAllocateBuffer*, *lpfnAllocateMore*, and *lpfnFreeBuffer* are ignored.

*WABOpenEx* is an extended version of [WABOpen](https://learn.microsoft.com/previous-versions/windows/desktop/api/wabapi/nc-wabapi-wabopen) that enables developers to specify the memory allocation functions used by WAB to return buffers to the client. If you pass one allocation routine, you must pass all three routines: [MAPIAllocateBuffer](https://learn.microsoft.com/previous-versions/office/developer/office-2007/cc815816(v=office.12)), [MAPIAllocateMore](https://learn.microsoft.com/previous-versions/office/developer/office-2007/cc765787(v=office.12)), and [MAPIFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nf-mapi-mapifreebuffer).

If you do not need the extra memory allocation functionality of *WABOpenEx*, use [WABOpen](https://learn.microsoft.com/previous-versions/windows/desktop/api/wabapi/nc-wabapi-wabopen) instead.

**Note** When you specify memory allocation routines with *WABOpenEx*, these routines globally replace the WAB internal routines for this process. Other threads may still call [WABOpen](https://learn.microsoft.com/previous-versions/windows/desktop/api/wabapi/nc-wabapi-wabopen), but the memory will be allocated with those routines previously passed to *WABOpenEx*.