# OleConvertOLESTREAMToIStorage2 function

Converts the specified object from the OLE 1 storage model to an OLE 2 structured storage object without specifying presentation data.

> [!NOTE]
> This is one of several compatibility functions.

## Parameters

### lpolestream [in]

A pointer to a stream that contains the persistent representation of the object in the OLE 1 storage format.

### pstg [out]

A pointer to the [IStorage](https://learn.microsoft.com/windows/win32/api/objidl/nn-objidl-istorage) interface on the OLE 2 structured storage object.

### ptd [in]

A pointer to the [DVTARGETDEVICE](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-dvtargetdevice) structure that specifies the target device for which the OLE 1 object is rendered.

### opt [in]

This value can be 0 or OLESTREAM_CONVERSION_DISABLEOLELINK(0x00000001). If the value is OLESTREAM_CONVERSION_DISABLEOLELINK, linked object will be disabled during conversion.

### pvCallbackContext [in]

The context of the user to be passed to the callback function *pQueryConvertOLELinkCallback*. May be NULL.

### pQueryConvertOLELinkCallback [in]

A pointer to an [OLESTREAMQUERYCONVERTOLELINKCALLBACK](https://learn.microsoft.com/windows/win32/controls/olestreamqueryconvertolelinkcallback) callback function that queries the application if linked object should be converted or not. May be NULL.

## Return value

| Value | Description |
|-------|-------------|
| S_OK | Success. |
| E_INVALIDARG | Invalid argument. |

## Remarks

This function converts an OLE 1 object to an OLE 2 structured storage object. Use this function to update OLE 1 objects to OLE 2 objects when a new version of the object application supports OLE 2.
This function differs from the [OleConvertOLESTREAMToIStorage](https://learn.microsoft.com/windows/win32/api/ole2/nf-ole2-oleconvertolestreamtoistorage) function in that the application can pass in an optional value to disable linked object during conversion or a callback function that queries the application if linked object should be converted or not.

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions. The API is exported from Ole32.dll.

## Requirements

| Requirement | Value |
|-----------------------------------|-------------------------------------------------------------------------------------------------------|
| Minimum supported client| Windows 10 RTM (with Oct 2023 security update or later) |
| Minimum supported server| Windows Server 2008 (with Oct 2023 security update or later) |
| Library | Ole32.lib |
| DLL | Ole32.dll |