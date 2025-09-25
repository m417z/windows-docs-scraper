# CreateIFECommonInstance function

## Description

Returns a pointer to an [IFECommon](https://learn.microsoft.com/windows/desktop/api/msime/nn-msime-ifecommon) interface.

## Parameters

### `ppvObj` [out]

Address of the pointer variable that receives the [IFECommon](https://learn.microsoft.com/windows/desktop/api/msime/nn-msime-ifecommon) interface pointer of the object created.

## Return value

**S_OK** if successful, otherwise an OLE-defined error code.

## Remarks

There is no import library available that defines this function. It is necessary to manually obtain a pointer to this function using [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress).