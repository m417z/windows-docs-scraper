# CreateIFEDictionaryInstance function

## Description

Returns a pointer to an [IFEDictionary](https://learn.microsoft.com/windows/desktop/api/msime/nn-msime-ifedictionary) interface.

## Parameters

### `ppvObj` [out]

Address of the pointer variable that receives the [IFEDictionary](https://learn.microsoft.com/windows/desktop/api/msime/nn-msime-ifedictionary) interface pointer of the object created.

## Return value

**S_OK** if successful, otherwise an OLE-defined error code.

## Remarks

There is no import library available that defines this function. It is necessary to manually obtain a pointer to this function using [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress).