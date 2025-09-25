# IWiaDataTransfer::idtGetBandedData

## Description

The **IWiaDataTransfer::idtGetBandedData** method transfers a band of data from a hardware device to an application. For efficiency, applications retrieve data from Windows Image Acquisition (WIA) hardware devices in successive bands.

## Parameters

### `pWiaDataTransInfo` [in]

Type: **PWIA_DATA_TRANSFER_INFO**

Pointer to the [WIA_DATA_TRANSFER_INFO](https://learn.microsoft.com/windows/desktop/api/wia_xp/ns-wia_xp-wia_data_transfer_info) structure.

### `pIWiaDataCallback` [in]

Type: **[IWiaDataCallback](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiadatacallback)***

Pointer to the [IWiaDataCallback](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiadatacallback) interface. Periodically, this method will call the [BandedDataCallback](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiadatacallback-bandeddatacallback) method to provide the application with data transfer status notification.

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

The **IWiaDataTransfer::idtGetBandedData** method allocates a section of memory to transfer data without requiring an extra data copy through the Component Object Model/Remote Procedure Call (COM/RPC) marshalling layer. This memory section is shared between the application and the hardware device's item tree.

Optionally, the application can pass in a pointer to a block of memory that **IWiaDataTransfer::idtGetBandedData** will use as its shared section. The application passes this handle by storing the pointer in the **ulSection** member of the [WIA_DATA_TRANSFER_INFO](https://learn.microsoft.com/windows/desktop/api/wia_xp/ns-wia_xp-wia_data_transfer_info) structure prior to calling **IWiaDataTransfer::idtGetBandedData**.

Applications can improve performance by using double buffering. To do this, applications must set the **bDoubleBuffer** member of the [WIA_DATA_TRANSFER_INFO](https://learn.microsoft.com/windows/desktop/api/wia_xp/ns-wia_xp-wia_data_transfer_info) structure to **TRUE**. The **IWiaDataTransfer::idtGetBandedData** method will divide the data buffer in half. When one half of the buffer is full, **IWiaDataTransfer::idtGetBandedData** will send a notification to the application using the [IWiaDataCallback](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiadatacallback) pointer passed in through the *pIWiaDataCallback* parameter. While the application is retrieving the data from the full half of the buffer, the device driver can fill the other half with data.

The format of the data transfer is determined by the values of the item's [WIA_IPA_FORMAT](https://learn.microsoft.com/windows/desktop/wia/-wia-wiaitempropcommonitem) and **WIA_IPA_TYMED** properties. The application sets these properties with calls to the [IWiaPropertyStorage::WriteMultiple](https://learn.microsoft.com/windows/desktop/api/propidl/nf-propidl-ipropertystorage-writemultiple) method.