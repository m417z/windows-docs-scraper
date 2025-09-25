# IFixedPage::GetPagePart

## Description

The **GetPagePart** method gets the images, thumbnails, fonts, and so on in a page by using the URI.

## Parameters

### `uri` [in]

The URI for a part. For example, the filter might parse the page markup and find a referenced font. The filter can use the font URI in a call to **GetPagePart**. The filter could then retrieve the font object that is associated with the page.

### `ppUnk` [out]

The object that is to be queried.

## Return value

**GetPagePart** returns an **HRESULT**.

## Remarks

A filter must use QueryInterface on the return value to see what part types reside in the page.