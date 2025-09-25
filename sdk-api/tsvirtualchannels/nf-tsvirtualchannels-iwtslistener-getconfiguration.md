# IWTSListener::GetConfiguration

## Description

Retrieves the listener-specific configuration. This configuration is supplied as a **BSTR** property of the property bag, under the name of **WTS_PROPERTY_DEFAULT_CONFIG** (which equals the string "DefaultConfig").

## Parameters

### `ppPropertyBag` [out]

Output parameter that receives the property bag.

## Return value

Returns **S_OK** if successful.

## See also

[IWTSListener](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtslistener)