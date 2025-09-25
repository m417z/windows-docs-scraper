# IGlobalOptions::Query

## Description

Queries the specified global property of the COM runtime.

## Parameters

### `dwProperty` [in]

 The global property of the COM runtime. For a list of properties that can be set with this method, see [IGlobalOptions](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iglobaloptions).

### `pdwValue` [out]

The value of the property.

**Important** For the COMGLB_APPID property, this parameter receives a pointer to the AppID GUID.

## Return value

The return value is S_OK if the property is queried successfully.

## See also

[IGlobalOptions](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iglobaloptions)