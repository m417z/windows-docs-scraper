# IGlobalOptions::Set

## Description

Sets the specified global property of the COM runtime.

## Parameters

### `dwProperty` [in]

 The global property of the COM runtime. For a list of properties that can be set with this method, see [IGlobalOptions](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iglobaloptions).

### `dwValue` [in]

The value of the property.

**Important** For the COMGLB_APPID property, this parameter must specify a pointer to the APPID GUID.

## Return value

The return value is S_OK if the property was set successfully.

## See also

[IGlobalOptions](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iglobaloptions)