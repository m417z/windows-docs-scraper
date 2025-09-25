# StgGetIFillLockBytesOnILockBytes function

## Description

[The
**StgGetIFillLockBytesOnILockBytes** function is obsolete and the following information is provided for versions of Windows prior to Windows 2000.]

Creates a new wrapper object on a byte array object provided by the caller.

## Parameters

### `pilb` [in]

Pointer to an existing byte array object.

### `ppflb` [out]

Pointer to
[IFillLockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ifilllockbytes) pointer variable that receives the interface pointer to the new byte array wrapper object.

## Return value

This function supports the standard return values E_UNEXPECTED and E_FAIL, as well as the following:

## Remarks

The
**StgGetIFillLockBytesOnILockBytes** function makes it possible to create an asynchronous storage wrapper object on a custom byte-array object. For example, if you wanted to implement asynchronous storage on a database for which you have already created a byte-array object, you would call this function to create the wrapper object for the byte array. To do so, the function creates a new wrapper object and then initializes it by passing it a pointer to the existing byte-array object.

## See also

[IFillLockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ifilllockbytes)

[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes)