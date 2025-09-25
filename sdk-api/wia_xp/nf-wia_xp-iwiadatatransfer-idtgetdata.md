# IWiaDataTransfer::idtGetData

## Description

The **IWiaDataTransfer::idtGetData** method retrieves complete files from a Windows Image Acquisition (WIA) device.

## Parameters

### `pMedium` [in, out]

Type: **LPSTGMEDIUM**

Pointer to the [STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1) structure.

### `pIWiaDataCallback` [in]

Type: **[IWiaDataCallback](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiadatacallback)***

Pointer to the [IWiaDataCallback](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiadatacallback) interface.

## Return value

Type: **HRESULT**

This method can return any one of the following values:

| Return Value | Meaning |
| --- | --- |
| E_INVALIDARG | One or more parameters to this method contain invalid data. |
| E_OUTOFMEMORY | This method cannot allocate enough memory to complete its operation. |
| E_UNEXPECTED | An unknown error occurred. |
| S_FALSE | The application canceled the operation. |
| S_OK | The image was successfully acquired. |
| STG_E_MEDIUMFULL | The storage medium the application is using to acquire the image is full. |
| WIA_S_NO_DEVICE_AVAILABLE | There are no WIA hardware devices attached to the user's computer. |

This method will return a value specified in [Error Codes](https://learn.microsoft.com/windows/desktop/wia/-wia-error-codes), or a standard COM error if it fails for any reason other than those specified in the preceding table.

## Remarks

In most respects, this method operates identically to the [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) method. The primary difference is that **IWiaDataTransfer::idtGetData** provides an additional parameter for a pointer to the [IWiaDataCallback](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiadatacallback) interface. Applications use this optional parameter to obtain status notifications during the data transfer. If no status notifications are needed, it should be set to zero.

The format of the data transfer is determined by the values of the item's [WIA_IPA_FORMAT](https://learn.microsoft.com/windows/desktop/wia/-wia-wiaitempropcommonitem) and **WIA_IPA_TYMED** properties. The application sets these properties with calls to the [IWiaPropertyStorage::WriteMultiple](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-writemultiple) method.

Unlike the [IWiaDataTransfer::idtGetBandedData](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiadatatransfer-idtgetbandeddata) method, **IWiaDataTransfer::idtGetData** transfers a complete file from a WIA device to an application rather than just a single band of data. The *pMedium* parameter is a pointer to the [STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1) structure which contains information on the storage medium to be used for the data transfer. Programs use the *pIWiaDataCallback* parameter to pass this method a pointer to the [IWiaDataCallback](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiadatacallback) interface. Periodically, this method will use the interface pointer to invoke the [BandedDataCallback](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiadatacallback-bandeddatacallback) method and provide the application with status information about the data transfer in progress.

Pass **NULL** as the value of the **lpszFileName** member of the *pMedium* structure to allow WIA to determine the file name and location for the new file. Upon return, the **lpszFileName** member of the *pMedium* structure contains the location and name of the new file.

If the value returned by this method is a COM SUCCESS value or the transfer is a multipage file transfer, and the error code returned is WIA_ERROR_PAPER_JAM, WIA_ERROR_PAPER_EMPTY, or WIA_ERROR_PAPER_PROBLEM, WIA does not delete the file.