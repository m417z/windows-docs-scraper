# IWiaItem::AnalyzeItem

## Description

The **IWiaItem::AnalyzeItem** method causes the Windows Image Acquisition (WIA) hardware device to acquire and try to detect what data types are present.

## Parameters

### `lFlags` [in]

Type: **LONG**

Currently unused. Should be set to zero.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is used with scanners to detect what type of data is on a page. When an application calls this method, the WIA hardware device driver scans and analyzes the current page. For each data type it detects, it creates an [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) object to represent the region on the page the data occupies.

Image processing and OCR software can use this capability to detect graphics and text on a page. This method adds the regions it creates into the WIA device's [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) tree. The application can select the individual regions and use the standard data transfer methods to acquire data from them.

If necessary, applications can override the regions created by this method.