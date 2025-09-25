# WIA_DATA_CALLBACK_HEADER structure

## Description

The **WIA_DATA_CALLBACK_HEADER** is transmitted to an application during a series of calls by the Windows Image Acquisition (WIA) run-time system to the [IWiaDataCallback::BandedDataCallback](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiadatacallback-bandeddatacallback) method.

## Members

### `lSize`

Type: **LONG**

Must contain the size of this structure in bytes. Should be initialized to **sizeof(WIA_DATA_CALLBACK_HEADER)**.

### `guidFormatID`

Type: **GUID**

Indicates the image clipboard format. For a list of clipboard formats, see [SetClipboardData](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setclipboarddata) Function. This parameter is queried during a callback to the [IWiaDataCallback::BandedDataCallback](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiadatacallback-bandeddatacallback) method with the *lMessage* parameter set to IT_MSG_DATA_HEADER.

### `lBufferSize`

Type: **LONG**

Specifies the size in bytes of the buffer needed for a complete data transfer. This value can be zero, which indicates that the total image size is unknown. (when using compressed data formats, for example). In this case, the application should dynamically increase the size of its buffer. For more information, see [Common WIA Item Property Constants](https://learn.microsoft.com/windows/desktop/wia/-wia-wiaitempropcommonitem) in WIA_IPA_ITEM_SIZE.

### `lPageCount`

Type: **LONG**

Specifies the page count. Indicates the number of callbacks to the [IWiaDataCallback::BandedDataCallback](https://learn.microsoft.com/windows/desktop/api/wia_xp/nf-wia_xp-iwiadatacallback-bandeddatacallback) method with the *lMessage* parameter set to IT_MSG_NEW_PAGE.